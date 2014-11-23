<?php
/**
 * @file
 *     voipscripts for vojo hosted service.
 *
 * Since scripts are compiled and then run, the v function doesn't respect later calls to 
 * voipvoice_set_current_voice that are trying to change the voice mid-call.  Call v() 
 * like this:
 *   $script->addSay("^v('Welcome to Vojo',null,null,%vojo_voice)");  
 */

/**
 * VoIP script Callback: Welcome script
 * @see voipextension_basic_menu
 */
function _vojo_welcome_script() {
  
  $script = new VoipScript('vojo_welcome');
  $script->addSet('vojo_language', '');
  $script->addSet('vojo_voice', vojo_voice_id_for_language());

  // TODO: if it is an existing user, change the language based on their default language setting

  // forward directly to a group if they called a direct phone number
  $script->addGotoIf('forward_to_group',"^%dest_number != ".variable_get('voipcall_cid_number',''));
  
  // let the user pick a language first
  $script->addLabel('intro');
  $script->addSay( "^v('Welcome to Vojo',null,null,%vojo_voice)" );
  $script->addGosub('vojo_pick_language');
  
  // prompt to pick a group extension
  $script->addLabel('request_extension');
  $script->addGetInput("^v('Please enter a group extension and then press pound.',null,null,%vojo_voice)", 5, '#', 3);
  $script->addGotoIf('no_input_received', "^%input_digits == ''");
  $script->addGotoIf('go_back', "^%input_digits == '*'");
  $script->addGosub('vojo_play_extension', array('eid' => "%input_digits")); 
  $script->addGoto('request_extension');

  //didn't get a selection
  $script->addLabel('no_input_received');
  $script->addSay(variable_get('voipextension_noinput_msg', "^v('No input received. Please try again.',null,null,%vojo_voice)"));
  $script->addGoto('request_extension');

  // send to appropriate group
  $script->addLabel('forward_to_group');
  $script->addGosub('vojo_redirect_to_group', array('number'=>'%dest_number'));
  $script->addGoto('request_extension');

  // return to previous menu
  $script->addLabel('go_back');
  $script->addReturn();

  return $script;
}

/**
 * Re-usable script to pick a language.  We'll need to manually edit this script each 
 * time we add more languages.  Route all language selection through the 
 * vojo_voice_id_for_language($language) method in vojo.module.  This calls 
 * voipvoice_set_current_voice instead of $script->setVoice to make it a cross-script
 * setting (ie. live for the entire duration of the call).
 */
function _vojo_pick_language_script(){

  $script = new VoipScript('vojo_pick_language');

  // pick language menu
  $script->addLabel('menu');
  $script->addGetInput("^v('For english, press one. Para español, marca dos. Para português, pressione três. To go back press pound.',null,null,%vojo_voice)", 1, '', 6);
  $script->addGotoIf('picked_en', "^%input_digits == '1'");
  $script->addGotoIf('picked_es', "^%input_digits == '2'");
  $script->addGotoIf('picked_pt', "^%input_digits == '3'");
  $script->addGotoIf('return', "^%input_digits == '#'");
  $script->addSay("^v('Input not recognized',null,null,%vojo_voice)");
  $script->addGoto('menu');

  // user picked english
  $script->addLabel('picked_en');
  $script->addGosub('vojo_change_language', array('language'=>'en') );
  $script->addGoto('return');

  // user picked spanish
  $script->addLabel('picked_es');
  $script->addGosub('vojo_change_language', array('language'=>'es') );
  $script->addGoto('return');
  
  // user picked portuguese
  $script->addLabel('picked_pt');
  $script->addGosub('vojo_change_language', array('language'=>'pt') );
  $script->addGoto('return');

  // return
  $script->addLabel('return');
  $script->addReturn();

  return $script;
  
}

/**
 * Actually change the language to whatever the userpicked
 */
