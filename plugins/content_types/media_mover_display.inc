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
  global $base_url;
  
  $block = new stdClass();
  $block->content = '';
  // Get the node id from the url.
  $nid = arg(1);
  // load the node data
  $node = node_load($nid);
  // figure out which media to show and how to show it
  $incomplete = false;
  $harvest_files = array();
  if (isset($node->media_mover)) {
    foreach ($node->media_mover as $cid) {
      foreach ($cid as $mmfid) {
        $harvest_files[$mmfid['harvest_file']] = true;
        if (strtolower(substr($mmfid['complete_file'], -4, 4)) == '.mp3' || strtolower(substr($mmfid['complete_file'], -4, 4)) == '.wav'  ||
	   strtolower(substr($mmfid['complete_file'], -4, 4)) == 'ogg') {
          if( !array_key_exists($mmfid['fid'], $playlist) ){
            $playlist[$mmfid['fid']] = array('url' => file_create_url($mmfid['complete_file']));
            $playlist[$mmfid['fid']]['image'] = $base_url . '/' . drupal_get_path('theme', 'vojo_generic') . '/images/vojo/audio_icon_large.png';
          }
        }
        if (strtolower(substr($mmfid['complete_file'], -4, 4)) == '.flv' || strtolower(substr($mmfid['complete_file'], -4, 4)) == '.m4v') {
          if( !array_key_exists($mmfid['fid'], $playlist) ){
            $playlist[$mmfid['fid']] = array('url' => file_create_url($mmfid['complete_file']));
            $playlist[$mmfid['fid']]['image'] = base_path() . $node->field_image[0]['filepath'];
          }
        }
        if (empty($mmfid['complete_file'])) {
          $playlist[$mmfid['fid']]['empty'] = TRUE;
          // drupal_set_message("uploaded media will display after being processed");
        }
      }
    } 
  }
  // Check for unconverted wav files
  if (isset($node->field_audio_recorder)) {
    foreach ($node->field_audio_recorder as $file) {
      if (is_array($file)) {
        if (!$harvest_files[$file['filepath']]) {
          $incomplete = true;
        }
      }
    }
  }
  // build up a playlist of all the media
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
  // Output the media player
  $media_player = '';
  if ($playlist) {
    $block->content = $media_mover_vids;
    foreach ($playlist as $clip) {
      if (isset($clip['empty'])) {
        $flash_vars['playlist']['empty'] = TRUE;
      }
      else {
        $flash_vars['playlist'][] = array('file' => $clip['url'], 'image' => $clip['image']);
      }
    }
    if (isset($flash_vars['playlist']['empty'])) {
      $incomplete = true;
    }
    else {
      $media_player = theme('jwplayermodule_render_player', array(), $flash_vars);            
    }
  }
  if ($incomplete) {
    $block->content .= '<div class="messages status">'. t("This media is being converted. Please check back in a minute or two.") .'</div>';
  }
  $block->content .= $media_player;
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
