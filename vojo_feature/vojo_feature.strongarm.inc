<?php

/**
 * Implementation of hook_strongarm().
 */
function vojo_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_front_slideshow';
  $strongarm->value = 0;
  $export['comment_anonymous_front_slideshow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_front_slideshow';
  $strongarm->value = '3';
  $export['comment_controls_front_slideshow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_front_slideshow';
  $strongarm->value = '4';
  $export['comment_default_mode_front_slideshow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_front_slideshow';
  $strongarm->value = '1';
  $export['comment_default_order_front_slideshow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_front_slideshow';
  $strongarm->value = '50';
  $export['comment_default_per_page_front_slideshow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_front_slideshow';
  $strongarm->value = '0';
  $export['comment_form_location_front_slideshow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_front_slideshow';
  $strongarm->value = '0';
  $export['comment_front_slideshow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_front_slideshow';
  $strongarm->value = '1';
  $export['comment_preview_front_slideshow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_front_slideshow';
  $strongarm->value = '1';
  $export['comment_subject_field_front_slideshow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_front_slideshow';
  $strongarm->value = array(
    'title' => '-5',
    'body_field' => '0',
    'revision_information' => '3',
    'author' => '2',
    'options' => '4',
    'comment_settings' => '7',
    'language' => '1',
    'translation' => '8',
    'menu' => '-1',
    'path' => '6',
    'print' => '5',
  );
  $export['content_extra_weights_front_slideshow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_front_slideshow';
  $strongarm->value = '2';
  $export['language_content_type_front_slideshow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_front_slideshow';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_front_slideshow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_front_slideshow';
  $strongarm->value = '0';
  $export['upload_front_slideshow'] = $strongarm;

  return $export;
}