function _vojo_change_language_script($language){
  // change the language
  voipvoice_set_current_voice( vojo_voice_id_for_language($language) );
  // give user feedback
  $script = new VoipScript('vojo_change_language');
  $script->addSet('vojo_voice', vojo_voice_id_for_language($language) );
  $script->addSet('vojo_language', $language);
  $script->addSay("^v('Welcome to Vojo',null,null,%vojo_voice)");  // say it again in the local language  
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
    $script->addSay("^v('Sorry, there is no group at that number.',null,null,%vojo_voice)");
  } else {
    // found a node, return its script
    $eid = _vojo_voipextension_api_extension_for_node($nid);
    if($eid===false){
      watchdog('vojo', 'Direct phone number %number is node %nid, but has no extension', array('%number'=>$number, '%nid'=>$nid));
      $script->addSay("^v('Sorry, there is no extension for that number.',null,null,%vojo_voice)");
    } else {
      watchdog('vojo', 'Forwarding directly to group %nid / extension %eid (user called %number)', array('%nid'=>$nid, '%eid'=>$eid, '%number'=>$number));
      $script->addGosub('vojo_play_extension', array('eid' => $eid)); 
    }
  }
  $script->addReturn();
  return $script;
}



/**
 * Script to use when a group extension is selected
 *
 * $param['nid'] = Node ID.
 */
function _vojo_group_script($node) {
  $script = new VoipScript('vojo_group');

  $script->addLabel('begin');
  
  // Change to group's language if no language is already set
  $script->addGotoIf('group_name', "^%vojo_language != ''");
  if (!empty($node->language)) {
    $script->addGosub('vojo_change_language', array('language'=>$node->language));
  }
  
  $script->addLabel('group_name');
  if ($name = voipnode_get_title($node)) {
    $script->addSay($name);
  } else {
    $script->addSay($node->title . '.');
  }

  // menu of group options
  $script->addLabel('group_menu');
  if ($greeting = voipnode_get_greeting($node)) {
    $script->addGetInput($greeting, 1, '', 6);
  } else {
    $script->addGetInput("^v('To hear other stories, press 1.  To record your own story press 2. To learn more press 3. To return and select another group press the pound key.',null,null,%vojo_voice)", 1, '', 6);
  }
  $script->addGotoIf('hear_stories', "^%input_digits == '1'");
  $script->addGotoIf('record_story', "^%input_digits == '2'");
  $script->addGotoIf('learn_more', "^%input_digits == '3'");
  $script->addGotoIf('return', "^%input_digits == '#'");
  $script->addSay("^v('Input not recognized',null,null,%vojo_voice)");
  $script->addGoto('group_menu');
  
  $script->addLabel('hear_stories');
  $script->addGosub('vojo_hear_group_stories', array('nid'=> $node->nid));
  $script->addGoto('begin');

  // user wants to record a story
  $script->addLabel('record_story');
  $script->addGosub('vojo_record_blog', array('nid' => $node->nid));
  $script->addGoto('begin');

  // user wants to hear more about the group
  $script->addLabel('learn_more');
  if ($descrip = voipnode_get_description($node)) {
    $script->addSay($descrip);  
  } else {
    $script->addSay($node->body . '.');
  }
  $script->addGoto('begin');

  // return
  $script->addLabel('return');
  return $script;
}


/**
 * Script to hear stories for a specific group
 *
 * $param['nid'] = Node ID.
 */
function _vojo_hear_group_stories_script($nid) {
  $script = new VoipScript('vojo_hear_group_stories');
  $result = db_query('SELECT * FROM {files} f INNER JOIN {upload} r ON f.fid = r.fid WHERE r.nid in (select nid from {og_ancestry} where group_nid=%d and status=1) ORDER BY r.weight,f.fid desc;', $nid);
  while ($file = db_fetch_array($result)) {
     $extension = substr($file['filepath'], -3);
     if( in_array($extension, array('wav','mp3')) ) {
       $script->addSay("^v('This story was created by ',null,null,%vojo_voice)");
       $uid = $file['uid'];
       if ($uid==0) {
	   $uid = vojo_og_anon_get_user_id(); 
       }
       $user = user_load($uid);
       $script->addSay($user->name);
       $script->addSay(file_create_url($file['filepath']));
       $script->addLabel('voice_menu_'.$file['fid']);
       $script->addGetInput("^v('Press 1 to hear another story, or # to go back to the main menu',null,null,%vojo_voice)", 1, '', 5);
       $script->addGotoIf('return', "^%input_digits == '#'");
       $script->addGotoIf('voice_menu_'.$file['fid'], "^%input_digits != '1'");      
     }
  }
  $script->addLabel('return');
  $script->addReturn();
  return $script;
}


