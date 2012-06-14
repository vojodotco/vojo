<?php

/**
 * Implementation of specially named hook_ctools_content_types()
 */
$plugin = array(
    'single' => TRUE,
    'icon' => 'icon_node_form.png',
    'no title override' => TRUE,
    'title' => t('Front: tagline and try it now button'),
    'category' => t('Vojo'),
  );

function vojo_front_trynow_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();

  // Load jcycle plugin
  jquery_plugin_add('cycle', 'module', 'header');
  drupal_add_js(drupal_get_path('module', 'vojo') . '/js/cycle.js', 'module');

  $view = views_embed_view('vojo_front_slideshow', 'front_slideshow');

  $block->content = '<div id="front-logo"><img src="' . base_path() . drupal_get_path('theme', 'vojo_generic') . '/logo-full.png" alt="Vojo logo" /></div>';
  $block->content .= '<div id="front-slideshow">' . $view . '<a id="vojo-slide-prev">Previous slide</a><a id="vojo-slide-next">Next slide</a></div>';
  $block->content .= '<p id="vojo-tagline">' . t('A new way for communities to share stories') . '</p>';
  $block->content .= '<p id="vojo-trynow">' . l(t('Try it now'), 'trynow', array('attributes' => array('class' => 'huge-button'))) . '</p>';
  return $block;
}

// A function that returns the name of the administration pane
function vojo_front_trynow_content_type_admin_title($subtype, $conf, $context) {
  return t('Front Try it now button');
}

// A function that returns a block with administration information
function vojo_front_trynow_content_type_admin_info($subtype, $conf, $context) {
  $block = new stdClass();
  $block->title = t('Front: tagline and try it now button');
  $block->content = '';
  return $block;
}

function vojo_front_trynow_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  return $form;
}

/**
 * Validate the node selection.
 */
/* function vojo_front_trynow_content_type_edit_form_validate($form, &$form_state) {

}*/

/**
 * The submit form stores the data in $conf.
 */
/* function vojo_front_trynow_content_type_edit_form_submit($form, &$form_state) {
  foreach($form_state['values'] as $value => $value_object) {
    $form_state['conf'][$value] = $value_object;
  }
} */