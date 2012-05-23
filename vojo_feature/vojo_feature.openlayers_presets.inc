<?php

/**
 * Implementation of hook_openlayers_presets().
 */
function vojo_feature_openlayers_presets() {
  $export = array();

  $openlayers_presets = new stdClass;
  $openlayers_presets->disabled = FALSE; /* Edit this to true to make a default openlayers_presets disabled initially */
  $openlayers_presets->api_version = 1;
  $openlayers_presets->name = 'vojo_default';
  $openlayers_presets->title = 'Vojo Default';
  $openlayers_presets->description = 'The generic default vojo empty map';
  $openlayers_presets->data = array(
    'width' => 'auto',
    'height' => '400px',
    'image_path' => 'sites/all/libraries/openlayers/themes/dark/',
    'css_path' => '',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '0,0',
        'zoom' => '2',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_attribution' => array(),
      'openlayers_behavior_panzoombar' => array(),
    ),
    'default_layer' => 'osm_mapnik',
    'layers' => array(
      'osm_mapnik' => 'osm_mapnik',
    ),
    'layer_styles' => array(),
    'layer_activated' => array(),
    'layer_switcher' => array(),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'vojo_default',
      'select' => 'vojo_default',
      'temporary' => 'vojo_default',
    ),
  );
  $export['vojo_default'] = $openlayers_presets;

  $openlayers_presets = new stdClass;
  $openlayers_presets->disabled = FALSE; /* Edit this to true to make a default openlayers_presets disabled initially */
  $openlayers_presets->api_version = 1;
  $openlayers_presets->name = 'vojo_group_all_stories_preset';
  $openlayers_presets->title = 'Vojo Group Stories';
  $openlayers_presets->description = 'show all the stories for vojo.co group';
  $openlayers_presets->data = array(
    'width' => 'auto',
    'height' => '400px',
    'image_path' => 'sites/all/libraries/openlayers/themes/dark/',
    'css_path' => 'sites/all/libraries/openlayers/themes/dark/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 1,
    'center' => array(
      'initial' => array(
        'centerpoint' => '',
        'zoom' => '11',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_dragpan' => array(),
      'openlayers_behavior_panzoombar' => array(),
      'openlayers_behavior_zoomtolayer' => array(
        'zoomtolayer' => 'vojo_group_stories_map_vojo_group_stories_map_ol_data',
        'point_zoom_level' => '11',
      ),
      'openlayers_plus_behavior_popup' => array(),
    ),
    'default_layer' => 'osm_mapnik',
    'layers' => array(
      'osm_mapnik' => 'osm_mapnik',
      'vojo_group_stories_map_vojo_group_stories_map_ol_data' => 'vojo_group_stories_map_vojo_group_stories_map_ol_data',
    ),
    'layer_styles' => array(),
    'layer_activated' => array(
      'vojo_group_stories_map_vojo_group_stories_map_ol_data' => 'vojo_group_stories_map_vojo_group_stories_map_ol_data',
    ),
    'layer_switcher' => array(),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'vojo_default',
      'select' => 'vojo_selected',
      'temporary' => 'vojo_temporary',
    ),
  );
  $export['vojo_group_all_stories_preset'] = $openlayers_presets;

  $openlayers_presets = new stdClass;
  $openlayers_presets->disabled = FALSE; /* Edit this to true to make a default openlayers_presets disabled initially */
  $openlayers_presets->api_version = 1;
  $openlayers_presets->name = 'vojo_story_preset';
  $openlayers_presets->title = 'Vojo Story Map';
  $openlayers_presets->description = 'show one story on map';
  $openlayers_presets->data = array(
    'width' => 'auto',
    'height' => '400px',
    'image_path' => '/sites/all/libraries/openlayers/themes/dark/',
    'css_path' => 'sites/all/libraries/openlayers/themes/dark/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 1,
    'center' => array(
      'initial' => array(
        'centerpoint' => '',
        'zoom' => '4',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_panzoombar' => array(),
      'openlayers_behavior_zoomtolayer' => array(
        'zoomtolayer' => 'vojo_node_map_vojo_node_map_ol_data',
        'point_zoom_level' => '13',
      ),
    ),
    'default_layer' => 'osm_mapnik',
    'layers' => array(
      'osm_mapnik' => 'osm_mapnik',
      'vojo_node_map_vojo_node_map_ol_data' => 'vojo_node_map_vojo_node_map_ol_data',
    ),
    'layer_styles' => array(),
    'layer_activated' => array(
      'vojo_node_map_vojo_node_map_ol_data' => 'vojo_node_map_vojo_node_map_ol_data',
    ),
    'layer_switcher' => array(),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'vojo_selected',
      'select' => 'vojo_selected',
      'temporary' => 'vojo_temporary',
    ),
  );
  $export['vojo_story_preset'] = $openlayers_presets;

  return $export;
}