/**
 * Script to use when a group extension is selected
 *
 * $param['nid'] = Node ID.
 */
function _vojo_simple_group_script($node) {
  $script = new VoipScript('vojo_simple_group');
  $script->addLabel('begin');
  
  // Change to group's language if no language is already set
  //$script->addSet('vojo_language', '');
  //$script->addSet('vojo_voice', vojo_voice_id_for_language());
  $script->addGotoIf('group_name', "^%vojo_language != ''");
  if (!empty($node->language)) {
    $script->addGosub('vojo_change_language', array('language'=>$node->language));
  }

  $script->addLabel('group_name');
  if ($name = voipnode_get_title($node)) {
    $script->addSay($name);
  } else {
    $script->addSay($node->title . '.');
  }

  // menu of group options
  $script->addLabel('group_menu');
  if ($greeting = voipnode_get_greeting($node)) {
    $script->addGetInput($greeting, 1, '', 6);
  } else {
    $script->addGetInput("^v('To record a new story, press 1, or just wait for the tone.  To listen to stories, press 2.  To hear more about the group, press 3.  Thanks!',null,null,%vojo_voice)", 1, '', 1);
  }
  $script->addGotoIf('record_story', "^%input_digits == '1'");
  $script->addGotoIf('hear_stories', "^%input_digits == '2'");
  $script->addGotoIf('learn_more', "^%input_digits == '3'");
  $script->addGotoIf('return', "^%input_digits == '#'");
  $script->addGoto('record_story');
  
  // user wants to hear other stories - this delegates to a voipview
  $script->addLabel('hear_stories');
  $script->addGosub('vojo_hear_group_stories', array('nid'=> $node->nid));
  $script->addGoto('begin');

  // user wants to record a story
  $script->addLabel('record_story');
  $script->addGosub('vojo_record_blog', array('nid' => $node->nid, 'simple' => true));
  $script->addGoto('begin');

  // user wants to hear more about the group
  $script->addLabel('learn_more');
  if ($descrip = voipnode_get_description($node)) {
    $script->addSay($descrip);  
  } else {
    $script->addSay($node->body . '.');
  }
  $script->addGoto('begin');

  // return
  $script->addLabel('return');
  return $script;
}

/**
 * VoIP Script Callback: Record blog node in group.
 *
 * $param['nid'] = Group node ID.
 */
