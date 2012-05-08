<?php

/**
 * Implementation of hook_views_default_views().
 */
function vojo_feature_views_default_views() {
  $views = array();

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
  /* Field: Audio icon */
  $handler->display->display_options['fields']['field_audio_fid']['id'] = 'field_audio_fid';
  $handler->display->display_options['fields']['field_audio_fid']['table'] = 'node_data_field_audio';
  $handler->display->display_options['fields']['field_audio_fid']['field'] = 'field_audio_fid';
  $handler->display->display_options['fields']['field_audio_fid']['ui_name'] = 'Audio icon';
  $handler->display->display_options['fields']['field_audio_fid']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_audio_fid']['alter']['text'] = '<span class="stories-audio-icon">Audio</span>';
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
  $handler->display->display_options['fields']['field_audio_fid']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_audio_fid']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_audio_fid']['format'] = 'path_plain';
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

  /* Display: Browse Stories User Blog Page */
  $handler = $view->new_display('page', 'Browse Stories User Blog Page', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Stories Blog';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Argument: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['title'] = '%1\'s blog';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['code'] = 'arg(1);';
  $handler->display->display_options['arguments']['uid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['uid']['validate_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['validate_options']['type'] = 'name';
  $handler->display->display_options['arguments']['uid']['validate_options']['restrict_roles'] = 0;
  $handler->display->display_options['arguments']['uid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['uid']['not'] = 0;
  $handler->display->display_options['path'] = 'blogs/%';
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
    t('<span class="stories-audio-icon">Audio</span>'),
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
    t('Browse Stories User Blog Page'),
    t('Stories Blog'),
    t('%1\'s blog'),
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
  /* Field: Content: Voice (field_audio) */
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
  $handler->display->display_options['fields']['field_audio_fid']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_audio_fid']['format'] = 'path_plain';
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

  // Exported view: vojo_node_map
  $view = new view;
  $view->name = 'vojo_node_map';
  $view->description = '';
  $view->tag = 'Vojo';
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
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  $handler->display->display_options['fields']['post_count']['suffix'] = ' stories';
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
  $handler->display->display_options['fields']['member_count']['suffix'] = ' members';
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
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Content: Group logo (field_group_logo) */
  $handler->display->display_options['fields']['field_group_logo_fid']['id'] = 'field_group_logo_fid';
  $handler->display->display_options['fields']['field_group_logo_fid']['table'] = 'node_data_field_group_logo';
  $handler->display->display_options['fields']['field_group_logo_fid']['field'] = 'field_group_logo_fid';
  $handler->display->display_options['fields']['field_group_logo_fid']['label'] = 'Group logo';
  $handler->display->display_options['fields']['field_group_logo_fid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_group_logo_fid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_group_logo_fid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_group_logo_fid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_group_logo_fid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_group_logo_fid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_group_logo_fid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_group_logo_fid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_group_logo_fid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_group_logo_fid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_group_logo_fid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_group_logo_fid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_group_logo_fid']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_group_logo_fid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_group_logo_fid']['link_to_node'] = 1;
  $handler->display->display_options['fields']['field_group_logo_fid']['format'] = 'image_nodelink';
  $handler->display->display_options['path'] = 'all-groups';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Groups';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'primary-links';
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Groups';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $translatables['vojo_og'] = array(
    t('Defaults'),
    t('All Groups'),
    t('more'),
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
    t('Feed'),
    t('Page'),
    t(' stories'),
    t(' members'),
    t('Group logo'),
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

  // Exported view: vojo_tag_clouds
  $view = new view;
  $view->name = 'vojo_tag_clouds';
  $view->description = 'Provides a tag cloud for tags. ';
  $view->tag = '';
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
  $handler->display->display_options['arguments']['tid']['style_plugin'] = 'cloud_summary';
  $handler->display->display_options['arguments']['tid']['style_options']['count'] = 0;
  $handler->display->display_options['arguments']['tid']['style_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['style_options']['randomize'] = 1;
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
  $handler->display->display_options['arguments']['tid']['style_plugin'] = 'cloud_summary';
  $handler->display->display_options['arguments']['tid']['style_options']['count'] = 0;
  $handler->display->display_options['arguments']['tid']['style_options']['override'] = TRUE;
  $handler->display->display_options['arguments']['tid']['style_options']['items_per_page'] = '';
  $handler->display->display_options['arguments']['tid']['style_options']['randomize'] = 1;
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
    t('Reset'),
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

  return $views;
}
