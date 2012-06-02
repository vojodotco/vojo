<?php

/**
 * Implementation of specially named hook_ctools_content_types()
 */
$plugin = array(
    'single' => TRUE,
    'icon' => 'icon_node_form.png',
    'no title override' => TRUE,
    'title' => t('Access denied message for Blog entries'),
    'description' => t('An access denied message for Blog entries that retains group context. Use with panel '),
    'category' => t('Vojo'),
  );

function vojo_custom_access_denied_content_type_render($subtype, $conf, $panel_args, $context) {
  global $user;
  $block = new stdClass();
  
// Note: this Panels pane should to be used with a panels node variant with the following these two selection rules: 
//  1) Node: type --	Node being viewed is type Group
//  2) String: URL path -- node/*/blog-add/access-denied
  
  // Get group nid from path.
  $nid = arg(1);
  $group_node = node_load($nid);

  // If the users is logged in, redirect them to the node add form for this group. 
  if ($user->uid > 0) {
    drupal_goto("node/add/blog", 'gids[]='. $group_node->nid);
  }

  $block->title = t('Access denied');
  // Show a different message based on group membership type.
  if ($node->og_selective == OG_OPEN) {
    $message = '<p>'. t("If you'd like, you can post a story to this group from your phone - just follow the directions on the right. Once you've done that, you'll also become a group member.") .'</p>';
  }
  else {
    $message = '<p>'. t("Sorry, only members can post stories to this group.", array('@title' => $node->title)) .'</p>';
  }
  $block->content = $message;
  return $block;
}

// A function that returns the name of the administration pane
function vojo_custom_access_denied_content_type_admin_title($subtype, $conf, $context) {
  return t('Display uploaded photos');
}

// A function that returns a block with administration information
function vojo_custom_access_denied_content_type_admin_info($subtype, $conf, $context) {
  $block = new stdClass();
  $block->title = t('Access Deneid Messages');
  $block->content = NULL;
  return $block;
}

function vojo_custom_access_denied_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  return $form;
}
