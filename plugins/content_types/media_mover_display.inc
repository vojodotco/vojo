<?php

/**
 * Implementation of specially named hook_ctools_content_types()
 */
$plugin = array(
    'single' => TRUE,
    'icon' => 'icon_node_form.png',
    'no title override' => TRUE,
    'title' => t('Display media mover files'),
    'category' => t('Node'),
  );

// A function that renders the pane
function vojo_media_mover_display_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  // Get the node id from the url.
  $nid = arg(1);
  // load the node data
  $node = node_load($nid);
  if (isset($node->media_mover)) {
    foreach ($node->media_mover as $cid) {
      foreach ($cid as $mmfid) {
        if (strtolower(substr($mmfid['complete_file'], -4, 4)) == '.mp3' || strtolower(substr($mmfid['complete_file'], -4, 4))  == '.ogg') {
          if (empty($playlist) && empty($node->field_image[0])) { 
            $playlist[$mmfid['fid']] = base_path() . drupal_get_path('theme', 'vojo_generic') . '/images/audio_icon_large.gif';
          }
          $playlist[$mmfid['fid']] = array('url' => file_create_url($mmfid['complete_file']));
        }
        if (substr($mmfid['complete_file'], -4, 4) == '.flv' || substr($mmfid['complete_file'], -4, 4) == '.m4v') {
          $playlist[$mmfid['fid']] = array('url' => file_create_url($mmfid['complete_file']));
          $video = 'flowplayer-video ';
        }
      }
    } 
  }

  if (!empty($playlist)) {
    foreach($playlist as $fid => $clip) {
      if (!empty($node->files[$fid]->weight) && !isset($playlist[$node->files[$fid]->weight])) {
        $playlist[$node->files[$fid]->weight] = $clip;
        unset($playlist[$fid]);
      }
    }

  ksort($playlist);
  $playlist = array_merge($playlist);
  }
 
  // Output 
  if ($playlist) {
    $block->content = $media_mover_vids;
    foreach ($playlist as $clip) {
      $flash_vars['playlist'][] = array('file' => $clip['url']);
    }
    $block->content = theme('jwplayermodule_render_player', array(), $flash_vars);
  }
  return $block;
}

// A function that returns the name of the administration pane
function vojo_media_mover_display_content_type_admin_title($subtype, $conf, $context) {
  return t('Display media mover files');
}

// A function that returns a block with administration information
function vojo_media_mover_display_content_type_admin_info($subtype, $conf, $context) {
  $block = new stdClass();
  $block->title = t('Display media mover files');
  $block->content = NULL;
  return $block;
}

function vojo_media_mover_display_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  return $form;
}

/**
 * Validate the node selection.
 */
/* function vojo_media_mover_display_content_type_edit_form_validate($form, &$form_state) {

}*/

/**
 * The submit form stores the data in $conf.
 */
/* function vojo_vendor_item_gallery_content_type_edit_form_submit($form, &$form_state) {
  foreach($form_state['values'] as $value => $value_object) {
    $form_state['conf'][$value] = $value_object;
  }
} */
