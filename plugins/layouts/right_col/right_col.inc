<?php 
/**
 * Implementation of hook_panels_layout()
 */
 
function vojo_right_col_panels_layouts() {
  $items['right_col'] = array(
    'title' => t('Vojo: Right sidebar'),
    'icon' => 'right_col.png',
    'theme' => 'right_col',
    'css' => 'right_col.css',
    'category' => t('Vojo'),
    'panels' => array(
      'main' => t('Main'),
      'right' => t('Right sidebar'),
    ),
  );

  return $items;
}
