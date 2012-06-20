<?php

/**
 * Implementation of specially named hook_ctools_content_types()
 */
$plugin = array(
    'single' => TRUE,
    'icon' => 'icon_node_form.png',
    'no title override' => TRUE,
    'title' => t('Vojo: Blog prev/next links'),
    'category' => t('Node'),
  );

function vojo_blog_prev_next_links_content_type_render($subtype, $conf, $panel_args, $context) {
  $node = node_load(arg(1));
    $block->content = '';
  if ($node->og_groups_both) {
     foreach ($node->og_groups_both as $id => $name) {
    $group_nid = $id;
    $group_name = $name;
    }
    $block->content .= '<h3>'. $group_name .'</h3>';
  }
  // Use views to generate the Prev / Next pager.
  $view = views_get_view_result('vojo_group_browse_stories', 'prev_next_links', $group_nid);
  $numItems = count($view);
  $i = 0;
  foreach ($view as $key => $item) {
    if ($item->nid == arg(1)) {
      $prev_key = $key - 1;
      $next_key = $key + 1;
      
      // Prev link
      if ($key == 0) {
        $prev_link = '';
      }
      else {
        $prev_item = $view[$prev_key];
        $prev_link = l(t('Previous'), 'node/'. $prev_item->nid, array('attributes' => array('class' => 'blog-prev')));
      }
      // Next link
      if ($i+1 == $numItems) {
        $next_link = '';
      }
      else {
        $next_item = $view[$next_key];        
        $next_link = l(t('Next'), 'node/'. $next_item->nid, array('attributes' => array('class' => 'blog-next')));
      }
    $block->content = '<span class="blog-prev-next">'. $prev_link .' '. $next_link .'</span>';
    }
  $i++;
  }
  return $block;
}
