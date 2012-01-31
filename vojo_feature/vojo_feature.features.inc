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
 * Implementation of hook_views_api().
 */
function vojo_feature_views_api() {
  return array(
    'api' => '3.0-alpha1',
  );
}
