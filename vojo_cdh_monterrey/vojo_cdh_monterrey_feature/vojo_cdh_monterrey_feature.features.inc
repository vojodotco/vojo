<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function vojo_cdh_monterrey_feature_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "openlayers" && $api == "openlayers_presets") {
    return array("version" => 1);
  }
  elseif ($module == "page_manager" && $api == "pages_default") {
    return array("version" => 1);
  }
  elseif ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function vojo_cdh_monterrey_feature_imagecache_default_presets() {
  $items = array(
    '230px-sq' => array(
      'presetname' => '230px-sq',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '230',
            'height' => '230',
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function vojo_cdh_monterrey_feature_views_api() {
  return array(
    'api' => '3.0-alpha1',
  );
}