function _vojo_record_blog_script($node, $simple = false) {
  global $user;
  
  $script = new VoipScript('vojo_record_blog');
 
  // login the user based on their phone number
  $script->addGosub('vojo_login', array('number' => '%caller_number'));
  $script->addSet('og_group', $node->title);
  $script->addSet('gid', $node->nid);
  $script->addGotoIf('handle_non_user','^%user_uid == '.vojo_og_anon_get_user_id());
  $script->addGotoIf('start_recording','^%user_uid != '.vojo_og_anon_get_user_id());
  
  // if new user, let them choose to create an account or post as anon
  $script->addLabel('handle_non_user');
  $script->addGotoIf('record_create_user', '^' . ($simple ? 'true' : 'false'));
  $script->addGosub('vojo_pick_create_or_anon', array('number' => '%caller_number', 'nid' => $node->nid));
  $script->addGoto('start_recording');
  $script->addLabel('record_create_user');
  $script->addLabel('creating user');
  $script->addGosub('vojo_create_user', array('number' => '%caller_number','nid' => $node->nid, 'simple'=>$simple));
  $script->addGoto('start_recording');

  // record a message
  // setting hangup_callback to make sure story is saved even if user hangs
  // up without pressing pound (#) see user story #1683
  $script->addLabel('start_recording');
  // auto_save_blog flag is checked on hangup, if set the recorded user story
  // wii be saved for the corresponding group. This is meant for users that call
  // and record a voice message but quickly hang up before reaching the "save this recording" menu
  $script->addSet('auto_save_blog', True);
  $script->addSet('voipscript_hangup_callback', '_vojo_voipscript_hangup_callback');
  $prompt = $simple ? '' : 'Start recording your message after the tone. Press the pound key to stop recording.';
  $script->addRecord(
    "^v('$prompt',null,null,%vojo_voice)", 
    5, '#', 3600, 'mp3', TRUE
  );
  
  // review the recording (and save / re-record)
  $script->addLabel('accept_menu');
  $script->addSet('auto_save_blog', False);
  $script->addGetInput(
    "^v('To save this recording, press 1. To record it once again, press 2. To listen to wat you said, press 3. To return, press the pound key.',null,null,%vojo_voice)",
    1, '', 10
  );
  $script->addGotoIf('accept recording', "^%input_digits == '1'");
  $script->addGotoIf('start_recording', "^%input_digits == '2'");
  $script->addGotoIf('review_recording', "^%input_digits == '3'");
  $script->addGotoIf('end_record', "^%input_digits == '#'");
  // fall through to accept recording if no input (could be hang-up)
  $script->addLabel('accept recording');
  $script->addGosub('vojo_save_blog', array('nid' => $node->nid, 'fid' => '%recording_fid', 'uid' => '%user_uid'));
  $script->addGoto('end_record');

  // playback for user
  $script->addLabel('review_recording');
  $script->addSay("^v('You said ',null,null,%vojo_voice)");
  $script->addSay('%recording_public_url');
  $script->addGoto('accept_menu');

  // deal with no recording
  $script->addLabel('no_recording');
  $script->addSay("^v('No recording detected. Please try again.',null,null,%vojo_voice)");
  $script->addGoto('start_recording');

  // return
  $script->addLabel('end_record');

  return $script;
}

/**
 * A script giving the user an option to post as anonymous or create a new user.
 */
function _vojo_pick_create_or_anon_script($number, $groupNid){

  $script = new VoipScript('vojo_pick_create_or_anon');
  
  $script->addLabel('pick_option');
  $script->addGetInput("^v('Press 1 to record an anonymous story, or press 2 to create a new account on vojo dot co',null,null,%vojo_voice)", 1, '', 5);
  $script->addGotoIf('as_anon', "^%input_digits == '1'");
  $script->addGotoIf('create_user', "^%input_digits == '2'");
  $script->addSay("^v('Input not recognized',null,null,%vojo_voice)");
  $script->addGoto('pick_option');

  $script->addLabel('as_anon');
  $script->addSay("^v('Your story will be posted anonymously',null,null,%vojo_voice)");
  $script->addGoto('end');
  
  $script->addLabel('create_user');
  $script->addGosub('vojo_create_user', array('number' => '%caller_number','nid' => $groupNid));
  $script->addGoto('end');
  
  $script->addLabel('end');
  return $script;
}

/**
 * Create a new user and send them an sms.  
 * TODO: This does not check if the user phone exists already!
 */
function _vojo_create_user_script($number, $groupNid, $simple = false){
  global $user;
  // create the user
  $newUser = FALSE;
  $password = strtolower(user_password(6));
  $group = node_load($groupNid); 
  while (!$newUser) {
    $newUser = user_save(NULL, array(
      'name' => variable_get('sms_registration_username', 'Drupal-') . mt_rand(1, db_result(db_query('SELECT MAX(uid) FROM {users}')) * 10),
      'pass' => $password,
      'roles' => ($role = variable_get('sms_registration_role', NULL)) ? array($role => 1) : NULL,
      'status' => 1,
      'language' => $group->language,
      'sms_user' => array('number' => sms_formatter($number), 'status' => SMS_USER_PENDING),
      'access' => time(),
    ));
  }
  $user = $newUser;
  // add them to the group
  og_save_subscription($groupNid, $user->uid, array('is_active' => 1));
  watchdog('vojo', 'Created new user via phone %name / %number', array('%name'=> $user->name,'%number'=>$number));
  // provide audio feedback
  $script = new VoipScript('vojo_create_user');
  $script->addSet('new_user', '1');
  $script->addSet('password', $password);
  $script->addSet('user_uid', $user->uid);
  $script->addSet('user_name', $user->name);
  if (!$simple) {
    $script->addSay("^v('We made a new user account for you. We have sent you an sms with your user name and password',null,null,%vojo_voice)");
  }

  $script->addSet('voipscript_hangup_callback', '_vojo_voipscript_hangup_callback');
  _vojo_notify_new_user($user->uid, $number, $password);
  return $script;
}

