<?php

/**
 * Implementation of specially named hook_ctools_content_types()
 */
$plugin = array(
    'single' => TRUE,
    'icon' => 'icon_node_form.png',
    'no title override' => TRUE,
    'title' => t('Access Deneid Messages'),
    'category' => t('Vojo'),
  );

function vojo_custom_access_denied_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  
  // Assuming the path for the panel is node/add/blog/%node/access-denied
  $block->title = t('Access denied');
  $block->content = '<p>'. t("Sorry, only members can post stories to this group.", array('@title' => $node->title)) .'</p>';
  $block->content .= '<p>'. t("If you'd like, you can post a story to this group from your phone - just follow the directions on the right. Once you've done that, you'll also become a group member.") .'</p>';
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
