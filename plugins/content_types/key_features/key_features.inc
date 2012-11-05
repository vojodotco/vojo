<?php

/**
 * Implementation of specially named hook_ctools_content_types()
 */
$plugin = array(
    'single' => TRUE,
    'icon' => 'icon_node_form.png',
    'no title override' => TRUE,
    'title' => t('Site features'),
    'category' => t('Vojo'),
  );

function vojo_key_features_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();

  $block->title = 'Site features';
  
  $items = array();
  foreach ($conf['features'] as $feature => $conf) {
    $url = url('trynow');
    $output = '<a href="' . $url . '"><img src="'. base_path() . drupal_get_path('module', 'vojo') .'/plugins/content_types/key_features/images/'. $feature .'.png" /></a>';
    $output .= '<h3><a href="' . $url . '">' . t($conf['title']) . '</a></h3>';
    $output .= '<p><a href="' . $url . '">' . t($conf['text']) . '</a></p>';
    $items[$feature] = array(
      'data' => $output,
    );
  }
  $block->content .= theme('item_list', $items, NULL, 'ul', array('id' => 'vojo-site-features'));
  return $block;
}

// A function that returns the name of the administration pane
function vojo_key_features_content_type_admin_title($subtype, $conf, $context) {
  return t('Site features');
}

// A function that returns a block with administration information
function vojo_key_features_content_type_admin_info($subtype, $conf, $context) {
  $block = new stdClass();
  $block->title = t('See pane settings for custom editing options');
  $block->content = '';
  return $block;
}

function vojo_key_features_content_type_edit_form(&$form, &$form_state) {
  $conf = $form_state['conf'];

  $field_list = array('feature_1', 'feature_2', 'feature_3', 'feature_4', 'feature_5', 'feature_6');
  $form['features'] = array(
    '#type' => 'fieldset',
    '#title' => t(''),
    '#tree' => TRUE,
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );
  foreach ($field_list as $key => $field_item) {
    // Note: in d7 pane fields will be much more easily created with fieldable_panels_panes.
    $item_numb = $key + 1;
    $form['features'][$field_item] = array(
      '#type' => 'fieldset',
      '#title' => 'Site feature ' . $item_numb,
      '#collapsible' => FALSE,
      '#collapsed' => FALSE,
    );
    $form['features'][$field_item]['img'] = array(
      '#type' => 'markup',
      '#value' => '<img src="'. base_path() . drupal_get_path('module', 'vojo') .'/plugins/content_types/key_features/images/'. $field_item .'.png" />',
    );
    $form['features'][$field_item]['title'] = array(
      '#type' => 'textfield',
      '#title' => t('Title'),
      '#default_value' => $conf['features'][$field_item]['title'],
    ); 
    $form['features'][$field_item]['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Text'),
      '#default_value' => $conf['features'][$field_item]['text'],
    );
  }

  return $form;
}

/**
 * Validate the node selection.
 */
/* function vojo_key_features_content_type_edit_form_validate($form, &$form_state) {

}*/

/**
 * The submit form stores the data in $conf.
 */
function vojo_key_features_content_type_edit_form_submit($form, &$form_state) {
  foreach($form_state['values'] as $value => $value_object) {
    $form_state['conf'][$value] = $value_object;
  }
}