<?php

/**
 * Implementation of hook_content_default_fields().
 */
function vojo_feature_content_default_fields() {
  $fields = array();

  // Exported field: field_group_header_bg_color
  $fields['group-field_group_header_bg_color'] = array(
    'field_name' => 'field_group_header_bg_color',
    'type_name' => 'group',
    'display_settings' => array(
      'weight' => '-1',
      'parent' => '',
      'label' => array(
        'format' => 'above',
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
    'type' => 'colorpicker_cck_textfield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'colorpicker_cck',
    'active' => '1',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_group_header_bg_color][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Header background color',
      'weight' => '1',
      'description' => '',
      'type' => 'colorpicker_cck',
      'module' => 'colorpicker_cck',
    ),
  );

  // Exported field: field_group_maps_opt_out
  $fields['group-field_group_maps_opt_out'] = array(
    'field_name' => 'field_group_maps_opt_out',
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
    'type' => 'text',
    'required' => '0',
    'multiple' => '1',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => 'Unselect this box to turn maps off.',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Maps',
      'weight' => '-2',
      'description' => 'By default, your group has a map view that shows stories as points on a map, if they have location information. ',
      'type' => 'optionwidgets_buttons',
      'module' => 'optionwidgets',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Header background color');
  t('Maps');

  return $fields;
}
