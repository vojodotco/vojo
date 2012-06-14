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
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function vojo_feature_imagecache_default_presets() {
  $items = array(
    '100px' => array(
      'presetname' => '100px',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '100',
            'height' => '100',
            'upscale' => 0,
          ),
        ),
      ),
    ),
    '375px' => array(
      'presetname' => '375px',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '375',
            'height' => '375',
            'upscale' => 0,
          ),
        ),
      ),
    ),
    '500px' => array(
      'presetname' => '500px',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '500',
            'height' => '500',
            'upscale' => 0,
          ),
        ),
      ),
    ),
    '640px' => array(
      'presetname' => '640px',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '640',
            'height' => '640',
            'upscale' => 0,
          ),
        ),
      ),
    ),
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
    'front_slideshow' => array(
      'presetname' => 'front_slideshow',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '1180px',
            'height' => '350px',
          ),
        ),
      ),
    ),
    'slideshow_window' => array(
      'presetname' => 'slideshow_window',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '770',
            'height' => '500',
            'upscale' => 0,
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function vojo_feature_node_info() {
  $items = array(
    'front_slideshow' => array(
      'name' => t('Front slideshow'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
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
