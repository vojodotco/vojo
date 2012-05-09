<?php

/**
 * Implementation of hook_content_default_fields().
 */
function vojo_feature_content_default_fields() {
  $fields = array();

  // Exported field: field_location_string
  $fields['blog-field_location_string'] = array(
    'field_name' => 'field_location_string',
    'type_name' => 'blog',
    'display_settings' => array(
      'weight' => '2',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'hidden',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '200',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_location_string][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Location',
      'weight' => '2',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_direct_phone_number
  $fields['group-field_direct_phone_number'] = array(
    'field_name' => 'field_direct_phone_number',
    'type_name' => 'group',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'voipnumber',
    'required' => '0',
    'multiple' => '0',
    'module' => 'voipnumber',
    'active' => '1',
    'voipnumber_choice' => '1',
    'voipnumber_types' => '',
    'voipnumber_allowed_countries' => array(),
    'voipnumber_default' => '',
    'voipnumber_max_length' => '15',
    'voipnumber_show_code' => 1,
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'number_prefix' => 'United States of America',
          'phone' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Direct Phone Number',
      'weight' => '31',
      'description' => '',
      'type' => 'voipphonenumber_widget',
      'module' => 'voipnumber',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Direct Phone Number');
  t('Location');

  return $fields;
}
