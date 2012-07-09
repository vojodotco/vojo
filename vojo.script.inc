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
 * $param['nid'] = Group node ID.
 */
function _vojo_record_blog_script($node) {
  $script = new VoipScript('vojo_record_blog');
 
  $script->addGosub('vojo_login', array('number' => '%caller_number'));
  $script->addSet('og_group', $node->title);

  $script->addGotoIf('handle_non_user','^%user_uid == '.vojo_og_anon_get_user_id());
  $script->addGotoIf('start_recording','^%user_uid != '.vojo_og_anon_get_user_id());
  
  $script->addLabel('handle_non_user');
  $script->addGosub('vojo_pick_create_or_anon', array('number' => '%caller_number', 'nid' => $node->nid));
  $script->addGoto('start_recording');

  $script->addLabel('start_recording');
  $script->addRecord(
    v('Start recording your message for %og_group after the tone. Press the pound key to stop recording.'), 
    5, '#', 3600, 'mp3', TRUE
  );
  $script->addGotoIf('no_recording','^%recording_duration == 0');
  $script->addSay(v('You said '));
  $script->addSay('%recording_public_url');
  
  $script->addLabel('accept menu');
  $script->addGetInput(
    v('To accept this recording, press 1. To record it once again, press 2. To return, press the pound key.'),
    10, '', 1
  );
  $script->addGotoIf('accept recording', "^%input_digits == '1'");
  $script->addGotoIf('start_recording', "^%input_digits == '2'");
  $script->addGotoIf('end_record', "^%input_digits == '#'");
  // fall through to accept recording if no input (could be hang-up)
  $script->addLabel('accept recording');
  $script->addSay(v('Please wait while we save your story'));
  $script->addGosub('vojo_save_blog', array('nid' => $node->nid, 'fid' => '%recording_fid'));
  $script->addGoto('end_record');

  $script->addLabel('no_recording');
  $script->addSay(v("No recording detected. Please try again."));
  $script->addGoto('start_recording');

  $script->addLabel('end_record');

  return $script;
}

/**
 * A script giving the user an option to post as anonymous or create a new user.
 */
function _vojo_pick_create_or_anon_script($number, $groupNid){
  global $user;
  $script = new VoipScript('vojo_pick_create_or_anon');
  $script->addLabel('pick_option');
  $script->addGetInput('Press 1 to record an anonymous story, or press 2 to create a new account on vojo dot co', 1, '', 5);
  $script->addGotoIf('as_anon', "^%input_digits == '1'");
  $script->addGotoIf('create_user', "^%input_digits == '2'");
  $script->addSay(v('Input not recognized'));
  $script->addGoto('pick_option');

  $script->addLabel('as_anon');
  $script->addSay('Your story will be posted anonymously');
  $script->addGoto('end');
  
  $script->addLabel('create_user');
  $script->addGoSub('vojo_create_user', array('number' => '%caller_number','nid' => $groupNid));
  $script->addGoto('end');
  
  $script->addLabel('end');
  return $script;
}

/**
 * Create a new user and send them an sms.  This does not check if the user phone exists already!
 */
function _vojo_create_user_script($number, $groupNid){
  global $user;
  // create the user
  $newUser = FALSE;
  $password = user_password(8);
  while (!$newUser) {
    $newUser = user_save(NULL, array(
      'name' => variable_get('sms_registration_username', 'Drupal-') . mt_rand(1, db_result(db_query('SELECT MAX(uid) FROM {users}')) * 10),
      'pass' => $password,
      'roles' => ($role = variable_get('sms_registration_role', NULL)) ? array($role => 1) : NULL,
      'status' => 1,
      'language' => $node->language,
      'sms_user' => array('number' => sms_formatter($number), 'status' => SMS_USER_PENDING),
      'access' => time(),
    ));
  }
  $user = $newUser;
  // add them to the group
  og_save_subscription($groupNid, $user->uid, array('is_active' => 1));
  // send them an sms
  $result = _vojo_send_sms($number, t('Welcome! Your username is @name and password is @pass.  You can login to @server_url with this info.',
    array('@name'=>$user->name, '@pass'=>$password, '@server_url'=>variable_get('site_name', 'vojo.co')) ) ); 
  watchdog('vojo', 'Created new user %name / %number - result = %res.', array('%name'=> $user->name,'%number'=>$number, '%res'=>$result));
  // provide audio feedback
  $script = new VoipScript('vojo_create_user');
  $script->addSet('user_uid', $user->uid);
  $script->addSet('user_name', $user->name);  
  $script->addSay(v('We made a new user account for you. We have sent you an sms with your user name and password'));
  return $script;
}

/**
 * Internal helper to send an SMS via VoipDrupal
 * Important to use this, and NOT sms_send because it isn't configured to work with a Tropo Application.
 * TODO: figure out right way around hack so it doesn't send as 
 */
function _vojo_send_sms($number, $msg){
  global $user;
  $tempUserId = $user->uid;
  $user = user_load(1);
  $call = new VoipCall();
  $call->setCurrentChannel('text');
  $call->setCurrentNetwork('sms');
  $call->setDestNumber($number);
  $call->setCallerNumber(variable_get('voipcall_cid_number', NULL));
  voip_text($msg, $call);
  $user = user_load($tempUserId);}

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
