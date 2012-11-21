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

  // TODO: save this as the user's default language?

  // user picked english
  $script->addLabel('picked_en');
  $script->addGoSub('vojo_change_language', array('language'=>'en') );
  $script->addGoto('return');

  // user picked spanish
  $script->addLabel('picked_es');
  $script->addGoSub('vojo_change_language', array('language'=>'es') );
  $script->addGoto('return');
  
  // user picked portuguese
  $script->addLabel('picked_pt');
  $script->addGoSub('vojo_change_language', array('language'=>'pt') );
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
  
  // user wants to hear other stories - this delegates to a voipview
  $script->addLabel('hear_stories');
  $params = array('view_name' => 'vojo_group_stories_voip', 'display_id' => 'vojo_group_stories_voip', 
    'args' => json_encode(array($node->nid)));
  $script->addGosub('voipviews_read_view', $params);
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
 * VoIP Script Callback: Record blog node in group.
 *
 * $param['nid'] = Group node ID.
 */
function _vojo_record_blog_script($node) {
  $script = new VoipScript('vojo_record_blog');
 
  // login the user based on their phone number
  $script->addGosub('vojo_login', array('number' => '%caller_number'));
  $script->addSet('og_group', $node->title);
  $script->addGotoIf('handle_non_user','^%user_uid == '.vojo_og_anon_get_user_id());
  $script->addGotoIf('start_recording','^%user_uid != '.vojo_og_anon_get_user_id());
  
  // if new user, let them choose to create an account or post as anon
  $script->addLabel('handle_non_user');
  $script->addGosub('vojo_pick_create_or_anon', array('number' => '%caller_number', 'nid' => $node->nid));
  $script->addGoto('start_recording');

  // record a message
  $script->addLabel('start_recording');
  $script->addRecord(
    "^v('Start recording your message after the tone. Press the pound key to stop recording.',null,null,%vojo_voice)", 
    5, '#', 3600, 'mp3', TRUE
  );
  $script->addGotoIf('no_recording','^%recording_fid == 0');
  $script->addSay("^v('You said ',null,null,%vojo_voice)");
  $script->addSay('%recording_public_url');
  $script->addGotoIf('accept_menu', "^%recording_digits != 'hangup'");
  $script->addGosub('vojo_save_blog', array('nid' => $node->nid, 'fid' => '%recording_fid'));
  $script->addGoto('end_record');
  
  // review the recording (and save / re-record)
  $script->addLabel('accept_menu');
  $script->addGetInput(
    "^v('To accept this recording, press 1. To record it once again, press 2. To return, press the pound key.',null,null,%vojo_voice)",
    10, '', 1
  );
  $script->addGotoIf('accept recording', "^%input_digits == '1'");
  $script->addGotoIf('start_recording', "^%input_digits == '2'");
  $script->addGotoIf('end_record', "^%input_digits == '#'");
  // fall through to accept recording if no input (could be hang-up)
  $script->addLabel('accept recording');
  $script->addSay("^v('Please wait while we save your story',null,null,%vojo_voice)");
  $script->addGosub('vojo_save_blog', array('nid' => $node->nid, 'fid' => '%recording_fid'));
  $script->addGoto('end_record');

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
  $script->addGetInput('Press 1 to record an anonymous story, or press 2 to create a new account on vojo dot co', 1, '', 5);
  $script->addGotoIf('as_anon', "^%input_digits == '1'");
  $script->addGotoIf('create_user', "^%input_digits == '2'");
  $script->addSay("^v('Input not recognized',null,null,%vojo_voice)");
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
 * Create a new user and send them an sms.  
 * TODO: This does not check if the user phone exists already!
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
  $user_language = sms_registration_get_user_language($user);  // switch to the correct language for SMSs
  // TODO: centrally locate this text in sms_registration?
  $result1 = _vojo_send_sms($number, t('Welcome, thanks for the story! Your username is !name, password is !pass.  You can login to !server_url on the web with this info.',
    array('!name'=>$user->name, '!pass'=>$password, '!server_url'=>variable_get('site_name', 'vojo.co')), $language ) ); 
  $result2 = _vojo_send_sms($number, t("To change your username, just text the name you'd like to !sms_reg",
    array('!sms_reg'=>sms_registration_get_address()), $language ) ); 
  watchdog('vojo', 'Created new user via phone %name / %number', array('%name'=> $user->name,'%number'=>$number));
  // provide audio feedback
  $script = new VoipScript('vojo_create_user');
  $script->addSet('user_uid', $user->uid);
  $script->addSet('user_name', $user->name);  
  $script->addSay("^v('We made a new user account for you. We have sent you an sms with your user name and password',null,null,%vojo_voice)");
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
  $call->setCurrentChannel('text');
  $call->setCurrentNetwork('sms');
  $call->setDestNumber($number);
  $call->setCallerNumber(variable_get('voipcall_cid_number', NULL));  // this is not a useful phone number :-(
  $call->setCallerName(sms_registration_get_address());   // does this work?
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
function _vojo_save_blog_script($nid, $fid) {
  global $user;
  watchdog('vojo', 'in vojo_save_blog');
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
  watchdog('vojo', 'blog node saved');
  $script->addSay("^v('Story saved.',null,null,%vojo_voice)");
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
      $unknown = t('Unknown extension %number. ');
    }
    $script->addSay($unknown);
  }
  $script->addReturn();
 
  return $script;
}
