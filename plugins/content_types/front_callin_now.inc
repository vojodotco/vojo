<?php

/**
 * Implementation of specially named hook_ctools_content_types()
 */
$plugin = array(
    'single' => TRUE,
    'icon' => 'icon_node_form.png',
    'no title override' => TRUE,
    'title' => t('Front: call story in'),
    'category' => t('Vojo'),
  );

function vojo_front_callin_now_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  
  $text = $conf['text'] ? $conf['text'] : t('Call in your story!');
  $number = $conf['number'] ? '<span>'. $conf['number'] .'</span>': '617-286-5017';

  $block->content = '<div id="front-logo"><img src="' . base_path() . drupal_get_path('theme', 'vojo_generic') . '/logo-full.png" alt="Vojo logo" /></div>';
  $block->content .= '<h1 class="welcome">'. t('Welcome to Vojo.oc!') .'</h1>';
  $block->content .= '<h2>'. $text .' '. $number. '</h2>';
  return $block;
}

// A function that returns the name of the administration pane
function vojo_front_callin_now_content_type_admin_title($subtype, $conf, $context) {
  return t('Front: call story in');
}

// A function that returns a block with administration information
function vojo_front_callin_now_content_type_admin_info($subtype, $conf, $context) {
  $block = new stdClass();
  // $block->title = t('See pane settings for editing options');
  // $block->content = '';
  return $block;
}

function vojo_front_callin_now_content_type_edit_form(&$form, &$form_state) {
  $conf = $form_state['conf'];
  
  $form['text'] = array(
    '#type' => 'textfield',
    '#title' => t('Text'),
    '#default_value' => $tagline,
  );
  $form['number'] = array(
    '#type' => 'textfield',
    '#title' => t('Text'),
    '#default_value' => $tagline,
  );
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
function vojo_front_callin_now_content_type_edit_form_submit($form, &$form_state) {
  foreach($form_state['values'] as $value => $value_object) {
    $form_state['conf'][$value] = $value_object;
  }
}