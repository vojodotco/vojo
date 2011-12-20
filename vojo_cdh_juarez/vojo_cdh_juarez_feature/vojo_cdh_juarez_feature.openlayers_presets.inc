<?php

/**
 * Implementation of hook_openlayers_presets().
 */
function vojo_cdh_juarez_feature_openlayers_presets() {
  $export = array();

  $openlayers_presets = new stdClass;
  $openlayers_presets->disabled = FALSE; /* Edit this to true to make a default openlayers_presets disabled initially */
  $openlayers_presets->api_version = 1;
  $openlayers_presets->name = 'cdh_story_preset';
  $openlayers_presets->title = 'CDH Juarez Story';
  $openlayers_presets->description = 'show one CDH Juarez story';
  $openlayers_presets->data = array(
    'width' => 'auto',
    'height' => '400px',
    'image_path' => '/sites/all/libraries/openlayers/themes/dark/',
    'css_path' => 'sites/all/libraries/openlayers/themes/dark/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '-106.425624, 31.7',
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
        'zoomtolayer' => 'cdhj_one_story_cdhj_one_story_ol_data',
        'point_zoom_level' => '13',
      ),
    ),
    'default_layer' => 'osm_mapnik',
    'layers' => array(
      'osm_mapnik' => 'osm_mapnik',
      'cdhj_one_story_cdhj_one_story_ol_data' => 'cdhj_one_story_cdhj_one_story_ol_data',
    ),
    'layer_styles' => array(),
    'layer_activated' => array(
      'cdhj_one_story_cdhj_one_story_ol_data' => 'cdhj_one_story_cdhj_one_story_ol_data',
    ),
    'layer_switcher' => array(),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'vojo_cdh_juarez_selected',
      'select' => 'vojo_cdh_juarez_selected',
      'temporary' => 'vojo_cdh_juarez_temporary',
    ),
  );
  $export['cdh_story_preset'] = $openlayers_presets;

  $openlayers_presets = new stdClass;
  $openlayers_presets->disabled = FALSE; /* Edit this to true to make a default openlayers_presets disabled initially */
  $openlayers_presets->api_version = 1;
  $openlayers_presets->name = 'cdhj_stories_preset';
  $openlayers_presets->title = 'CDH Juarez Stories';
  $openlayers_presets->description = 'show all the stories for CDH Juarez';
  $openlayers_presets->data = array(
    'width' => 'auto',
    'height' => '400px',
    'image_path' => 'sites/all/libraries/openlayers/themes/dark/',
    'css_path' => 'sites/all/libraries/openlayers/themes/dark/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '-106.425624, 31.70',
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
          'cdhj_all_stories_cdhj_stories_ol_data' => 'cdhj_all_stories_cdhj_stories_ol_data',
        ),
      ),
      'openlayers_behavior_panzoombar' => array(),
    ),
    'default_layer' => 'osm_mapnik',
    'layers' => array(
      'osm_mapnik' => 'osm_mapnik',
      'cdhj_all_stories_cdhj_stories_ol_data' => 'cdhj_all_stories_cdhj_stories_ol_data',
    ),
    'layer_styles' => array(),
    'layer_activated' => array(
      'cdhj_all_stories_cdhj_stories_ol_data' => 'cdhj_all_stories_cdhj_stories_ol_data',
    ),
    'layer_switcher' => array(),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'vojo_cdh_juarez_default',
      'select' => 'vojo_cdh_juarez_selected',
      'temporary' => 'vojo_cdh_juarez_temporary',
    ),
  );
  $export['cdhj_stories_preset'] = $openlayers_presets;

  return $export;
}
