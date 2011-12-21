<?php

/**
 * Implementation of hook_menu_default_menu_custom().
 */
function vojo_cdh_monterrey_feature_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-monterrey
  $menus['menu-monterrey'] = array(
    'menu_name' => 'menu-monterrey',
    'title' => 'CDH Monterrey Menu',
    'description' => 'Menu for the Monterrey Crónicas de Héroes group',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('CDH Monterrey Menu');
  t('Menu for the Monterrey Crónicas de Héroes group');


  return $menus;
}
