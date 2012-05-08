<?php

/**
 * Implementation of specially named hook_ctools_content_types()
 */
$plugin = array(
    'single' => TRUE,
    'icon' => 'icon_node_form.png',
    'no title override' => TRUE,
    'title' => t('Display uploaded photos'),
    'category' => t('Node'),
  );

function vojo_blog_photos_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();

  // Load jcycle plugin
  jquery_plugin_add('cycle', 'module', 'header');
  drupal_add_js(drupal_get_path('module', 'vojo') . '/js/cycle.js', 'module');
  
  // Get the node id from the url.
  $nid = arg(1);
  // load the node data
  $node = node_load($nid);
  if (!empty($node->field_image)) {
    // Load field settings, so we can select formatter.
    $field = content_fields('field_image', 'blog');
    $field['display_settings']['full']['format'] = 'slideshow_window_default';
    $node->build_mode = NODE_BUILD_NORMAL;
    // If image is a derivative of a transcoded video, remove it from images
    // displayed on full node. 
    foreach ($node->field_image as $key => $image) {
      $pos = strpos($image['filename'], 'mpeg');
      $mpeg = substr($image['filename'], $pos, 4);
      if ($mpeg == 'mpeg') {
        unset($node->field_image[$key]);
      }
    }
    // Render field
    $block->content = '';
    if (count($node->field_image) > 1) {
      $block->content .= '<div id="vojo-cycle-wrapper">';
    }
    $block->content .= content_view_field($field, $node);
    if (count($node->field_image) > 1) {
      $block->content .= '<div id="vojo-node-cycle-prev"><</div>';
      $block->content .= '<div id="vojo-node-cycle-next">></div>';
      $block->content .= '</div>'; 
    }
    $block->content .= '<div id="vojo-node-cycle-pager"></div>';
  }
  return $block;
}

// A function that returns the name of the administration pane
function vojo_blog_photos_content_type_admin_title($subtype, $conf, $context) {
  return t('Display uploaded photos');
}

// A function that returns a block with administration information
function vojo_blog_photos_content_type_admin_info($subtype, $conf, $context) {
  $block = new stdClass();
  $block->title = t('Display uploaded photos');
  $block->content = NULL;
  return $block;
}

function vojo_blog_photos_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  return $form;
}

/**
 * Validate the node selection.
 */
/* function vojo_blog_photos_content_type_edit_form_validate($form, &$form_state) {

}*/

/**
 * The submit form stores the data in $conf.
 */
/* function vojo_blog_photos_content_type_edit_form_submit($form, &$form_state) {
  foreach($form_state['values'] as $value => $value_object) {
    $form_state['conf'][$value] = $value_object;
  }
} */