/**
 * Internal helper to send an SMS via VoipDrupal
 * Important to use this, and NOT sms_send because it isn't configured to work with a Tropo Application.
 * TODO: figure out right way around hack so it doesn't send as the main vojo phone line
 */
function _vojo_send_sms($number, $msg){
  global $user;
  $tempUserId = $user->uid;
  $user = user_load(1);
  $call = new VoipCall();
  $call->setCallChannel('text');
  $call->setCallNetwork('sms');
  $call->setDestNumber($number);
  // The following two lines don't currently work
  $call->setCallerNumber(variable_get('voipcall_cid_number', NULL));
  $call->setCallerName(sms_registration_get_address());
  // Create a dummy script to prevent triggering inbound text script
  $dummyscript = new VoipScript('dummyscript');
  $call->setScript($dummyscript);
  voip_text($msg, $call);
  $user = user_load($tempUserId);
}

/**
 * VoIP Script Callback: Save announcment file to node.
 *
 * $param['nid'] = Group node ID.
 * $param['fid'] = File ID (%recording_fid).
 * @see _vozmob_callin_record_callback()
 */
function _vojo_save_blog_script($nid, $fid, $uid) {
  vojo_save_blog($nid, $fid, $uid);
  $script = new VoipScript('vojo_save_blog');
  $script->addSay("^v('Story saved.',null,null,%vojo_voice)");
  // blog_post_saved flag is used on hangup to indicate the user
  // has manually saved a new recording. in those cases sms with published story
  // is sent to the corrsponding user via sms
  $script->addSet('blog_post_saved', True);
  return $script;
}

/**
 * Log user in based on sms_user number.  Log in as og fake anonymous is no user found.
 */
function _vojo_login_script($number) {
  global $user;
  $script = new VoipScript('vojo_login');
  $uid = sms_user_get_uid($number);
  if ($uid==0) {
    $uid = vojo_og_anon_get_user_id(); // DO NOT use user_load(0); - anonymous cannot post to og groups :-(
  }
  $user = user_load($uid);
  watchdog('vojo', 'Voip login user %uid ( %name ).', array('%uid'=>$uid, '%name' => $user->name));
  $script->addSet('user_uid', $user->uid);
  $script->addSet('user_name', $user->name);

  return $script;
}

/*
 * Copied from _voipextension_get_play_extension_script().
 * Removes message when transferring to an extension.
 */
function _vojo_get_play_extension_script($eid, $options=array()) {
  // @todo load api, when in a separate file.

  $script = new VoipScript('vojo_play_extension');
  // using voipscript %number replacement
  $script->setVar('number', $eid);

  if (($extension = voipextension_load($eid)) && $extension['enabled']) {
    $gosub = voipextension_get_script($extension);
    $arguments = array_merge($gosub['script_arguments'], $options);
    // include the extension in the arguments
    $arguments['eid'] = $eid;
    $script->addGosub($gosub['script_name'], $arguments);
  }
  else {
    if (! $unknown = variable_get('voipextension_unknown_msg', FALSE)) {
      $unknown = "^v('Unknown extension %number.',null,null,%vojo_voice)";
    }
    $script->addSay($unknown);

  }
  $script->addReturn();
 
  return $script;
}


/*
 * Receive a text message.  Update the user's name if they have an existing account.
 */
function _vojo_default_incoming_text() {
  $script = new VoipScript('vojo_default_incoming_text');
  $script->addLog('Received incoming text from %caller_number, changing username');
  
  $script->addGosub('vojo_route_inboud_text', array('number' => '%caller_number', 'text' => '%inbound_text_contents'));
  return $script;
}

/*
 * Routes a text message to update_username or sms_post function
 * depending on existence (or not) of 'name' keyword
 */
