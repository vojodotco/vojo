<?php

/**
 * Implementation of hook_views_default_views().
 */
function vojo_feature_views_default_views() {
  $views = array();

  // Exported view: vojo_front_slideshow
  $view = new view;
  $view->name = 'vojo_front_slideshow';
  $view->description = '';
  $view->tag = '';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Restablecer';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Link (field_slideshow_link) */
  $handler->display->display_options['fields']['field_slideshow_link_url']['id'] = 'field_slideshow_link_url';
  $handler->display->display_options['fields']['field_slideshow_link_url']['table'] = 'node_data_field_slideshow_link';
  $handler->display->display_options['fields']['field_slideshow_link_url']['field'] = 'field_slideshow_link_url';
  $handler->display->display_options['fields']['field_slideshow_link_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_slideshow_link_url']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_slideshow_link_url']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_slideshow_link_url']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_slideshow_link_url']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_slideshow_link_url']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_slideshow_link_url']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_slideshow_link_url']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_slideshow_link_url']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_slideshow_link_url']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_slideshow_link_url']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_slideshow_link_url']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_slideshow_link_url']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_slideshow_link_url']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_slideshow_link_url']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_slideshow_link_url']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_slideshow_link_url']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_slideshow_link_url']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_slideshow_link_url']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_slideshow_link_url']['label_type'] = 'none';
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_slideshow_link_url]';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Content: Caption (field_slideshow_caption) */
  $handler->display->display_options['fields']['field_slideshow_caption_value']['id'] = 'field_slideshow_caption_value';
  $handler->display->display_options['fields']['field_slideshow_caption_value']['table'] = 'node_data_field_slideshow_caption';
  $handler->display->display_options['fields']['field_slideshow_caption_value']['field'] = 'field_slideshow_caption_value';
  $handler->display->display_options['fields']['field_slideshow_caption_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_slideshow_caption_value']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_slideshow_caption_value']['alter']['path'] = '[field_slideshow_link_url]';
  $handler->display->display_options['fields']['field_slideshow_caption_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_slideshow_caption_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_slideshow_caption_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_slideshow_caption_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_slideshow_caption_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_slideshow_caption_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_slideshow_caption_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_slideshow_caption_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_slideshow_caption_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_slideshow_caption_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_slideshow_caption_value']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_slideshow_caption_value']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_slideshow_caption_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_slideshow_caption_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_slideshow_caption_value']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_slideshow_caption_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_slideshow_caption_value']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_slideshow_caption_value']['format'] = 'plain';
  /* Field: Content: Slide image (field_slideshow_image) */
  $handler->display->display_options['fields']['field_slideshow_image_fid']['id'] = 'field_slideshow_image_fid';
  $handler->display->display_options['fields']['field_slideshow_image_fid']['table'] = 'node_data_field_slideshow_image';
  $handler->display->display_options['fields']['field_slideshow_image_fid']['field'] = 'field_slideshow_image_fid';
  $handler->display->display_options['fields']['field_slideshow_image_fid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_slideshow_image_fid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_slideshow_image_fid']['alter']['path'] = '[field_slideshow_link_url]';
  $handler->display->display_options['fields']['field_slideshow_image_fid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_slideshow_image_fid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_slideshow_image_fid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_slideshow_image_fid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_slideshow_image_fid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_slideshow_image_fid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_slideshow_image_fid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_slideshow_image_fid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_slideshow_image_fid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_slideshow_image_fid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_slideshow_image_fid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_slideshow_image_fid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_slideshow_image_fid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_slideshow_image_fid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_slideshow_image_fid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_slideshow_image_fid']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_slideshow_image_fid']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_slideshow_image_fid']['format'] = 'front_slideshow_default';
  $handler->display->display_options['fields']['field_slideshow_image_fid']['multiple']['group'] = 1;
  $handler->display->display_options['fields']['field_slideshow_image_fid']['multiple']['multiple_reversed'] = 0;
  /* Filter: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'front_slideshow' => 'front_slideshow',
  );
  /* Filter: Node: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';

  /* Display: Front slideshow */
  $handler = $view->new_display('panel_pane', 'Front slideshow', 'front_slideshow');
  $handler->display->display_options['pane_title'] = 'Front slideshow';
  $handler->display->display_options['pane_category']['name'] = 'Vojo';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $translatables['vojo_front_slideshow'] = array(
    t('Defaults'),
    t('more'),
    t('Apply'),
    t('Restablecer'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('[field_slideshow_link_url]'),
    t('Front slideshow'),
    t('Vojo'),
  );

  $views[$view->name] = $view;

  // Exported view: vojo_global_story_listings
  $view = new view;
  $view->name = 'vojo_global_story_listings';
  $view->description = 'Multimedia centered listing of featured stories';
  $view->tag = 'vojo';
  $view->base_table = 'node';
  $view->human_name = 'Vojo Story Listings';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['css_class'] = 'vojo-story-list';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Restablecer';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 1;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  /* Relationship: Organic groups: Group node (post) */
  $handler->display->display_options['relationships']['group_nid']['id'] = 'group_nid';
  $handler->display->display_options['relationships']['group_nid']['table'] = 'og_ancestry';
  $handler->display->display_options['relationships']['group_nid']['field'] = 'group_nid';
  $handler->display->display_options['relationships']['group_nid']['required'] = 0;
  /* Field: Node: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Content: Image (field_image) */
  $handler->display->display_options['fields']['field_image_fid']['id'] = 'field_image_fid';
  $handler->display->display_options['fields']['field_image_fid']['table'] = 'node_data_field_image';
  $handler->display->display_options['fields']['field_image_fid']['field'] = 'field_image_fid';
  $handler->display->display_options['fields']['field_image_fid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_image_fid']['format'] = 'global_stories_listings_thumbs_linked';
  $handler->display->display_options['fields']['field_image_fid']['multiple']['group'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['multiple']['multiple_number'] = '1';
  $handler->display->display_options['fields']['field_image_fid']['multiple']['multiple_reversed'] = 0;
  /* Field: Inivisible view story link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['ui_name'] = 'Inivisible view story link';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['external'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['view_node']['element_wrapper_class'] = 'vojo-view-story';
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['view_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_node']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['view_node']['text'] = 'view story';
  /* Field: Node: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_class'] = 'vojo-story-created';
  $handler->display->display_options['fields']['created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['created']['element_wrapper_class'] = 'story-date-wrapper';
  $handler->display->display_options['fields']['created']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'n/j/Y';
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '50';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'group_nid';
  $handler->display->display_options['fields']['title_1']['label'] = 'in';
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = 1;
  /* Field: Story is mapped (openlayers_wkt) */
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['id'] = 'field_map_openlayers_wkt';
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['table'] = 'node_data_field_map';
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['field'] = 'field_map_openlayers_wkt';
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['ui_name'] = 'Story is mapped (openlayers_wkt)';
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['text'] = '&nbsp;';
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['element_wrapper_class'] = 'vojo-story-mapped';
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['format'] = 'openlayers_wkt';
  /* Sort criterion: Node: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Node: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Argument: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  /* Filter: Node: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'blog' => 'blog',
  );
  /* Filter: Node: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  /* Filter: Content: Image (field_image) - list */
  $handler->display->display_options['filters']['field_image_list']['id'] = 'field_image_list';
  $handler->display->display_options['filters']['field_image_list']['table'] = 'node_data_field_image';
  $handler->display->display_options['filters']['field_image_list']['field'] = 'field_image_list';
  $handler->display->display_options['filters']['field_image_list']['value'] = '0';

  /* Display: Recent Stories */
  $handler = $view->new_display('panel_pane', 'Recent Stories', 'recent_stories');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Recent Stories';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['pane_title'] = 'Front: recent stories';
  $handler->display->display_options['pane_category']['name'] = 'Vojo';
  $handler->display->display_options['pane_category']['weight'] = '0';

  /* Display: Bloggers stories page */
  $handler = $view->new_display('page', 'Bloggers stories page', 'page_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '21';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: User&#039;s Stories Title */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['ui_name'] = 'User\'s Stories Title';
  $handler->display->display_options['header']['php']['label'] = '';
  $handler->display->display_options['header']['php']['empty'] = TRUE;
  $handler->display->display_options['header']['php']['php_output'] = '<?php
$this_user = user_load(array(\'name\' => check_plain($view->args[0])));
?>
<h1><?php print l($view->args[0] . "\'s", drupal_get_path_alias(\'user/\' .$this_user->uid)); ?> stories</h1>';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Argument: User: Name */
  $handler->display->display_options['arguments']['name']['id'] = 'name';
  $handler->display->display_options['arguments']['name']['table'] = 'users';
  $handler->display->display_options['arguments']['name']['field'] = 'name';
  $handler->display->display_options['arguments']['name']['default_action'] = 'default';
  $handler->display->display_options['arguments']['name']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['name']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['name']['default_argument_options']['code'] = 'if (arg(0) == \'blogs\') {
  return arg(1);
}';
  $handler->display->display_options['arguments']['name']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['name']['validate_fail'] = 'ignore';
  $handler->display->display_options['arguments']['name']['glossary'] = 0;
  $handler->display->display_options['arguments']['name']['ignorecase'] = 0;
  $handler->display->display_options['arguments']['name']['limit'] = '0';
  $handler->display->display_options['arguments']['name']['transform_dash'] = 0;
  $handler->display->display_options['arguments']['name']['break_phrase'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter: Node: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'blog' => 'blog',
  );
  $handler->display->display_options['path'] = 'blogs/%';

  /* Display: User stories list */
  $handler = $view->new_display('panel_pane', 'User stories list', 'vojo_user_stories_list_pane');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'My stories';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'field_image_fid' => 'field_image_fid',
    'view_node' => 'view_node',
    'created' => 'created',
    'title' => 'title',
    'title_1' => 'title_1',
    'field_map_openlayers_wkt' => 'field_map_openlayers_wkt',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_image_fid' => array(
      'align' => '',
      'separator' => '',
    ),
    'view_node' => array(
      'align' => '',
      'separator' => '',
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'title_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_map_openlayers_wkt' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Organic groups: Group node (post) */
  $handler->display->display_options['relationships']['group_nid']['id'] = 'group_nid';
  $handler->display->display_options['relationships']['group_nid']['table'] = 'og_ancestry';
  $handler->display->display_options['relationships']['group_nid']['field'] = 'group_nid';
  $handler->display->display_options['relationships']['group_nid']['required'] = 0;
  /* Relationship: User: Nodes authored */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'users';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['label'] = 'authored-by';
  $handler->display->display_options['relationships']['uid']['required'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Node: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Content: Image (field_image) */
  $handler->display->display_options['fields']['field_image_fid']['id'] = 'field_image_fid';
  $handler->display->display_options['fields']['field_image_fid']['table'] = 'node_data_field_image';
  $handler->display->display_options['fields']['field_image_fid']['field'] = 'field_image_fid';
  $handler->display->display_options['fields']['field_image_fid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_image_fid']['format'] = 'global_stories_listings_thumbs_linked';
  $handler->display->display_options['fields']['field_image_fid']['multiple']['group'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['multiple']['multiple_number'] = '1';
  $handler->display->display_options['fields']['field_image_fid']['multiple']['multiple_reversed'] = 0;
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '50';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Node: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_class'] = 'vojo-story-created';
  $handler->display->display_options['fields']['created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['created']['element_wrapper_class'] = 'story-date-wrapper';
  $handler->display->display_options['fields']['created']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'n/j/Y';
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'group_nid';
  $handler->display->display_options['fields']['title_1']['label'] = 'Grupo';
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = 1;
  /* Field: Inivisible view story link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['ui_name'] = 'Inivisible view story link';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['external'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['view_node']['element_wrapper_class'] = 'vojo-view-story';
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['view_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_node']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['view_node']['text'] = 'view story';
  /* Field: Story is mapped (openlayers_wkt) */
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['id'] = 'field_map_openlayers_wkt';
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['table'] = 'node_data_field_map';
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['field'] = 'field_map_openlayers_wkt';
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['ui_name'] = 'Story is mapped (openlayers_wkt)';
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['text'] = '&nbsp;';
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['element_wrapper_class'] = 'vojo-story-mapped';
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['format'] = 'openlayers_wkt';
  /* Field: Node: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Editar';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['external'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['edit_node']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['edit_node']['text'] = 'editar';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Argument: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['uid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['uid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['uid']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter: Node: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'blog' => 'blog',
  );
  /* Filter: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['pane_title'] = 'User: stories list';
  $handler->display->display_options['pane_category']['name'] = 'Vojo';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'uid' => array(
      'type' => 'panel',
      'context' => 'node.termpath-raw',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'User: Uid',
    ),
  );
  $translatables['vojo_global_story_listings'] = array(
    t('Defaults'),
    t('more'),
    t('Apply'),
    t('Restablecer'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Group node (post)'),
    t('Nid'),
    t('view story'),
    t('node/[nid]'),
    t('in'),
    t('&nbsp;'),
    t('All'),
    t('Recent Stories'),
    t('Front: recent stories'),
    t('Vojo'),
    t('Bloggers stories page'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('User stories list'),
    t('My stories'),
    t('authored-by'),
    t('Title'),
    t('Post date'),
    t('Grupo'),
    t('Editar'),
    t('editar'),
    t('User: stories list'),
  );

  $views[$view->name] = $view;

  // Exported view: vojo_group_all_stories
  $view = new view;
  $view->name = 'vojo_group_all_stories';
  $view->description = 'List all the stories in a group';
  $view->tag = 'vojo';
  $view->base_table = 'node';
  $view->human_name = 'Vojo Group Stories';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'All Stories';
  $handler->display->display_options['css_class'] = 'vojo-story-list';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Restablecer';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = 1;
  $handler->display->display_options['row_options']['comments'] = 0;
  /* Field: Content: Image (field_image) */
  $handler->display->display_options['fields']['field_image_fid']['id'] = 'field_image_fid';
  $handler->display->display_options['fields']['field_image_fid']['table'] = 'node_data_field_image';
  $handler->display->display_options['fields']['field_image_fid']['field'] = 'field_image_fid';
  /* Field: Node: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'node_revisions';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Sort criterion: Node: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Argument: Organic groups: Groups */
  $handler->display->display_options['arguments']['group_nid']['id'] = 'group_nid';
  $handler->display->display_options['arguments']['group_nid']['table'] = 'og_ancestry';
  $handler->display->display_options['arguments']['group_nid']['field'] = 'group_nid';
  $handler->display->display_options['arguments']['group_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['group_nid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['group_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['group_nid']['validate_type'] = 'node';
  $handler->display->display_options['arguments']['group_nid']['validate_options']['types'] = array(
    'group' => 'group',
  );
  $handler->display->display_options['arguments']['group_nid']['validate_options']['access'] = 1;
  $handler->display->display_options['arguments']['group_nid']['validate_fail'] = 'empty';
  $handler->display->display_options['arguments']['group_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['group_nid']['not'] = 0;
  /* Filter: Node: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';

  /* Display: Vojo Group All Stories Pane */
  $handler = $view->new_display('panel_pane', 'Vojo Group All Stories Pane', 'vojo_group_all_stories_pane');
  $handler->display->display_options['pane_title'] = 'Vojo Group All Stories Pane';
  $handler->display->display_options['pane_category']['weight'] = '0';

  /* Display: Vojo Group Unpublished Stories Page */
  $handler = $view->new_display('page', 'Vojo Group Unpublished Stories Page', 'vojo_group_unpublished_stories_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Unpublished Stories';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter: Node: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '0';
  $handler->display->display_options['path'] = 'node/%/unpublished';
  $translatables['vojo_group_all_stories'] = array(
    t('Defaults'),
    t('All Stories'),
    t('more'),
    t('Apply'),
    t('Restablecer'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Body'),
    t('Title'),
    t('All'),
    t('Vojo Group All Stories Pane'),
    t('View panes'),
    t('Vojo Group Unpublished Stories Page'),
    t('Unpublished Stories'),
  );

  $views[$view->name] = $view;

  // Exported view: vojo_group_browse_stories
  $view = new view;
  $view->name = 'vojo_group_browse_stories';
  $view->description = 'Multimedia centered listing of stories';
  $view->tag = 'vojo';
  $view->base_table = 'node';
  $view->human_name = 'Vojo Group Browse Stories';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'All Stories';
  $handler->display->display_options['css_class'] = 'vojo-story-list';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Restablecer';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '21';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 1;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  /* Field: Node: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Content: Image (field_image) */
  $handler->display->display_options['fields']['field_image_fid']['id'] = 'field_image_fid';
  $handler->display->display_options['fields']['field_image_fid']['table'] = 'node_data_field_image';
  $handler->display->display_options['fields']['field_image_fid']['field'] = 'field_image_fid';
  $handler->display->display_options['fields']['field_image_fid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_image_fid']['format'] = 'browse_stories_linked';
  $handler->display->display_options['fields']['field_image_fid']['multiple']['group'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['multiple']['multiple_reversed'] = 0;
  /* Field: Story is mapped (openlayers_wkt) */
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['id'] = 'field_map_openlayers_wkt';
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['table'] = 'node_data_field_map';
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['field'] = 'field_map_openlayers_wkt';
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['ui_name'] = 'Story is mapped (openlayers_wkt)';
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['text'] = 'Story is mapped';
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['element_wrapper_class'] = 'vojo-story-mapped';
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['format'] = 'openlayers_wkt';
  /* Field: Inivisible view story link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['ui_name'] = 'Inivisible view story link';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['external'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['view_node']['element_wrapper_class'] = 'vojo-view-story';
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['view_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_node']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['view_node']['text'] = 'view story';
  /* Field: Node: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_class'] = 'vojo-story-created';
  $handler->display->display_options['fields']['created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'n/j/Y';
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Node: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'node_revisions';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['body']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '90';
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 1;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 1;
  /* Field: Formats title and body text as links */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Formats title and body text as links';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<h3>[title]</h3>
<p>[body]</p>';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_wrapper_class'] = 'vojo-story-text';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  /* Field: Has Audio? */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'Has Audio?';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php']['element_type'] = '0';
  $handler->display->display_options['fields']['php']['element_label_type'] = '0';
  $handler->display->display_options['fields']['php']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['php']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php 
$has_audio = false;
$node = node_load($row->nid);
if( property_exists($node, \'media_mover\') ) {
  foreach($node->media_mover as $mm_config){
    foreach($mm_config as $mm_item){
      $pathinfo = pathinfo($mm_item[\'complete_file\']);
      if(array_key_exists(\'extension\',$pathinfo)){
        if($pathinfo[\'extension\']==\'mp3\'){
          $has_audio = true;
        }
      }
    }
  }
}
if($has_audio) {
  print \'<a href="\' . url($node->path) . \'" class="vojo-story-has-audio">\'.t(\'Has audio\')."</a>";
}
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Sort criterion: Node: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Node: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Argument: Organic groups: Groups */
  $handler->display->display_options['arguments']['group_nid']['id'] = 'group_nid';
  $handler->display->display_options['arguments']['group_nid']['table'] = 'og_ancestry';
  $handler->display->display_options['arguments']['group_nid']['field'] = 'group_nid';
  $handler->display->display_options['arguments']['group_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['group_nid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['group_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['group_nid']['validate_type'] = 'node';
  $handler->display->display_options['arguments']['group_nid']['validate_options']['types'] = array(
    'group' => 'group',
  );
  $handler->display->display_options['arguments']['group_nid']['validate_options']['access'] = 1;
  $handler->display->display_options['arguments']['group_nid']['validate_fail'] = 'empty';
  $handler->display->display_options['arguments']['group_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['group_nid']['not'] = 0;
  /* Filter: Node: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'blog' => 'blog',
  );
  /* Filter: Node translation: Source translation */
  $handler->display->display_options['filters']['source_translation']['id'] = 'source_translation';
  $handler->display->display_options['filters']['source_translation']['table'] = 'node';
  $handler->display->display_options['filters']['source_translation']['field'] = 'source_translation';

  /* Display: Group feed */
  $handler = $view->new_display('feed', 'Group feed', 'feed_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['style_options']['mission_description'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Argument: Organic groups: Groups */
  $handler->display->display_options['arguments']['group_nid']['id'] = 'group_nid';
  $handler->display->display_options['arguments']['group_nid']['table'] = 'og_ancestry';
  $handler->display->display_options['arguments']['group_nid']['field'] = 'group_nid';
  $handler->display->display_options['arguments']['group_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['group_nid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['group_nid']['title'] = 'All stories from %1';
  $handler->display->display_options['arguments']['group_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['group_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['group_nid']['validate_type'] = 'node';
  $handler->display->display_options['arguments']['group_nid']['validate_options']['types'] = array(
    'group' => 'group',
  );
  $handler->display->display_options['arguments']['group_nid']['validate_options']['access'] = 1;
  $handler->display->display_options['arguments']['group_nid']['validate_fail'] = 'empty';
  $handler->display->display_options['arguments']['group_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['group_nid']['not'] = 0;
  $handler->display->display_options['path'] = 'node/%/feed';
  $handler->display->display_options['displays'] = array(
    'page_1' => 'page_1',
    'vojo_group_browse_stories_pane' => 'vojo_group_browse_stories_pane',
    'default' => 0,
    'panel_pane_1' => 0,
  );

  /* Display: Vojo Group Browse Stories Page */
  $handler = $view->new_display('page', 'Vojo Group Browse Stories Page', 'page_1');
  $handler->display->display_options['path'] = 'node/%/browse';

  /* Display: Vojo Group Browse Stories Pane */
  $handler = $view->new_display('panel_pane', 'Vojo Group Browse Stories Pane', 'vojo_group_browse_stories_pane');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '21';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['pane_title'] = 'Vojo Browse Stories Pane';
  $handler->display->display_options['pane_category']['name'] = 'Vojo';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'group_nid' => array(
      'type' => 'panel',
      'context' => 'node.termpath-raw',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Organic groups: Groups',
    ),
  );

  /* Display: Vojo Users Browse Stories Pane */
  $handler = $view->new_display('panel_pane', 'Vojo Users Browse Stories Pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Argument: User: Name */
  $handler->display->display_options['arguments']['name']['id'] = 'name';
  $handler->display->display_options['arguments']['name']['table'] = 'users';
  $handler->display->display_options['arguments']['name']['field'] = 'name';
  $handler->display->display_options['arguments']['name']['default_action'] = 'default';
  $handler->display->display_options['arguments']['name']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['name']['title'] = '1%\'s Blog';
  $handler->display->display_options['arguments']['name']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['name']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['name']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['name']['validate_type'] = 'user';
  $handler->display->display_options['arguments']['name']['validate_options']['type'] = 'either';
  $handler->display->display_options['arguments']['name']['validate_options']['restrict_roles'] = 0;
  $handler->display->display_options['arguments']['name']['glossary'] = 0;
  $handler->display->display_options['arguments']['name']['ignorecase'] = 0;
  $handler->display->display_options['arguments']['name']['limit'] = '0';
  $handler->display->display_options['arguments']['name']['transform_dash'] = 0;
  $handler->display->display_options['arguments']['name']['break_phrase'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter: Node: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['pane_title'] = 'Vojo Blogger User\'s Stories Pane';
  $handler->display->display_options['pane_category']['name'] = 'Vojo';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'uid' => array(
      'type' => 'panel',
      'context' => 'node.termpath-raw',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'User: Uid',
    ),
  );

  /* Display: Prev next links */
  $handler = $view->new_display('panel_pane', 'Prev next links', 'prev_next_links');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Node: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['path']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['path']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['path']['alter']['external'] = 0;
  $handler->display->display_options['fields']['path']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['path']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['path']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['path']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['path']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['path']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['path']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['path']['alter']['html'] = 0;
  $handler->display->display_options['fields']['path']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['path']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['path']['hide_empty'] = 0;
  $handler->display->display_options['fields']['path']['empty_zero'] = 0;
  $handler->display->display_options['fields']['path']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['path']['absolute'] = 0;
  /* Field: Node: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Date';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_class'] = 'vojo-story-created';
  $handler->display->display_options['fields']['created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'n/j/Y';
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Node: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'node_revisions';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Story';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '90';
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 1;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 1;
  /* Field: Content: Image (field_image) */
  $handler->display->display_options['fields']['field_image_fid']['id'] = 'field_image_fid';
  $handler->display->display_options['fields']['field_image_fid']['table'] = 'node_data_field_image';
  $handler->display->display_options['fields']['field_image_fid']['field'] = 'field_image_fid';
  $handler->display->display_options['fields']['field_image_fid']['label'] = 'Image';
  $handler->display->display_options['fields']['field_image_fid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['label_type'] = 'custom';
  $handler->display->display_options['fields']['field_image_fid']['format'] = 'url_plain';
  $handler->display->display_options['fields']['field_image_fid']['multiple']['group'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['multiple']['multiple_reversed'] = 0;
  /* Field: Content: Audio recorder (field_audio_recorder) */
  $handler->display->display_options['fields']['field_audio_recorder_fid']['id'] = 'field_audio_recorder_fid';
  $handler->display->display_options['fields']['field_audio_recorder_fid']['table'] = 'node_data_field_audio_recorder';
  $handler->display->display_options['fields']['field_audio_recorder_fid']['field'] = 'field_audio_recorder_fid';
  $handler->display->display_options['fields']['field_audio_recorder_fid']['label'] = 'Audio';
  $handler->display->display_options['fields']['field_audio_recorder_fid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_audio_recorder_fid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_audio_recorder_fid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_audio_recorder_fid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_audio_recorder_fid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_audio_recorder_fid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_audio_recorder_fid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_audio_recorder_fid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_audio_recorder_fid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_audio_recorder_fid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_audio_recorder_fid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_audio_recorder_fid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_audio_recorder_fid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_audio_recorder_fid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_audio_recorder_fid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_audio_recorder_fid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_audio_recorder_fid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_audio_recorder_fid']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_audio_recorder_fid']['label_type'] = 'custom';
  $handler->display->display_options['fields']['field_audio_recorder_fid']['format'] = 'url_plain';
  /* Field: Upload: Attached files */
  $handler->display->display_options['fields']['upload_fid']['id'] = 'upload_fid';
  $handler->display->display_options['fields']['upload_fid']['table'] = 'node';
  $handler->display->display_options['fields']['upload_fid']['field'] = 'upload_fid';
  $handler->display->display_options['fields']['upload_fid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['upload_fid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['upload_fid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['upload_fid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['upload_fid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['upload_fid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['upload_fid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['upload_fid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['upload_fid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['upload_fid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['upload_fid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['upload_fid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['upload_fid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['upload_fid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['upload_fid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['upload_fid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['upload_fid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['upload_fid']['link_to_file'] = 0;
  $handler->display->display_options['fields']['upload_fid']['only_listed'] = 0;
  $handler->display->display_options['path'] = 'groups/export';
  $translatables['vojo_group_browse_stories'] = array(
    t('Defaults'),
    t('All Stories'),
    t('more'),
    t('Apply'),
    t('Restablecer'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Nid'),
    t('Story is mapped'),
    t('view story'),
    t('node/[nid]'),
    t('<h3>[title]</h3>
<p>[body]</p>'),
    t('All'),
    t('Group feed'),
    t('All stories from %1'),
    t('Vojo Group Browse Stories Page'),
    t('Vojo Group Browse Stories Pane'),
    t('Vojo Browse Stories Pane'),
    t('Vojo'),
    t('Vojo Users Browse Stories Pane'),
    t('1%\'s Blog'),
    t('Vojo Blogger User\'s Stories Pane'),
    t('Prev next links'),
    t('View panes'),
    t('Data export'),
    t('Path'),
    t('Date'),
    t('Title'),
    t('Story'),
    t('Image'),
    t('Audio'),
    t('Attached files'),
  );

  $views[$view->name] = $view;

  // Exported view: vojo_group_featured_stories
  $view = new view;
  $view->name = 'vojo_group_featured_stories';
  $view->description = 'Multimedia centered listing of featured stories';
  $view->tag = 'vojo';
  $view->base_table = 'node';
  $view->human_name = 'Vojo Group Featured Stories';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Featured Stories';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Restablecer';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 1;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['empty'] = FALSE;
  $handler->display->display_options['footer']['area']['content'] = '<a id="vojo-slide-prev">Previous slide</a> <a id="vojo-slide-next">Next slide</a>';
  $handler->display->display_options['footer']['area']['format'] = '1';
  $handler->display->display_options['footer']['area']['tokenize'] = 0;
  /* Field: Node: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Content: Image (field_image) */
  $handler->display->display_options['fields']['field_image_fid']['id'] = 'field_image_fid';
  $handler->display->display_options['fields']['field_image_fid']['table'] = 'node_data_field_image';
  $handler->display->display_options['fields']['field_image_fid']['field'] = 'field_image_fid';
  $handler->display->display_options['fields']['field_image_fid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_image_fid']['format'] = 'group_featured_stories_linked';
  $handler->display->display_options['fields']['field_image_fid']['multiple']['group'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['multiple']['multiple_number'] = '1';
  $handler->display->display_options['fields']['field_image_fid']['multiple']['multiple_reversed'] = 0;
  /* Field: Node: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_class'] = 'vojo-story-created';
  $handler->display->display_options['fields']['created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'n/j/Y';
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Formated title */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Formated title';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<h2>[title]</h2>';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_wrapper_class'] = 'vojo-story-text';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  /* Field: Node: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'node_revisions';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '300';
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 1;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 1;
  /* Sort criterion: Node: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Node: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Argument: Organic groups: Groups */
  $handler->display->display_options['arguments']['group_nid']['id'] = 'group_nid';
  $handler->display->display_options['arguments']['group_nid']['table'] = 'og_ancestry';
  $handler->display->display_options['arguments']['group_nid']['field'] = 'group_nid';
  $handler->display->display_options['arguments']['group_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['group_nid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['group_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['group_nid']['validate_type'] = 'node';
  $handler->display->display_options['arguments']['group_nid']['validate_options']['types'] = array(
    'group' => 'group',
  );
  $handler->display->display_options['arguments']['group_nid']['validate_options']['access'] = 1;
  $handler->display->display_options['arguments']['group_nid']['validate_fail'] = 'empty';
  $handler->display->display_options['arguments']['group_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['group_nid']['not'] = 0;
  /* Filter: Node: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'blog' => 'blog',
  );
  /* Filter: Node translation: Source translation */
  $handler->display->display_options['filters']['source_translation']['id'] = 'source_translation';
  $handler->display->display_options['filters']['source_translation']['table'] = 'node';
  $handler->display->display_options['filters']['source_translation']['field'] = 'source_translation';
  /* Filter: Node: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';

  /* Display: Vojo Group Featured Stories Pane */
  $handler = $view->new_display('panel_pane', 'Vojo Group Featured Stories Pane', 'vojo_group_featured_stories_pane');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['pane_title'] = 'Vojo: Group Featured Stories Pane';
  $handler->display->display_options['pane_category']['name'] = 'Vojo';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'group_nid' => array(
      'type' => 'panel',
      'context' => 'node.termpath-raw',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Organic groups: Groups',
    ),
  );
  $translatables['vojo_group_featured_stories'] = array(
    t('Defaults'),
    t('Featured Stories'),
    t('more'),
    t('Apply'),
    t('Restablecer'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Text area'),
    t('<a id="vojo-slide-prev">Previous slide</a> <a id="vojo-slide-next">Next slide</a>'),
    t('Nid'),
    t('node/[nid]'),
    t('<h2>[title]</h2>'),
    t('All'),
    t('Vojo Group Featured Stories Pane'),
    t('Vojo: Group Featured Stories Pane'),
    t('Vojo'),
  );

  $views[$view->name] = $view;

  // Exported view: vojo_group_stories_map
  $view = new view;
  $view->name = 'vojo_group_stories_map';
  $view->description = 'Map all the stories in a group';
  $view->tag = 'vojo';
  $view->base_table = 'node';
  $view->human_name = 'Vojo Group Stories Map';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Restablecer';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Empty text: No mapped stories */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['ui_name'] = 'No mapped stories';
  $handler->display->display_options['empty']['area']['label'] = '';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = '<div class="map-overlay"><p><?php print t("This group has no stories with location information yet. If you\'re a group member, edit your stories and add location information and they\'ll appear on this map."); ?></p>
<p> <?php print t(\'You can also post stories directly to the map from your phone: in the body of your message, use the "%" sign followed by an address or location (for example, "% 123 main st., cambridge, MA" or "%Macarthur Park, Los Angeles").\'); ?> </p></div>';
  $handler->display->display_options['empty']['area']['format'] = '4';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: Organic groups: Group node (post) */
  $handler->display->display_options['relationships']['group_nid']['id'] = 'group_nid';
  $handler->display->display_options['relationships']['group_nid']['table'] = 'og_ancestry';
  $handler->display->display_options['relationships']['group_nid']['field'] = 'group_nid';
  $handler->display->display_options['relationships']['group_nid']['required'] = 1;
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Image (field_image) */
  $handler->display->display_options['fields']['field_image_fid']['id'] = 'field_image_fid';
  $handler->display->display_options['fields']['field_image_fid']['table'] = 'node_data_field_image';
  $handler->display->display_options['fields']['field_image_fid']['field'] = 'field_image_fid';
  $handler->display->display_options['fields']['field_image_fid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image_fid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_image_fid']['format'] = '160px_linked';
  $handler->display->display_options['fields']['field_image_fid']['multiple']['group'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['multiple']['multiple_number'] = '1';
  $handler->display->display_options['fields']['field_image_fid']['multiple']['multiple_from'] = '0';
  $handler->display->display_options['fields']['field_image_fid']['multiple']['multiple_reversed'] = 0;
  /* Field: Node: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['external'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['view_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_node']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['view_node']['text'] = 'Listen to audio';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_audio_fid']['id'] = 'field_audio_fid';
  $handler->display->display_options['fields']['field_audio_fid']['table'] = 'node_data_field_audio';
  $handler->display->display_options['fields']['field_audio_fid']['field'] = 'field_audio_fid';
  $handler->display->display_options['fields']['field_audio_fid']['label'] = 'Voice';
  $handler->display->display_options['fields']['field_audio_fid']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_audio_fid']['alter']['text'] = '<div class="vojo-has-audio-wrapper"><span class="stories-audio-icon">Audio</span> [view_node]</div>';
  $handler->display->display_options['fields']['field_audio_fid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_audio_fid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_audio_fid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_audio_fid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_audio_fid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_audio_fid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_audio_fid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_audio_fid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_audio_fid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_audio_fid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_audio_fid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_audio_fid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_audio_fid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_audio_fid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_audio_fid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_audio_fid']['hide_alter_empty'] = 1;
  /* Field: Node: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'node_revisions';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '300';
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 1;
  /* Field: Popup body&#039;s source */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['ui_name'] = 'Popup body\'s source';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['created']['alter']['text'] = '[field_image_fid]
[created]
[body]
[field_audio_fid]';
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_type'] = 'div';
  $handler->display->display_options['fields']['created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'n/j/Y';
  /* Field: Content: Map (field_map) */
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['id'] = 'field_map_openlayers_wkt';
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['table'] = 'node_data_field_map';
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['field'] = 'field_map_openlayers_wkt';
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['label'] = 'Map';
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['format'] = 'openlayers_wkt';
  /* Sort criterion: Node: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Argument: Organic groups: Groups */
  $handler->display->display_options['arguments']['group_nid']['id'] = 'group_nid';
  $handler->display->display_options['arguments']['group_nid']['table'] = 'og_ancestry';
  $handler->display->display_options['arguments']['group_nid']['field'] = 'group_nid';
  $handler->display->display_options['arguments']['group_nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['group_nid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['group_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['group_nid']['validate_type'] = 'node';
  $handler->display->display_options['arguments']['group_nid']['validate_options']['types'] = array(
    'group' => 'group',
  );
  $handler->display->display_options['arguments']['group_nid']['validate_options']['access'] = 0;
  $handler->display->display_options['arguments']['group_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['group_nid']['not'] = 0;
  /* Filter: Node: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'blog' => 'blog',
  );

  /* Display: Vojo Group Stories OL Data */
  $handler = $view->new_display('openlayers', 'Vojo Group Stories OL Data', 'vojo_group_stories_map_ol_data');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_data';
  $handler->display->display_options['style_options']['data_source'] = array(
    'value' => 'openlayers_wkt',
    'other_lat' => 'title',
    'other_lon' => 'title',
    'openlayers_wkt' => 'field_map_openlayers_wkt',
    'other_top' => 'title',
    'other_right' => 'title',
    'other_bottom' => 'title',
    'other_left' => 'title',
    'name_field' => 'title',
    'keep_orig_name_field' => 1,
    'description_field' => 'created',
    'keep_orig_desc_field' => 1,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;

  /* Display: Vojo Group Stories Map Page */
  $handler = $view->new_display('page', 'Vojo Group Stories Map Page', 'vojo_group_stories_map_page');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_map';
  $handler->display->display_options['style_options']['preset'] = 'vojo_group_all_stories_preset';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'node/%/map';

  /* Display: Vojo Group Stories Map Pane */
  $handler = $view->new_display('panel_pane', 'Vojo Group Stories Map Pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_map';
  $handler->display->display_options['style_options']['preset'] = 'vojo_group_all_stories_preset';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['argument_input'] = array(
    'group_nid' => array(
      'type' => 'none',
      'context' => 'node.termpath-raw',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Grupos: Grupos',
    ),
  );
  $translatables['vojo_group_stories_map'] = array(
    t('Defaults'),
    t('more'),
    t('Apply'),
    t('Restablecer'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<div class="map-overlay"><p><?php print t("This group has no stories with location information yet. If you\'re a group member, edit your stories and add location information and they\'ll appear on this map."); ?></p>
<p> <?php print t(\'You can also post stories directly to the map from your phone: in the body of your message, use the "%" sign followed by an address or location (for example, "% 123 main st., cambridge, MA" or "%Macarthur Park, Los Angeles").\'); ?> </p></div>'),
    t('Group node (post)'),
    t('Listen to audio'),
    t('Voice'),
    t('<div class="vojo-has-audio-wrapper"><span class="stories-audio-icon">Audio</span> [view_node]</div>'),
    t('Post date'),
    t('[field_image_fid]
[created]
[body]
[field_audio_fid]'),
    t('Map'),
    t('All'),
    t('Vojo Group Stories OL Data'),
    t('Vojo Group Stories Map Page'),
    t('Vojo Group Stories Map Pane'),
    t('View panes'),
  );

  $views[$view->name] = $view;

  // Exported view: vojo_group_stories_voip
  $view = new view;
  $view->name = 'vojo_group_stories_voip';
  $view->description = '';
  $view->tag = 'vojo';
  $view->base_table = 'node';
  $view->human_name = 'Vojo Group Stories Voip';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'All Stories';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Restablecer';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = 0;
  $handler->display->display_options['row_options']['comments'] = 0;
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Sort criterion: Node: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Node: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Argument: Organic groups: Groups */
  $handler->display->display_options['arguments']['group_nid']['id'] = 'group_nid';
  $handler->display->display_options['arguments']['group_nid']['table'] = 'og_ancestry';
  $handler->display->display_options['arguments']['group_nid']['field'] = 'group_nid';
  $handler->display->display_options['arguments']['group_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['group_nid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['group_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['group_nid']['validate_type'] = 'node';
  $handler->display->display_options['arguments']['group_nid']['validate_options']['types'] = array(
    'group' => 'group',
  );
  $handler->display->display_options['arguments']['group_nid']['validate_options']['access'] = 1;
  $handler->display->display_options['arguments']['group_nid']['validate_fail'] = 'empty';
  $handler->display->display_options['arguments']['group_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['group_nid']['not'] = 0;
  /* Filter: Node: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'blog' => 'blog',
  );

  /* Display: Vojo Group Stories VoIP */
  $handler = $view->new_display('voipviews', 'Vojo Group Stories VoIP', 'vojo_group_stories_voip');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'voipviews_list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'voipviews_row_ivr';
  $handler->display->display_options['row_options']['ivr_prompt_intro'] = 'Press 1 to hear another story, or # to go back to the main menu';
  $handler->display->display_options['row_options']['ivr_invalid_msg'] = 'Sorry, that\'s isn\'t a valid option';
  $handler->display->display_options['row_options']['ivr_no_input_msg'] = 'No option detected';
  $handler->display->display_options['row_options']['ivr_options'] = array(
    'title' => '',
    'name' => '',
    'php' => '',
    'ivr_next_row' => '1',
    'ivr_return' => '#',
  );
  $handler->display->display_options['row_options']['ivr_prompt'] = array(
    '\\0' => '',
    '\\1' => '',
    '\\2' => '',
    '\\3' => '',
    '\\4' => '',
    '\\5' => '',
    '\\6' => '',
    '\\7' => '',
    '\\8' => '',
    '\\9' => '',
    '\\*' => '',
    '\\#' => '',
  );
  $handler->display->display_options['row_options']['ivr_notfirst'] = array(
    '\\0' => 0,
    '\\1' => 0,
    '\\2' => 0,
    '\\3' => 0,
    '\\4' => 0,
    '\\5' => 0,
    '\\6' => 0,
    '\\7' => 0,
    '\\8' => 0,
    '\\9' => 0,
    '\\*' => 0,
    '\\#' => 0,
  );
  $handler->display->display_options['row_options']['ivr_notlast'] = array(
    '\\0' => 0,
    '\\1' => 1,
    '\\2' => 0,
    '\\3' => 0,
    '\\4' => 0,
    '\\5' => 0,
    '\\6' => 0,
    '\\7' => 0,
    '\\8' => 0,
    '\\9' => 0,
    '\\*' => 0,
    '\\#' => 0,
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'This story is called';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 1;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'This story was created by ';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 1;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_type'] = '0';
  $handler->display->display_options['fields']['name']['element_label_type'] = '0';
  $handler->display->display_options['fields']['name']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['name']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['name']['link_to_user'] = 0;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  /* Field: PHP: Cleaned Content */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'PHP: Cleaned Content';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php']['element_type'] = '0';
  $handler->display->display_options['fields']['php']['element_label_type'] = '0';
  $handler->display->display_options['fields']['php']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['php']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['php']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['php']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_setup'] = 'function get_audio_extensions(){

  return array(\'wav\',\'mp3\');

}';
  $handler->display->display_options['fields']['php']['php_value'] = '// the list of allowed extensions (dictated by what Tropo supports for now)

$audio_extensions = get_audio_extensions();

// clean text body (fallback if no audio)

$content = strip_tags($row->body);

$content = str_replace("\\n"," ",$content);

$content = str_replace("\\r"," ",$content);

//$content = html_entity_decode($content); // this doesn\'t work for some reason

// play any audio attached, if none then play text

$result = db_query(\'SELECT * FROM {files} f INNER JOIN {upload} r ON f.fid = r.fid WHERE r.vid = %d ORDER BY r.weight, f.fid\', $row->upload_fid);

while ($file = db_fetch_array($result)) {

  $extension = substr($file[\'filepath\'], -3);

  if( in_array($extension, $audio_extensions) ){

    $content = file_create_url($file[\'filepath\']);

  }

}

if(strlen($content)==0) {

  $content = "This story has no audio or text";

}

return $content;';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: VoIP: IVR: Goto next */
  $handler->display->display_options['fields']['ivr_next_row']['id'] = 'ivr_next_row';
  $handler->display->display_options['fields']['ivr_next_row']['table'] = 'voipviews';
  $handler->display->display_options['fields']['ivr_next_row']['field'] = 'ivr_next_row';
  $handler->display->display_options['fields']['ivr_next_row']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['ivr_next_row']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['ivr_next_row']['hide_alter_empty'] = 1;
  /* Field: VoIP: IVR: Return */
  $handler->display->display_options['fields']['ivr_return']['id'] = 'ivr_return';
  $handler->display->display_options['fields']['ivr_return']['table'] = 'voipviews';
  $handler->display->display_options['fields']['ivr_return']['field'] = 'ivr_return';
  $handler->display->display_options['fields']['ivr_return']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['ivr_return']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['ivr_return']['hide_alter_empty'] = 1;
  /* Field: Node: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'node_revisions';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '90';
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['body']['hide_empty'] = 1;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 1;
  /* Field: Upload: Attached files */
  $handler->display->display_options['fields']['upload_fid']['id'] = 'upload_fid';
  $handler->display->display_options['fields']['upload_fid']['table'] = 'node';
  $handler->display->display_options['fields']['upload_fid']['field'] = 'upload_fid';
  $handler->display->display_options['fields']['upload_fid']['label'] = '';
  $handler->display->display_options['fields']['upload_fid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['upload_fid']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['upload_fid']['alter']['text'] = '[upload_fid-url]';
  $handler->display->display_options['fields']['upload_fid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['upload_fid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['upload_fid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['upload_fid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['upload_fid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['upload_fid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['upload_fid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['upload_fid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['upload_fid']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['upload_fid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['upload_fid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['upload_fid']['element_type'] = '0';
  $handler->display->display_options['fields']['upload_fid']['element_label_type'] = '0';
  $handler->display->display_options['fields']['upload_fid']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['upload_fid']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['upload_fid']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['upload_fid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['upload_fid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['upload_fid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['upload_fid']['link_to_file'] = 0;
  $handler->display->display_options['fields']['upload_fid']['only_listed'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter: Node: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'blog' => 'blog',
  );
  /* Filter: PHP: Attachments = Audio or text */
  $handler->display->display_options['filters']['php']['id'] = 'php';
  $handler->display->display_options['filters']['php']['table'] = 'views';
  $handler->display->display_options['filters']['php']['field'] = 'php';
  $handler->display->display_options['filters']['php']['ui_name'] = 'PHP: Attachments = Audio or text';
  $handler->display->display_options['filters']['php']['use_php_setup'] = 0;
  $handler->display->display_options['filters']['php']['php_filter'] = '// the list of allowed extensions (dictated by what Tropo supports for now)

$audio_extensions =  array(\'wav\',\'mp3\');

// return TRUE to _REMOVE_ nodes

$content = $row->body;

$result = db_query(\'SELECT * FROM {files} f INNER JOIN {upload} r ON f.fid = r.fid WHERE r.vid = %d ORDER BY r.weight, f.fid\', $row->upload_fid);

while ($file = db_fetch_array($result)) {

  $extension = substr($file[\'filepath\'], -3);

  if( in_array($extension, $audio_extensions) ){

    $content = file_create_url($file[\'filepath\']);

  }

}

if(strlen($content)==0) {

  return true;

}

return false;

';
  $translatables['vojo_group_stories_voip'] = array(
    t('Defaults'),
    t('All Stories'),
    t('more'),
    t('Apply'),
    t('Restablecer'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
    t('Vojo Group Stories VoIP'),
    t('This story is called'),
    t('This story was created by '),
    t('node/[nid]'),
    t('[upload_fid-url]'),
  );

  $views[$view->name] = $view;

  // Exported view: vojo_node_map
  $view = new view;
  $view->name = 'vojo_node_map';
  $view->description = '';
  $view->tag = 'vojo';
  $view->base_table = 'node';
  $view->human_name = 'Vojo Node Map';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Restablecer';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Content: Map (field_map) */
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['id'] = 'field_map_openlayers_wkt';
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['table'] = 'node_data_field_map';
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['field'] = 'field_map_openlayers_wkt';
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['format'] = 'openlayers_wkt';
  /* Argument: Node: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['argument'] = '10055';
  $handler->display->display_options['arguments']['nid']['validate_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'blog' => 'blog',
  );
  $handler->display->display_options['arguments']['nid']['validate_options']['access'] = 0;
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  /* Filter: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'blog' => 'blog',
  );
  /* Filter: Node: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';

  /* Display: Vojo Node Map OL Data */
  $handler = $view->new_display('openlayers', 'Vojo Node Map OL Data', 'vojo_node_map_ol_data');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_data';
  $handler->display->display_options['style_options']['data_source'] = array(
    'value' => 'openlayers_wkt',
    'other_lat' => 'latitude',
    'other_lon' => 'longitude',
    'openlayers_wkt' => 'field_map_openlayers_wkt',
    'other_top' => 'title',
    'other_right' => 'title',
    'other_bottom' => 'title',
    'other_left' => 'title',
    'name_field' => 'title',
    'keep_orig_name_field' => 1,
    'description_field' => '',
    'keep_orig_desc_field' => 1,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;

  /* Display: Vojo Node Map Pane */
  $handler = $view->new_display('panel_pane', 'Vojo Node Map Pane', 'vojo_node_map_ol_map_pane');
  $handler->display->display_options['display_description'] = 'A map of story node';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_map';
  $handler->display->display_options['style_options']['preset'] = 'vojo_story_preset';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['pane_title'] = 'Vojo Node Map Pane';
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Node: Nid',
    ),
  );
  $translatables['vojo_node_map'] = array(
    t('Defaults'),
    t('more'),
    t('Apply'),
    t('Restablecer'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Title'),
    t('All'),
    t('Vojo Node Map OL Data'),
    t('Vojo Node Map Pane'),
    t('A map of story node'),
    t('View panes'),
  );

  $views[$view->name] = $view;

  // Exported view: vojo_og
  $view = new view;
  $view->name = 'vojo_og';
  $view->description = 'Vojo Groups directory';
  $view->tag = 'vojo';
  $view->base_table = 'node';
  $view->human_name = 'Vojo OG';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'All Groups';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'view all groups';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Restablecer';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = 90;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'item-row';
  $handler->display->display_options['style_options']['class'] = 'group-list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Empty text: Global: Text area */
  $handler->display->display_options['empty']['text']['id'] = 'area';
  $handler->display->display_options['empty']['text']['table'] = 'views';
  $handler->display->display_options['empty']['text']['field'] = 'area';
  $handler->display->display_options['empty']['text']['label'] = '';
  $handler->display->display_options['empty']['text']['empty'] = FALSE;
  $handler->display->display_options['empty']['text']['content'] = 'No hay grupos';
  $handler->display->display_options['empty']['text']['format'] = '1';
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Organic groups: Group: Description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'og';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = '';
  $handler->display->display_options['fields']['description']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['description']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['description']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['description']['alter']['external'] = 0;
  $handler->display->display_options['fields']['description']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['description']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['description']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['description']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['description']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['description']['alter']['html'] = 0;
  $handler->display->display_options['fields']['description']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['description']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['description']['hide_empty'] = 0;
  $handler->display->display_options['fields']['description']['empty_zero'] = 0;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Administrador';
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  /* Field: Organic groups: Group: Post count */
  $handler->display->display_options['fields']['post_count']['id'] = 'post_count';
  $handler->display->display_options['fields']['post_count']['table'] = 'og';
  $handler->display->display_options['fields']['post_count']['field'] = 'post_count';
  $handler->display->display_options['fields']['post_count']['label'] = '';
  $handler->display->display_options['fields']['post_count']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['post_count']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['post_count']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['post_count']['alter']['external'] = 0;
  $handler->display->display_options['fields']['post_count']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['post_count']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['post_count']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['post_count']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['post_count']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['post_count']['alter']['html'] = 0;
  $handler->display->display_options['fields']['post_count']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['post_count']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['post_count']['hide_empty'] = 0;
  $handler->display->display_options['fields']['post_count']['empty_zero'] = 0;
  $handler->display->display_options['fields']['post_count']['format_plural'] = 0;
  /* Field: Organic groups: Group: Members count */
  $handler->display->display_options['fields']['member_count']['id'] = 'member_count';
  $handler->display->display_options['fields']['member_count']['table'] = 'og';
  $handler->display->display_options['fields']['member_count']['field'] = 'member_count';
  $handler->display->display_options['fields']['member_count']['label'] = '';
  $handler->display->display_options['fields']['member_count']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['member_count']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['member_count']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['member_count']['alter']['external'] = 0;
  $handler->display->display_options['fields']['member_count']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['member_count']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['member_count']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['member_count']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['member_count']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['member_count']['alter']['html'] = 0;
  $handler->display->display_options['fields']['member_count']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['member_count']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['member_count']['hide_empty'] = 0;
  $handler->display->display_options['fields']['member_count']['empty_zero'] = 0;
  $handler->display->display_options['fields']['member_count']['format_plural'] = 0;
  /* Field: Node: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'M y';
  /* Field: Organic groups: Group: Join link */
  $handler->display->display_options['fields']['subscribe']['id'] = 'subscribe';
  $handler->display->display_options['fields']['subscribe']['table'] = 'og';
  $handler->display->display_options['fields']['subscribe']['field'] = 'subscribe';
  $handler->display->display_options['fields']['subscribe']['label'] = 'Join Link';
  /* Field: Node: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Content: Group logo (field_group_logo) */
  $handler->display->display_options['fields']['field_group_logo_fid']['id'] = 'field_group_logo_fid';
  $handler->display->display_options['fields']['field_group_logo_fid']['table'] = 'node_data_field_group_logo';
  $handler->display->display_options['fields']['field_group_logo_fid']['field'] = 'field_group_logo_fid';
  $handler->display->display_options['fields']['field_group_logo_fid']['label'] = 'Group logo';
  $handler->display->display_options['fields']['field_group_logo_fid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_group_logo_fid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_group_logo_fid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_group_logo_fid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_group_logo_fid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_group_logo_fid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_group_logo_fid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_group_logo_fid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_group_logo_fid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_group_logo_fid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_group_logo_fid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_group_logo_fid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_group_logo_fid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_group_logo_fid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_group_logo_fid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_group_logo_fid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_group_logo_fid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_group_logo_fid']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_group_logo_fid']['format'] = 'group_logo_large_linked';
  /* Filter: Node: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter: Organic groups: Group types (all) */
  $handler->display->display_options['filters']['type_groups_all']['id'] = 'type_groups_all';
  $handler->display->display_options['filters']['type_groups_all']['table'] = 'og';
  $handler->display->display_options['filters']['type_groups_all']['field'] = 'type_groups_all';
  $handler->display->display_options['filters']['type_groups_all']['group'] = 0;
  $handler->display->display_options['filters']['type_groups_all']['expose']['operator'] = FALSE;
  /* Filter: Organic groups: Group: List in directory */
  $handler->display->display_options['filters']['directory']['id'] = 'directory';
  $handler->display->display_options['filters']['directory']['table'] = 'og';
  $handler->display->display_options['filters']['directory']['field'] = 'directory';
  $handler->display->display_options['filters']['directory']['value'] = 1;
  $handler->display->display_options['filters']['directory']['group'] = 0;
  $handler->display->display_options['filters']['directory']['expose']['operator'] = FALSE;

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = 20;
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['style_options']['mission_description'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Node: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['path'] = 'og/all/feed';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['empty'] = FALSE;
  $handler->display->display_options['header']['php']['php_output'] = '<p><?php if (user_access(\'create group content\')) { print l(t("Create new group"), \'node/add/group\', array(\'attributes\' => array(\'class\' => \'create-group-link\'))); } ?></p>';
  $handler->display->display_options['path'] = 'og/all';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Groups';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'primary-links';
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Groups';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'secondary-links';

  /* Display: Featured Groups */
  $handler = $view->new_display('panel_pane', 'Featured Groups', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Featured groups';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Nodequeue: Queue (name) */
  $handler->display->display_options['relationships']['nodequeue_rel_queue_name']['id'] = 'nodequeue_rel_queue_name';
  $handler->display->display_options['relationships']['nodequeue_rel_queue_name']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel_queue_name']['field'] = 'nodequeue_rel_queue_name';
  $handler->display->display_options['relationships']['nodequeue_rel_queue_name']['required'] = 0;
  $handler->display->display_options['relationships']['nodequeue_rel_queue_name']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel_queue_name']['names'] = array(
    'vojo_front_featured_groups' => 'vojo_front_featured_groups',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter: Node: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter: Organic groups: Group types (all) */
  $handler->display->display_options['filters']['type_groups_all']['id'] = 'type_groups_all';
  $handler->display->display_options['filters']['type_groups_all']['table'] = 'og';
  $handler->display->display_options['filters']['type_groups_all']['field'] = 'type_groups_all';
  $handler->display->display_options['filters']['type_groups_all']['group'] = 0;
  $handler->display->display_options['filters']['type_groups_all']['expose']['operator'] = FALSE;
  /* Filter: Organic groups: Group: List in directory */
  $handler->display->display_options['filters']['directory']['id'] = 'directory';
  $handler->display->display_options['filters']['directory']['table'] = 'og';
  $handler->display->display_options['filters']['directory']['field'] = 'directory';
  $handler->display->display_options['filters']['directory']['value'] = 1;
  $handler->display->display_options['filters']['directory']['group'] = 0;
  $handler->display->display_options['filters']['directory']['expose']['operator'] = FALSE;
  /* Filter: Nodequeue: In queue */
  $handler->display->display_options['filters']['in_queue']['id'] = 'in_queue';
  $handler->display->display_options['filters']['in_queue']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['filters']['in_queue']['field'] = 'in_queue';
  $handler->display->display_options['filters']['in_queue']['relationship'] = 'nodequeue_rel_queue_name';
  $handler->display->display_options['filters']['in_queue']['value'] = '1';
  $handler->display->display_options['pane_title'] = 'Front featured groups';
  $handler->display->display_options['pane_category']['name'] = 'Vojo';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 'path_override';
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['link_to_view'] = '0';
  $translatables['vojo_og'] = array(
    t('Defaults'),
    t('All Groups'),
    t('view all groups'),
    t('Apply'),
    t('Restablecer'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('No hay grupos'),
    t('Administrador'),
    t('.'),
    t(','),
    t('Created'),
    t('Join Link'),
    t('Nid'),
    t('Group logo'),
    t('Feed'),
    t('more'),
    t('Page'),
    t('PHP'),
    t('Featured Groups'),
    t('Featured groups'),
    t('queue'),
    t('Front featured groups'),
    t('Vojo'),
  );

  $views[$view->name] = $view;

  // Exported view: vojo_og_search
  $view = new view;
  $view->name = 'vojo_og_search';
  $view->description = 'Search within one group';
  $view->tag = 'vojo';
  $view->base_table = 'node';
  $view->human_name = 'Vojo Group Search';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Buscar';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'search content';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'input_required';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Buscar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Restablecer';
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = '1';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '21';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Empty text: Global: Text area */
  $handler->display->display_options['empty']['text']['id'] = 'area';
  $handler->display->display_options['empty']['text']['table'] = 'views';
  $handler->display->display_options['empty']['text']['field'] = 'area';
  $handler->display->display_options['empty']['text']['label'] = '';
  $handler->display->display_options['empty']['text']['empty'] = FALSE;
  $handler->display->display_options['empty']['text']['content'] = 'No posts found.';
  $handler->display->display_options['empty']['text']['format'] = '1';
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Node: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'node_revisions';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '150';
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_label_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  /* Sort criterion: Node: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Argument: Organic groups: Groups */
  $handler->display->display_options['arguments']['group_nid']['id'] = 'group_nid';
  $handler->display->display_options['arguments']['group_nid']['table'] = 'og_ancestry';
  $handler->display->display_options['arguments']['group_nid']['field'] = 'group_nid';
  $handler->display->display_options['arguments']['group_nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['group_nid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['group_nid']['title'] = '%1 Search Results';
  $handler->display->display_options['arguments']['group_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['group_nid']['default_argument_options']['argument'] = '10054';
  $handler->display->display_options['arguments']['group_nid']['validate_type'] = 'og_group_types';
  $handler->display->display_options['arguments']['group_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['group_nid']['not'] = 0;
  /* Argument: Search: Search Terms */
  $handler->display->display_options['arguments']['keys']['id'] = 'keys';
  $handler->display->display_options['arguments']['keys']['table'] = 'search_index';
  $handler->display->display_options['arguments']['keys']['field'] = 'keys';
  $handler->display->display_options['arguments']['keys']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['keys']['default_argument_type'] = 'fixed';
  /* Filter: Node: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['operator'] = 'required';
  $handler->display->display_options['filters']['keys']['group'] = 0;
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['optional'] = 0;
  $handler->display->display_options['filters']['keys']['expose']['remember'] = 1;

  /* Display: Vojo Group Search Page */
  $handler = $view->new_display('page', 'Vojo Group Search Page', 'vojo_group_search');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'node/%/search';
  $translatables['vojo_og_search'] = array(
    t('Defaults'),
    t('Buscar'),
    t('more'),
    t('Restablecer'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Select any filter and click on Apply to see results'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('No posts found.'),
    t('Title'),
    t('Body'),
    t('All'),
    t('%1 Search Results'),
    t('Vojo Group Search Page'),
  );

  $views[$view->name] = $view;

  // Exported view: vojo_submit_story
  $view = new view;
  $view->name = 'vojo_submit_story';
  $view->description = 'A skeleton hack to allow posting of stories to a group by the anonymous user';
  $view->tag = 'vojo';
  $view->base_table = 'node';
  $view->human_name = 'Vojo Story Submit';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Submit a Story */
  $handler = $view->new_display('default', 'Submit a Story', 'default');
  $handler->display->display_options['title'] = 'Enviar';
  $handler->display->display_options['access']['type'] = 'php';
  $handler->display->display_options['access']['php_access'] = 'return vojo_og_anon_create_access($_GET[\'gids\'][0]);';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Restablecer';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Argument: Organic groups: Groups */
  $handler->display->display_options['arguments']['group_nid']['id'] = 'group_nid';
  $handler->display->display_options['arguments']['group_nid']['table'] = 'og_ancestry';
  $handler->display->display_options['arguments']['group_nid']['field'] = 'group_nid';
  $handler->display->display_options['arguments']['group_nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['group_nid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['group_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['group_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['group_nid']['validate_type'] = 'og_group_types';
  $handler->display->display_options['arguments']['group_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['group_nid']['not'] = 0;

  /* Display: Vojo Story Submit Page */
  $handler = $view->new_display('page', 'Vojo Story Submit Page', 'vojo_story_submit_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Enviar';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['path'] = 'story/add';
  $handler->display->display_options['menu']['title'] = 'Cuéntanos';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-monterrey';

  /* Display: Vojo Node Blog Add Page */
  $handler = $view->new_display('page', 'Vojo Node Blog Add Page', 'page_1');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['path'] = 'node/add/blog';
  $translatables['vojo_submit_story'] = array(
    t('Submit a Story'),
    t('Enviar'),
    t('more'),
    t('Apply'),
    t('Restablecer'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Title'),
    t('All'),
    t('Vojo Story Submit Page'),
    t('Vojo Node Blog Add Page'),
  );

  $views[$view->name] = $view;

  // Exported view: vojo_tag_clouds
  $view = new view;
  $view->name = 'vojo_tag_clouds';
  $view->description = 'Provides a tag cloud for tags. ';
  $view->tag = 'vojo';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Restablecer';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = 1;
  $handler->display->display_options['row_options']['comments'] = 0;
  /* Field: Node: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Sort criterion: Node: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Node: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Argument: Taxonomy: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'term_node';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'summary desc';
  $handler->display->display_options['arguments']['tid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['title'] = 'Posts in %1';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['validate_type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['vids'] = array(
    1 => 0,
    2 => 0,
    6 => 0,
  );
  $handler->display->display_options['arguments']['tid']['validate_options']['transform'] = 0;
  $handler->display->display_options['arguments']['tid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['tid']['add_table'] = 0;
  $handler->display->display_options['arguments']['tid']['require_value'] = 0;
  $handler->display->display_options['arguments']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['arguments']['tid']['set_breadcrumb'] = 0;
  /* Filter: Node: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Etiquetas / Tags';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '16';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter: Taxonomy: Vocabulary */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['value'] = array(
    1 => 1,
  );
  $handler->display->display_options['filters']['vid']['expose']['operator'] = FALSE;
  $handler->display->display_options['block_description'] = 'Cloud: Tags for "Etiquetas"';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Argument: Taxonomy: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'term_node';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'summary desc';
  $handler->display->display_options['arguments']['tid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['title'] = 'Posts in %1';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['validate_type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['vids'] = array(
    1 => 0,
    2 => 0,
    6 => 0,
  );
  $handler->display->display_options['arguments']['tid']['validate_options']['transform'] = 0;
  $handler->display->display_options['arguments']['tid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['tid']['add_table'] = 0;
  $handler->display->display_options['arguments']['tid']['require_value'] = 0;
  $handler->display->display_options['arguments']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['arguments']['tid']['set_breadcrumb'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter: Taxonomy: Vocabulary */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['path'] = 'category/etiquetas';
  $translatables['vojo_tag_clouds'] = array(
    t('Defaults'),
    t('more'),
    t('Apply'),
    t('Restablecer'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Nid'),
    t('All'),
    t('Posts in %1'),
    t('Block'),
    t('Etiquetas / Tags'),
    t('Cloud: Tags for "Etiquetas"'),
    t('Page'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
  );

  $views[$view->name] = $view;

  // Exported view: vojo_term_browse_stories
  $view = new view;
  $view->name = 'vojo_term_browse_stories';
  $view->description = 'Multimedia centered listing of stories';
  $view->tag = 'vojo';
  $view->base_table = 'node';
  $view->human_name = 'Vojo Term Browse Stories';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['css_class'] = 'vojo-story-list view-vojo-group-browse-stories';
  $handler->display->display_options['link_display'] = 'page_1';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Restablecer';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '21';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 1;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  /* Footer: Global: PHP */
  $handler->display->display_options['footer']['php']['id'] = 'php';
  $handler->display->display_options['footer']['php']['table'] = 'views';
  $handler->display->display_options['footer']['php']['field'] = 'php';
  $handler->display->display_options['footer']['php']['label'] = '';
  $handler->display->display_options['footer']['php']['empty'] = FALSE;
  $handler->display->display_options['footer']['php']['php_output'] = '<?php print theme(\'feed_icon\', url(\'taxonomy/term/\' . $view->args[0] . \'/feed\')); ?>';
  /* Field: Node: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Content: Image (field_image) */
  $handler->display->display_options['fields']['field_image_fid']['id'] = 'field_image_fid';
  $handler->display->display_options['fields']['field_image_fid']['table'] = 'node_data_field_image';
  $handler->display->display_options['fields']['field_image_fid']['field'] = 'field_image_fid';
  $handler->display->display_options['fields']['field_image_fid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_image_fid']['format'] = 'browse_stories_linked';
  $handler->display->display_options['fields']['field_image_fid']['multiple']['group'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['multiple']['multiple_reversed'] = 0;
  /* Field: Story is mapped (openlayers_wkt) */
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['id'] = 'field_map_openlayers_wkt';
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['table'] = 'node_data_field_map';
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['field'] = 'field_map_openlayers_wkt';
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['ui_name'] = 'Story is mapped (openlayers_wkt)';
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['text'] = 'Story is mapped';
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['element_wrapper_class'] = 'vojo-story-mapped';
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_map_openlayers_wkt']['format'] = 'openlayers_wkt';
  /* Field: Inivisible view story link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['ui_name'] = 'Inivisible view story link';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['external'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['view_node']['element_wrapper_class'] = 'vojo-view-story';
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['view_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_node']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['view_node']['text'] = 'view story';
  /* Field: Node: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_class'] = 'vojo-story-created';
  $handler->display->display_options['fields']['created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'n/j/Y';
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Node: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'node_revisions';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['body']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '90';
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 1;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 1;
  /* Field: Formats title and body text as links */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Formats title and body text as links';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<h3>[title]</h3>
<p>[body]</p>';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_wrapper_class'] = 'vojo-story-text';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  /* Sort criterion: Node: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Node: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Argument: Taxonomy: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'term_node';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['title'] = '%1';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['tid']['validate_type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['transform'] = 0;
  $handler->display->display_options['arguments']['tid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['tid']['add_table'] = 0;
  $handler->display->display_options['arguments']['tid']['require_value'] = 0;
  $handler->display->display_options['arguments']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['arguments']['tid']['set_breadcrumb'] = 0;
  $handler->display->display_options['arguments']['tid']['use_synonym_for_summary_links'] = 0;
  /* Filter: Node: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'blog' => 'blog',
  );
  /* Filter: Node translation: Source translation */
  $handler->display->display_options['filters']['source_translation']['id'] = 'source_translation';
  $handler->display->display_options['filters']['source_translation']['table'] = 'node';
  $handler->display->display_options['filters']['source_translation']['field'] = 'source_translation';

  /* Display: Term feed */
  $handler = $view->new_display('feed', 'Term feed', 'vojo_term_browse_stories_feed');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['style_options']['mission_description'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'taxonomy/term/%/feed';
  $handler->display->display_options['displays'] = array(
    'page_1' => 'page_1',
    'default' => 0,
  );

  /* Display: Vojo Term Browse Stories Page */
  $handler = $view->new_display('page', 'Vojo Term Browse Stories Page', 'vojo_term_browse_stories_page');
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['path'] = 'taxonomy/term/%';
  $translatables['vojo_term_browse_stories'] = array(
    t('Defaults'),
    t('more'),
    t('Apply'),
    t('Restablecer'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Nid'),
    t('Story is mapped'),
    t('view story'),
    t('node/[nid]'),
    t('<h3>[title]</h3>
<p>[body]</p>'),
    t('All'),
    t('%1'),
    t('Term feed'),
    t('Vojo Term Browse Stories Page'),
  );

  $views[$view->name] = $view;

  return $views;
}
