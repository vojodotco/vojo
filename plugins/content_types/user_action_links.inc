<?php

/**
 * Implementation of specially named hook_ctools_content_types()
 */
$plugin = array(
    'single' => TRUE,
    'icon' => 'icon_node_form.png',
    'no title override' => TRUE,
    'title' => t('Vojo: user action links'),
    'category' => t('User'),
  );

function vojo_user_action_links_content_type_render($subtype, $conf, $panel_args, $context) {
  
  ctools_include('modal');
  ctools_modal_add_js();
  
  $user = user_load(arg(1));  
  $types = node_get_types('types');
  $action_links = '<ul id="vojo-create-content-links">';
  foreach ($types as $key => $type) {    
    if ($key == 'blog' || $key == 'group') {
      $access = "create " . $key . " content";
      if (user_access('create blog entries') && $key == 'blog') {

        ctools_include('modal');
        ctools_modal_add_js();

        $action_links .= '<li>'. l(t("Create story", array('@type' => $type->name)), 'story/nojs/go', array('attributes' => array('class' => 'ctools-use-modal'))) . '</li>';

      }
      if (user_access($access) && $key == 'group') {
        $action_links .= '<li>'. l(t("Create @type", array('@type' => $type->name)), 'node/add/'. $key) . '</li>';
      } 
    }
  }

  $action_links .= '<li>'. l(t('Edit my settings'), 'user/'. $user->uid .'/edit') .'</li>';
  $action_links .= '</ul>';
  
  $block->title = '';
  $block->content = $action_links;
  return $block;
}