function _vojo_route_inbound_text($number, $text) {
  $script = new VoipScript('vojo_route_inboud_text');
  
  // keywords for groups are '#'+the username of the group posting address
  $group_keywords = array();
  $rs = db_query("SELECT field_yeta_value,nid FROM {content_type_group};");  
  while ($row = db_fetch_array($rs)) {
    $group_email = $row['field_yeta_value'];
    $group_nid = $row['nid'];
    $mail_arr = explode('@',$group_email);
    if (sizeof($mail_arr) > 0) {
      $group_hash = '#'.$mail_arr[0];
      $group_keywords[$group_hash] = $group_nid;
    }

  }

  $arr = explode(' ',trim($text));
  
  // check for anon flag
  $anon = False;
  if (strtolower($arr[0]) == 'anon') {
    $anon = True;
    array_shift($arr);
  }

  $keyword = strtolower($arr[0]);
  $uid = sms_user_get_uid($number);
  if (($keyword == 'name' || $keyword == 'nombre' || $keyword == 'nome') && count($arr) > 1) {
    //change username
    $script->addGosub('vojo_update_username', array('number' => $number, 'text' => $arr[1]));
  } elseif (array_key_exists($keyword, $group_keywords)){
    //look for group keywords
    array_shift($arr);
    $post_text = implode(' ', $arr);
    $group_nid = $group_keywords[$keyword];
    $script->addGosub('vojo_post_sms_story', array('number' => $number, 
						   'text' => $post_text, 
						   'nid' => $group_nid, 
						   'anon' => $anon));
  }elseif($uid) {
    // previously registered users can post to the group they registered without requiring
    // group keyword
    $post_text = implode(' ', $arr);
    $user = user_load($uid);
    $user_group_nids = array_keys($user->og_groups);
    if(sizeof($user_group_nids)==0) {
      return $script;
    }
    $user_group_nid = $user_group_nids[0];
    $script->addGosub('vojo_post_sms_story', array('number' => $number, 
						   'text' => $post_text, 
						   'nid' => $user_group_nid, 
						   'anon' => $anon));
  }
  return $script;
}


/*
 * Post sms as story for user with specified number,
 * if no number exits, creates account and post
 */
function _vojo_post_sms_story($number, $text, $nid, $anon = False) {

  $script = new VoipScript('vojo_post_sms_story');
  $uid = sms_user_get_uid($number);
  if ($anon) {
    $uid = vojo_og_anon_get_user_id();
  }
  elseif (!$uid) {
    $script->addGosub('vojo_create_user', array('number' => '%caller_number','nid' => $nid, 'simple'=> True));
    //_vojo_notify_new_user(68, $number, 'passtest');
    return $script;

  }
  
  $user = user_load($uid);
  $node = new stdClass();
  $node->pass = NULL;
  $node->type = 'blog';
  $node->uid = $uid;
  $node->name = $user->name;
  $node->body = $text;
  $node->title = truncate_utf8(trim($node->body), 29, True);
  node_validate($node);
  $node = node_submit($node);
  node_save($node);

  $result = db_query('INSERT INTO {og_ancestry} (nid, group_nid) values (%d, %d)', $node->nid, $nid);
  _vojo_notify_saved_blog($uid, $number, $node->nid);
  return $script;
}



/*
 * Update a username.  Eventually, this should be combined with the
 * sms_registration code.
 */
function _vojo_update_username($number, $text) {
  global $user;
  $script = new VoipScript('vojo_update_username');
  // Skip if text is too long
  if (strlen($text) > 32) {
    watchdog('vojo', "Requested name too long: $number: $name");
  }
  // Authenticate
  $uid = sms_user_get_uid($number);
  if (!$uid) {
    $script->addReturn();
    return $script;
  }
  $old_user = $user;
  $user = user_load($uid);
  if (empty($user)) {
    watchdog('vojo', "Unable to authenticate voipdrupal sms from $number");
    $user = $old_user;
    $script->addReturn();
    return $script;
  }
  // Get language
  $user_language = sms_registration_get_user_language($user);
  // Try to change username
  $info = trim($text);
  $save = array('sms_user' => array('number' => sms_formatter($number), 'status' => SMS_USER_CONFIRMED, 'gateway' => array('carrier' => $user->sms_user[0]['gateway']['carrier'])));
  // Figure out if this is username or email (based on admin setting)
  if (variable_get('sms_registration_request_user', 'name') == 'name') {
    $save['name'] = $info;
  } else if (variable_get('sms_registration_request_user', 'name') == 'mail') {
    if (valid_email_address($info)) {
      $save['mail'] = $info;
    }
  }
  // Save changes
  $user = user_save($user, $save);
  if (empty($user)) {
    $message = sms_registration_failed_msg( $user->name, $user_language );
  } else {
    $message = sms_registration_name_changed_msg( $info, variable_get('site_name', 'the site'), $user_language );
  }
  // Send confirmation
  // This is a workaround because addSendText ignores the "from" number
  watchdog('vojo', 'Sending username change confirmation to user : ' . $user->name);
  $script->addSendText($message);
  $user = $old_user;
  $script->addReturn();
  return $script;
}


