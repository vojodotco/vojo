<?php

/**
 * Implementation of hook_menu_default_menu_custom().
 */
function vojo_cdh_juarez_feature_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-cdhjuarez
  $menus['menu-cdhjuarez'] = array(
    'menu_name' => 'menu-cdhjuarez',
    'title' => 'CDH Júarez Menu',
    'description' => 'Menu for the Júarez Crónicas de Héroes group',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('CDH Júarez Menu');
  t('Menu for the Júarez Crónicas de Héroes group');


  return $menus;
}
