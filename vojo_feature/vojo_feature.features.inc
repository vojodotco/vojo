<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function vojo_feature_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "openlayers" && $api == "openlayers_presets") {
    return array("version" => 1);
  }
  elseif ($module == "page_manager" && $api == "pages_default") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function vojo_feature_imagecache_default_presets() {
  $items = array(
    'browse_stories' => array(
      'presetname' => 'browse_stories',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '246',
            'height' => '246',
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
function vojo_feature_views_api() {
  return array(
    'api' => '3.0',
  );
}
