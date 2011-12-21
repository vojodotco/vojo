<?php

/**
 * Implementation of hook_openlayers_presets().
 */
function vojo_cdh_monterrey_feature_openlayers_presets() {
  $export = array();

  $openlayers_presets = new stdClass;
  $openlayers_presets->disabled = FALSE; /* Edit this to true to make a default openlayers_presets disabled initially */
  $openlayers_presets->api_version = 1;
  $openlayers_presets->name = 'cdhm_stories_preset';
  $openlayers_presets->title = 'CDH Monterrey Stories';
  $openlayers_presets->description = 'show all the stories for CDH Monterrey';
  $openlayers_presets->data = array(
    'width' => 'auto',
    'height' => '400px',
    'image_path' => 'sites/all/libraries/openlayers/themes/dark/',
    'css_path' => 'sites/all/libraries/openlayers/themes/dark/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '-100.3, 25.7',
        'zoom' => '11',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_attribution' => array(),
      'openlayers_behavior_popup' => array(
        'layers' => array(
          'cdhm_all_stories_cdhm_stories_ol_data' => 'cdhm_all_stories_cdhm_stories_ol_data',
        ),
      ),
      'openlayers_behavior_panzoombar' => array(),
    ),
    'default_layer' => 'osm_mapnik',
    'layers' => array(
      'osm_mapnik' => 'osm_mapnik',
      'cdhm_all_stories_cdhm_stories_ol_data' => 'cdhm_all_stories_cdhm_stories_ol_data',
    ),
    'layer_styles' => array(),
    'layer_activated' => array(
      'cdhm_all_stories_cdhm_stories_ol_data' => 'cdhm_all_stories_cdhm_stories_ol_data',
    ),
    'layer_switcher' => array(),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'vojo_cdh_monterrey_default',
      'select' => 'vojo_cdh_monterrey_selected',
      'temporary' => 'vojo_cdh_monterrey_temporary',
    ),
  );
  $export['cdhm_stories_preset'] = $openlayers_presets;

  $openlayers_presets = new stdClass;
  $openlayers_presets->disabled = FALSE; /* Edit this to true to make a default openlayers_presets disabled initially */
  $openlayers_presets->api_version = 1;
  $openlayers_presets->name = 'cdm_story_preset';
  $openlayers_presets->title = 'CDH Monterrey Story';
  $openlayers_presets->description = 'show one CDH Monterrey story';
  $openlayers_presets->data = array(
    'width' => 'auto',
    'height' => '400px',
    'image_path' => '/sites/all/libraries/openlayers/themes/dark/',
    'css_path' => 'sites/all/libraries/openlayers/themes/dark/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '-100.3, 25.7',
        'zoom' => '12',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_panzoombar' => array(),
      'openlayers_behavior_zoomtolayer' => array(
        'zoomtolayer' => 'cdhm_one_story_cdhm_one_story_ol_data',
        'point_zoom_level' => '13',
      ),
    ),
    'default_layer' => 'osm_mapnik',
    'layers' => array(
      'osm_mapnik' => 'osm_mapnik',
      'cdhm_one_story_cdhm_one_story_ol_data' => 'cdhm_one_story_cdhm_one_story_ol_data',
    ),
    'layer_styles' => array(),
    'layer_activated' => array(
      'cdhm_one_story_cdhm_one_story_ol_data' => 'cdhm_one_story_cdhm_one_story_ol_data',
    ),
    'layer_switcher' => array(),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'vojo_cdh_monterrey_selected',
      'select' => 'vojo_cdh_monterrey_selected',
      'temporary' => 'vojo_cdh_monterrey_temporary',
    ),
  );
  $export['cdm_story_preset'] = $openlayers_presets;

  return $export;
}
