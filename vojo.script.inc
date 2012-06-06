<?php
/**
 * @file
 *     voipscripts for vojo hosted service.
 */

/**
 * VoIP script Callback: Welcome script
 * @see voipextension_basic_menu
 */
function _vojo_welcome_script() {
  voipvoice_set_current_voice('vojo-english');  // TODO: allow voice user to switch language
  
  $script = new VoipScript('vojo_welcome');

  $script->addGotoIf('forward_to_group',"^%dest_number != ".variable_get('voipcall_cid_number',''));

  $prompt = v('Welcome to Vojo. Please enter a group extension and then press pound.');
  
  $script->addLabel('request_extension');
  $script->addGetInput($prompt, 5, '#', 3);
  $script->addGotoIf('no_input_received', "^%input_digits == ''");
  $script->addGotoIf('go_back', "^%input_digits == '*'");
  $script->addGosub('voipextension_play_extension', array('eid' => "%input_digits")); 
  $script->addGoto('request_extension');

  $script->addLabel('no_input_received');
  $script->addSay(variable_get('voipextension_noinput_msg', v('No input received. Please try again.')));
  $script->addGoto('request_extension');

  $script->addLabel('forward_to_group');
  $script->addGosub('vojo_redirect_to_group', array('number'=>'%dest_number'));
  $script->addGoto('request_extension');

  $script->addLabel('go_back');
  $script->addReturn();

  return $script;
}

/**
 * Find the node associated with a phone number, and return it's script (or an error script if none matches)
 */
function _vojo_redirect_to_group_script($number) {
  $nid = _vojo_voipnumber_api_nid_from_number($number);
  $script = new VoipScript('vojo_redirect_to_group');
  if($nid==null) {
    // no matching node for number found, return a brief error message
    watchdog('vojo', 'No node has direct phone number %number',array('%number'=>$number));
    $script->addSay(v('Sorry, there is no group at that number.'));
  } else {
    // found a node, return its script
    $eid = _vojo_voipextension_api_extension_for_node($nid);
    if($eid===false){
      watchdog('vojo', 'Direct phone number %number is node %nid, but has no extension', array('%number'=>$number, '%nid'=>$nid));
      $script->addSay(v('Sorry, there is no extension for that number.'));
    } else {
      watchdog('vojo', 'Forwarding directly to group %nid / extension %eid (user called %number)', array('%nid'=>$nid, '%eid'=>$eid, '%number'=>$number));
      $script->addGosub('voipextension_play_extension', array('eid' => $eid)); 
    }
  }
  $script->addReturn();
  return $script;
}

/**
 * VoIP Script Callback: Organic group options.
 *
 * $param['nid'] = Node ID.
 */
function _vojo_group_script($node) {
  $script = new VoipScript('vojo_group');

  $script->addLabel('begin');

  if ($name = voipnode_get_title($node)) {
    $script->addSay($name);
  } else {
    $script->addSay($node->title . '.');
  }

  $script->addLabel('intro');
  $prompt = v('To hear other stories, press 1.  To record your own story press 2. To learn more press 3. To return and select another group press the pound key.');
  if ($greeting = voipnode_get_greeting($node)) {
    $prompt = $greeting;
  }
  $script->addGetInput($prompt, 1, '', 6);
  $script->addGotoIf('hear_stories', "^%input_digits == '1'");
  $script->addGotoIf('record_story', "^%input_digits == '2'");
  $script->addGotoIf('learn_more', "^%input_digits == '3'");
  $script->addGotoIf('return', "^%input_digits == '#'");
  $script->addSay(v('Input not recognized'));

  $script->addGoto('intro');
  
  $script->addLabel('hear_stories');
  $params = array('view_name' => 'vojo_group_browse_stories', 'display_id' => 'vojo_group_stories_voip', 'args' => json_encode(array($node->nid)));
  $script->addGosub('voipviews_read_view', $params);
  $script->addGoto('begin');

  $script->addLabel('record_story');
  $script->addGosub('vojo_record_blog', array('nid' => $node->nid));
  $script->addGoto('begin');

  $script->addLabel('learn_more');
  if ($descrip = voipnode_get_description($node)) {
    $script->addSay($descrip);  
  } else {
    $script->addSay($node->body . '.');
  }
  $script->addGoto('begin');

  $script->addLabel('return');
  return $script;
}

/**
 * VoIP Script Callback: Record blog node in group.
 *
 * $param['nid'] = Node ID.
 */
function _vojo_record_blog_script($node) {
  $script = new VoipScript('vojo_record_blog');
 
  $script->addGosub('vojo_login', array('number' => '%caller_number'));
  $script->addSet('og_group', $node->title);

  $script->addLabel('start');
  $script->addRecord(
    v('Start recording your message for %og_group after the tone. Press the pound key to stop recording.'), 
    5, '#', 3600, 'mp3', TRUE
  );
  $script->addGotoIf('no recording detected','^%recording_duration == 0');
  $script->addSay(v('You said '));
  $script->addSay('%recording_public_url');
  
  $script->addLabel('accept menu');
  $script->addGetInput(
    v('To accept this recording, press 1. To record it once again, press 2. To return, press the pound key.'),
    10, '', 1
  );
  $script->addGotoIf('accept recording', "^%input_digits == '1'");
  $script->addGotoIf('start', "^%input_digits == '2'");
  $script->addGotoIf('end record', "^%input_digits == '#'");
  // fall through to accept recording if no input (could be hang-up)
  $script->addLabel('accept recording');
  $script->addSay(v('Please wait while we save your story'));
  $script->addGosub('vojo_save_blog', array('nid' => $node->nid, 'fid' => '%recording_fid'));
  $script->addGoto('end record');

  $script->addLabel('no recording detected');
  $script->addSay(v("No recording detected. Please try again."));
  $script->addGoto('start');

  $script->addLabel('end record');

  return $script;
}

/**
 * VoIP Script Callback: Save announcment file to node.
 *
 * $param['nid'] = Group node ID.
 * $param['fid'] = File ID (%recording_fid).
 * @see _vozmob_callin_record_callback()
 */
function _vojo_save_blog_script($nid, $fid) {
  global $user;
  $script = new VoipScript('vojo_save_blog');

  $node = new StdClass();
  $node->type = 'blog';
  $node->status = 1;                    // TODO: this should check the og group settings
  $node->title = '';                    // will be autogenerated by auto_nodetitle later
  $node->uid = $user->uid;
  $node->og_groups = array($nid => $nid);
  $result = db_query('SELECT * FROM {files} WHERE fid = %d', $fid);
  if ($file = db_fetch_object($result)) {
    $file->list = variable_get('upload_list_default', 1);
    $node->files[$file->fid] = $file;
    // Force upload module to recognize the file attachment.
    $node->old_vid = 1;
  }
  node_save($node);
  $script->addSay(v('Story saved.'));
  return $script;
}

/**
 * Log user in based on sms_user number.  Log in as og fake anonymous is no user found.
 */
function _vojo_login_script($number) {
  global $user;
  $script = new VoipScript('vojo_login');
  $uid = sms_user_get_uid($number);
  if ($uid) {
    $user = user_load($uid);
  }
  else {
    $user = user_load(vojo_og_anon_get_user_id()); // DO NOT use user_load(0); - anonymous cannot post to og groups :-(
  }
  watchdog('vojo', 'Voip call associated with user %name.', array('%name' => $user->name));
  $script->addSet('user_uid', $user->uid);
  $script->addSet('user_name', $user->name);

  return $script;
}
