<?php

/**
 * Implementation of specially named hook_ctools_content_types()
 */
$plugin = array(
    'single' => TRUE,
    'icon' => 'icon_node_form.png',
    'no title override' => TRUE,
    'title' => t('Vojo: Blog node links'),
    'category' => t('Node'),
  );

function vojo_blog_links_content_type_render($subtype, $conf, $panel_args, $context) {
  $node = node_load(arg(1));
  $block->content = '';
  if ($node->og_groups_both) {
     foreach ($node->og_groups_both as $id => $name) {
    $group_nid = $id;
    $group_name = $name;
    }
    $group_link .= t(" in ") . l($group_name, 'node/'. $group_nid) . '</br>';
  }
  if ($node->name) {
    $by_name = t(" by ") . l($node->name, 'blogs/'. $node->name); 
  }
  else {
    $by_name = '';
  }
  $block->content .= '<div class="node-date">'. format_date($node->created, 'medium') .'</div>';
  $block->content .= '<div>'. t("Posted ") . $by_name . $group_link .'</div>';
  return $block;
}
