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
  
  $feature_audio = theme('image', drupal_get_path('theme', 'vojo_generic') . '/images/vojo/feature-blogging.png');
  $feature_audio .= '<h3>' . t('No data plan required') . '</h3>';
  $feature_audio .= '<p>' . t('Blog from your phone via SMS, MMS, or Voice calls.') . '</p>';
  $items['feature_audio'] = array(
    'data' => $feature_audio,
  );
  
  $feature_sms_reg = theme('image', drupal_get_path('theme', 'vojo_generic') . '/images/vojo/feature-phone.png');
  $feature_sms_reg .= '<h3>' . t('SMS registration') . '</h3>';
  $feature_sms_reg .= '<p>' . t('Create an account from your phone') . '</p>';
  $items['feature_sms_reg'] = array(
    'data' => $feature_sms_reg,
  );  
  
  $feature_mapping = theme('image', drupal_get_path('theme', 'vojo_generic') . '/images/vojo/feature-mapping.png');
  $feature_mapping .= '<h3>' . t('Geolocation') . '</h3>';
  $feature_mapping .= '<p>' . t('Add your stories to a map.') . '</p>';
  $items['feature_mapping'] = array(
    'data' => $feature_mapping,
  );  
  
  $feature_groups = theme('image', drupal_get_path('theme', 'vojo_generic') . '/images/vojo/feature-groups.png');
  $feature_groups .= '<h3>' . t('Groups') . '</h3>';
  $feature_groups .= '<p>' . t('Create and customize your own group.') . '</p>';
  $items['feature_groups'] = array(
    'data' => $feature_groups,
  );

  $feature_sms_blast = theme('image', drupal_get_path('theme', 'vojo_generic') . '/images/vojo/feature-sms-blast.png');
  $feature_sms_blast .= '<h3>' . t('Broadcast') . '</h3>';
  $feature_sms_blast .= '<p>' . t('Blast SMS to all of your Group members.') . '</p>';
  $items['feature_sms_blast'] = array(
    'data' => $feature_sms_blast,
  );
  $feature_audio_slides = theme('image', drupal_get_path('theme', 'vojo_generic') . '/images/vojo/feature-audio.png');
  $feature_audio_slides .= '<h3>' . t('Audio slideshows') . '</h3>';
  $feature_audio_slides .= '<p>' . t('Create and share slideshows with audio on your phone or in the browser.') . '</p>';
  $items['feature_audio_slides'] = array(
    'data' => $feature_audio_slides,
  );
 
  //Create and share slideshows with audio on your phone or in the browser
  
   //feature-sms-blast.png
   
  /* $block->content = '<ul id="vojo-site-features">';
  $block->content .= '<li>' . '<img src="' . base_path() . drupal_get_path('theme', 'vojo_generic') . '/images/vojo/feature-audio.png" alt="Audio icon"/>' .  t('Create an account from your phone (SMS registration).') . '</li>';
  $block->content .= '<li>'. t('Create an account from your phone (SMS registration).') . '</li>';
  $block->content .= '<li>'. t('Blast SMS to all of your Group members.') . '</li>';
  $block->content .= '</ul>'; */
  
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
  $block->title = t('Site features');
  $block->content = '';
  return $block;
}

function vojo_key_features_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
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
/* function vojo_key_features_content_type_edit_form_submit($form, &$form_state) {
  foreach($form_state['values'] as $value => $value_object) {
    $form_state['conf'][$value] = $value_object;
  }
} */