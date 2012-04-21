<?php

/**
 * Implementation of hook_block().
 */
function vojo_og_block($op = 'list', $delta = 0, $edit = array()) {
  switch($op){
         case 'list':
            $block['generic-group-menu'] = array(
                 'info'=>t('Vojo: Generic Group Menu'),
                 'cache' => BLOCK_NO_CACHE,
                 'region'=>'navigation',
             );
            $block['vojo-group-details'] = array(
                'info' => t('Vojo: Group Details'),
                'cache' => BLOCK_NO_CACHE,
                'status' => 1,
                'region' => 'sidebar',
                'visibility' => 0,
            );
             break;
         case 'view':
             switch($delta){
                case 'generic-group-menu':
                    return array(
                      'subject' => NULL,
                      'content' => _vojo_og_generic_group_menu_block_contents(),
                     );
                     break;
                case 'vojo-group-details':
                    return vojo_group_details_block();
                    break;
             }
             break;
    }
    return $block;
}

/**
 * Supply a generic menu for un-themed groups
 */
function _vojo_og_generic_group_menu_block_contents(){
    $contents = null;
    $group_node = og_get_group_context();
    $group_nid = $group_node->nid;
    if($group_nid){
        $group_node = node_load($group_nid);
        // group name
        // $contents.= "<h2>".$group_node->title."</h2>";
        $contents.= " ";
        // MENU LINKS
        $contents.= '<ul class="menu">';
        // group homepage
        $contents.= '<li class="leaf first">';
        $contents.= l(t('Home'), drupal_get_path_alias("node/".$group_nid));
        $contents.= "</li>";
        // group about page
        if (!empty($group_node->body)) {
            $contents.= '<li class="leaf">';
            $contents.= l(t('About'), drupal_get_path_alias("node/".$group_nid."/about"));
            $contents.= "</li>";
        }    
        // group story submit page
        if (user_access('create blog entries')) {
            $contents.= '<li class="leaf">';
            $contents .= l(t('Submit'), "node/add/blog", array('attributes' => array('title' => t('Add a new story in this group.')),'query' => "gids[]=$group_nid"));
            // $contents.= l(t('Submit'), drupal_get_path_alias("node/".$group_nid."/submit"));
            $contents.= "</li>";               
        }
        // Browse stories  
        $contents.= '<li class="leaf">';
        $contents.= l(t('Browse Stories'), drupal_get_path_alias("node/".$group_nid."/browse"));
        $contents.= "</li>";
        // add map link only if group type is *not* maps. iif there's a map on the
        // group home page there is no need to add the map again to the group menu. 
       if ($group_node->field_group_type[0]['value'] != 'maps') {
            $contents.= '<li class="leaf">';
            $contents.= l(t('Map'), drupal_get_path_alias("node/".$group_nid."/map"));
            $contents.= "</li>";            
        }
        // admin links
        if(user_access( variable_get('og_user_roles_default_admin_role', 0) )  ){
            // group unpublished blog entries
            $contents.= '<li class="leaf">';
            $contents.= l(t('Unpublished'), drupal_get_path_alias("node/".$group_nid."/unpublished"));
            $contents.= "</li>";
            // group members administration
            $contents.= '<li class="leaf">';
            $contents.= l(t('Members'), drupal_get_path_alias("og/users/".$group_nid));
            $contents.= "</li>";            
            
        }
        $contents.= "</ul>";
    }
    return $contents;
}

/**
 * This is a forked version of og_block_details().
 */