/**
 * VoIP Script used to send sms messages with username and password information
 * to new users
 *
 * @param (int) (uid) new user id
 * @param (int) (number) new user's registered phone number
 * @param (string) (password) new user's generated password
 */
function _vojo_notify_new_user($uid, $number, $password) {
  $user = user_load($uid);
  // send them an sms
  $user_language = sms_registration_get_user_language($user);  // switch to the correct language for SMSs
  // TODO: centrally locate this text in sms_registration?
  $result1 = _vojo_send_sms($number, t('Welcome! Your username is !name, password is !pass. You can login to !server_url on the web with this info.',
    array('!name'=>$user->name, '!pass'=>$password, '!server_url'=>variable_get('site_name', 'vojo.co')), $user_language ) ); 
  $sms_reg = variable_get('voipcall_text_number', sms_registration_get_address());
  $result2 = _vojo_send_sms($number, t("To change your username, just text: name yourusername to !sms_reg",
				       array('!sms_reg'=>$sms_reg), $user_language)); 
}


/**
 * VoIP Script used to send sms messages with url information of new user posts
 *
 *
 * @param (int) (uid) new user id
 * @param (int) (number) new user's registered phone number
 * @param (int) (nid) node id for new blog post
 */
function _vojo_notify_saved_blog($uid, $number, $nid) {
  $user = user_load($uid);
  $user_language = sms_registration_get_user_language($user);  // switch to the correct language for SMSs
  $blog_url = url('node/'. $nid, array('absolute' => True));
  $result1 = _vojo_send_sms($number, t('Thanks for the story, !name. You can find it online at !blog_url',
				       array('!name'=>$user->name,'!blog_url'=>$blog_url), $user_language)); 
}

/**
 * VoIP Script used to assign a new user recording to a new blog post
 *
 * @param (int) (nid) group node id
 * @param (int) (fid) file id, from files table
 * @param (uid) (uid) user id
 */
function vojo_save_blog($nid, $fid, $uid) {
  global $user;
  
  // Log the user in
  if ($uid==0) {
    $uid = vojo_og_anon_get_user_id(); // DO NOT use user_load(0); - anonymous cannot post to og groups :-(
  }
  $user = user_load($uid);
  
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
}



/**
 * Function executed on hang up.
 */
function _vojo_voipscript_hangup_callback($original_call) {
  module_load_include('inc', 'vojo', 'includes/vojo.script');
  $original_script = $original_call->getScript();
  $cid = $original_call->getCid();
  $gid = $original_script->getVar('gid');
  $fid = $original_script->getVar('recording_fid');
  $uid = $original_script->getVar('user_uid');
  $number = $original_script->getVar('caller_number');
  $password = $original_script->getVar('password');
  $blog_post_saved = $original_script->getVar('blog_post_saved');
  $auto_save_blog = $original_script->getVar('auto_save_blog');
  if($auto_save_blog) {
    vojo_save_blog($gid, $fid, $uid);
  } 
  if($auto_save_blog || $blog_post_saved) {
      $res = db_query("SELECT nid FROM {upload} where fid = %d", $fid);
      while ($row = db_fetch_array($res)) {
	$post_nid = $row['nid'];
      }
      _vojo_notify_saved_blog($uid, $number, $post_nid);
  }
}


