<?php

/**
 * Define custom styles for rendering the markers on a map.
 * Implements hook_openlayers_styles().
 *   http://drupal.org/node/620602
 */
function vojo_cdh_juarez_openlayers_styles() {
  $styles = array();
  
  $style = new stdClass();
  $style->api_version = 1;
  $style->name = 'vojo_cdh_juarez_default';
  $style->title = t('CDH Juarez Default style');
  $style->description = t('Basic default style for the CDH Juarez website.');
  $style->data = array(
    'pointRadius' => 6,
    'fillColor' => '#ffffff',
    'strokeColor' => '#890053',
    'strokeWidth' => 4,
    'fillOpacity' => 0.6,
    'strokeOpacity' => 0.6
  );
  $styles[ $style->name ] = $style;
  
  $style = new stdClass();
  $style->api_version = 1;
  $style->name = 'vojo_cdh_juarez_selected';
  $style->title = t('CDH Juarez Selected style');
  $style->description = t('Basic selected style for the CDH Juarez website.');
  $style->data = array(
    'pointRadius' => 15,
    'fillColor' => '#ffffff',
    'strokeColor' => '#890053',
    'strokeWidth' => 10,
    'fillOpacity' => 1.0,
    'strokeOpacity' => 1.0
  );
  $styles[ $style->name ] = $style;
  
  $style = new stdClass();
  $style->api_version = 1;
  $style->name = 'vojo_cdh_juarez_temporary';
  $style->title = t('CDH Juarez Temporary style');
  $style->description = t('Basic temporary style for the CDH Juarez website.');
  $style->data = array(
    'pointRadius' => 8,
    'fillColor' => '#ffffff',
    'strokeColor' => '#890053',
    'strokeWidth' => 6,
    'fillOpacity' => 0.5,
    'strokeOpacity' => 0.5
  );
  $styles[ $style->name ] = $style;
  
  return $styles;
}

/**
 * Tell ctools that we have custom marker styles.
 * Implements hook_ctools_plugin_api().
 *   http://drupal.org/node/620602
 */
function vojo_cdh_juarez_ctools_plugin_api($module, $api) {
  if ($module == "openlayers") {
    switch ($api) {
      case 'openlayers_styles':
        return array('version' => 1);

    }
  }
}