function vojo_group_details_block() {
  global $user;
  $node = og_get_group_context();
  // Get voip call in number, set at admin/voip/call/settings
  $vojo_voip_number = variable_get('voipcall_cid_number','');
  // Display extension.
  // TODO - need to add field in group for this.
  if (isset($node->voipextension_number) && $node->voipextension_listed == 1) {
    $og_extenson = $node->voipextension_number;
  }
  if (isset($node->field_yeta[0]['value'])) {
    $og_email = $node->field_yeta[0]['value']; 
  }
  
  $message = array();
  $message['post_story'] = '<h3>'. t('Post your story to this group!') .'</h3>';
  $message['post_story'] .= '<p>'. t('Just send a sms or mms (picture message) from your phone to <em>@email</em>', array('@email' => $og_email)) .'</p>';
  if ($vojo_voip_number && $og_extenson) {
    $message['post_story'] .= '<p>'. t('Or call @phone ext. @ext to record your audio story', array('@phone' => $vojo_voip_number, '@ext' => $og_extenson)) .'</p>';
  }
                                                                                                                      
  // Only display group details if we have a group context.
  if ($node && node_access('view', $node)) {
    list($txt, $subscription) = og_subscriber_count_link($node);
    if ($subscription == 'active' || user_access('administer nodes')) {
      $links = module_invoke_all('og_create_links', $node);
      // Add post instructions to beginning of $links array
      array_unshift($links, $message['post_story']);
      // We want to open this up for OG_INVITE_ONLY but we need to handle invitation workflow much better. See http://drupal.org/node/170332
      if ($node->og_selective < OG_INVITE_ONLY) {
        $links['invite'] = l(t('Invite friend'), "og/invite/$node->nid");
      }
      $links['subscribers'] = $txt;
      $links['manager'] = t('Manager: !name', array('!name' => theme('username', $node)));

      // Site admins get a Join link if they are not yet subscribed.
      $subscribe = isset($subscription) && og_is_group_member($node->nid, FALSE) ? l(t('My membership'), "og/manage/$node->nid") : og_subscribe_link($node);
      if(isset($subscribe)) {
        $links['my_membership'] = $subscribe;
      }
    }
    elseif ($subscription == 'requested') {
      $links['approval'] = t('Your membership request awaits approval.');
      $links['delete'] = l(t('Delete request'), "og/unsubscribe/$node->nid/$user->uid", array('query' => 'destination=og'));
    }
    elseif ($node->og_selective == OG_OPEN) {
      $dest = drupal_get_destination();
      if (!$user->uid) {
        if (variable_get('user_register', 1) == 0) {
          $links['must_login'] = t('To subscribe to this group, you must <a href="!login">login</a>.', array('!login' => url("user/login", array('query' => $dest))));
        }
        else {
          $links['must_login'] = t('To subscribe to this group, you must <a href="!register">register</a> or <a href="!login">login</a>.', array('!register' => url("user/register", array('query' => $dest)), '!login' => url("user/login", array('query' => $dest))));
        }
      }
      else {
        $links['subscribe'] = og_subscribe_link($node);
      }
      // Add post instructions to beginning of $links array
      if (count($links) > 0) {
        array_unshift($links, $message['post_story']);
      }
      else {
        $links['post_story'] = $message['post_story'];
      }        
      // If open group and user is logged in, display join link.
    }
    elseif ($node->og_selective == OG_MODERATED) {
      $links['subscribe'] = og_subscribe_link($node);
    }
   /* elseif ($node->og_selective < OG_INVITE_ONLY) {
      $links['subscribe'] = og_subscribe_link($node);
    }
    elseif ($node->og_selective == OG_INVITE_ONLY) {
      $links['closed'] = t('This is an <em>invite only</em> group. The group administrators add/remove members as needed.');
    }
    elseif ($node->og_selective == OG_CLOSED) {
      $links['closed'] = t('This is a <em>closed</em> group. The group administrators add/remove members as needed.');
    } */

    // Modify these links by reference. If you want control of the whole block, see og_block_details().
    drupal_alter('og_links', $links, $node);

    if (!empty($links)) {
      $block['content'] = '<h2>'. l($node->title, "node/$node->nid") .'</h2>';
      $block['content'] .= theme('item_list', $links);
    }

    return $block;
  }
}
