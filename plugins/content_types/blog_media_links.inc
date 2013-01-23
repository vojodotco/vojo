<?php

/**
 * Implementation of specially named hook_tools_content_types()
 */
$plugin = array(
    'single' => TRUE,
    'icon' => 'icon_node_form.png',
    'no title override' => TRUE,
    //t is for translate and it tells drupal that there is something you want to translate
    'title' => t('Vojo: Media Links'),
    'category' => t('Node'),
  );

function vojo_blog_media_links_content_type_render($subtype, $conf, $panel_args, $context) {
  $node = node_load(arg(1));
  $paths = array();
  $filepaths = '';

  foreach ($node->media_mover as $media_mover){
    foreach ($media_mover as $complete_array){
      if (strpos($complete_array['complete_file'], 'mp3') !== FALSE) {
        if ($filepaths == '') {
          $filepaths .= '<h3>Download Attached Media</h3><ul>';
        }
        $paths[] = $complete_array['complete_file'];
      } else {}
    }
  }
  foreach ($node->field_image as $field_image){
    if ($field_image['filepath'] != '' && $filepaths == '') {
      $filepaths .= '<h3>Download Attached Media</h3><ul>';
    }
    $paths[] = $field_image['filepath'];
  }
  
  foreach ($paths as $path){
    if ($path != '') {
      $filepaths .= '<li><a href ="'.file_create_url($path).'">'.basename($path).'</a></li>';
    }
  }
  
  $filepaths .= '</ul>';
  $block->content = $filepaths;
  return $block;
}
