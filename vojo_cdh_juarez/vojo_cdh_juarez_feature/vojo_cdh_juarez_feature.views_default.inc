<?php

/**
 * Implementation of hook_views_default_views().
 */
function vojo_cdh_juarez_feature_views_default_views() {
  $views = array();

  // Exported view: cdhj_all_stories
  $view = new view;
  $view->name = 'cdhj_all_stories';
  $view->description = 'List of all the stories in the CDH Juarez Group';
  $view->tag = 'CDH Juarez';
  $view->base_table = 'node';
  $view->human_name = 'CDH Juarez Stories';
  $view->core = 6;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Location: Latitude */
  $handler->display->display_options['fields']['latitude']['id'] = 'latitude';
  $handler->display->display_options['fields']['latitude']['table'] = 'location';
  $handler->display->display_options['fields']['latitude']['field'] = 'latitude';
  $handler->display->display_options['fields']['latitude']['exclude'] = TRUE;
  $handler->display->display_options['fields']['latitude']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['external'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['latitude']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['latitude']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['html'] = 0;
  $handler->display->display_options['fields']['latitude']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['latitude']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['latitude']['hide_empty'] = 0;
  $handler->display->display_options['fields']['latitude']['empty_zero'] = 0;
  /* Field: Location: Longitude */
  $handler->display->display_options['fields']['longitude']['id'] = 'longitude';
  $handler->display->display_options['fields']['longitude']['table'] = 'location';
  $handler->display->display_options['fields']['longitude']['field'] = 'longitude';
  $handler->display->display_options['fields']['longitude']['exclude'] = TRUE;
  $handler->display->display_options['fields']['longitude']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['external'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['longitude']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['longitude']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['html'] = 0;
  $handler->display->display_options['fields']['longitude']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['longitude']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['longitude']['hide_empty'] = 0;
  $handler->display->display_options['fields']['longitude']['empty_zero'] = 0;
  /* Field: Node: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'node_revisions';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
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
  $handler->display->display_options['arguments']['group_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['group_nid']['validate_type'] = 'og_group_types';
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

  /* Display: CDH Juarez Stories List Pane */
  $handler = $view->new_display('panel_pane', 'CDH Juarez Stories List Pane', 'cdhj_stories_pane');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Recent Reports';
  $handler->display->display_options['display_description'] = 'List the most recent stories in the CDH Juarez Group';
  $handler->display->display_options['pane_title'] = 'CDH Juarez Stories List Pane';
  $handler->display->display_options['argument_input'] = array(
    'group_nid' => array(
      'type' => 'panel',
      'context' => 'node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Organic groups: Groups',
    ),
  );

  /* Display: CDH Juarez Stories OL Data */
  $handler = $view->new_display('openlayers', 'CDH Juarez Stories OL Data', 'cdhj_stories_ol_data');
  $handler->display->display_options['display_description'] = 'Feed the preset to show all CDH Juarez stories';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_data';
  $handler->display->display_options['style_options']['data_source'] = array(
    'value' => 'other_latlon',
    'other_lat' => 'latitude',
    'other_lon' => 'longitude',
    'openlayers_wkt' => 'title',
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

  /* Display: CDH Juarez Stories OL Map Pane */
  $handler = $view->new_display('panel_pane', 'CDH Juarez Stories OL Map Pane', 'cdhj_stories_ol_map_pane');
  $handler->display->display_options['display_description'] = 'Map of all the CDH Juarez stories';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_map';
  $handler->display->display_options['style_options']['preset'] = 'cdhj_stories_preset';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['pane_title'] = 'Group Stories OL Map Pane';
  $handler->display->display_options['argument_input'] = array(
    'group_nid' => array(
      'type' => 'context',
      'context' => 'node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '10016',
      'label' => 'Organic groups: Groups',
    ),
  );

  /* Display: CDH Juarez Stories Map Page */
  $handler = $view->new_display('page', 'CDH Juarez Stories Map Page', 'cdhj_stories_map_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'All Stories';
  $handler->display->display_options['display_description'] = 'Page with a map of all the CDH Juarez stories';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_map';
  $handler->display->display_options['style_options']['preset'] = 'cdhj_stories_preset';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Argument: Organic groups: Groups */
  $handler->display->display_options['arguments']['group_nid']['id'] = 'group_nid';
  $handler->display->display_options['arguments']['group_nid']['table'] = 'og_ancestry';
  $handler->display->display_options['arguments']['group_nid']['field'] = 'group_nid';
  $handler->display->display_options['arguments']['group_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['group_nid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['group_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['group_nid']['default_argument_options']['argument'] = '10014';
  $handler->display->display_options['arguments']['group_nid']['validate_type'] = 'og_group_types';
  $handler->display->display_options['arguments']['group_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['group_nid']['not'] = 0;
  $handler->display->display_options['path'] = 'cdh-juarez/map';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Map';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-cdhjuarez';
  $translatables['cdhj_all_stories'] = array(
    t('Defaults'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort By'),
    t('Asc'),
    t('Desc'),
    t('Latitude'),
    t('Longitude'),
    t('Body'),
    t('All'),
    t('CDH Juarez Stories List Pane'),
    t('Recent Reports'),
    t('List the most recent stories in the CDH Juarez Group'),
    t('View panes'),
    t('CDH Juarez Stories OL Data'),
    t('Feed the preset to show all CDH Juarez stories'),
    t('CDH Juarez Stories OL Map Pane'),
    t('Map of all the CDH Juarez stories'),
    t('Group Stories OL Map Pane'),
    t('CDH Juarez Stories Map Page'),
    t('All Stories'),
    t('Page with a map of all the CDH Juarez stories'),
  );

  $views[$view->name] = $view;

  // Exported view: cdhj_group_pages
  $view = new view;
  $view->name = 'cdhj_group_pages';
  $view->description = 'Show some pages for the Juarez group';
  $view->tag = 'CDH Juarez';
  $view->base_table = 'node';
  $view->human_name = 'Juarez Group Pages';
  $view->core = 6;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'About';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: Node: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'node_revisions';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 1;
  $handler->display->display_options['fields']['body']['element_class'] = 'twelvecol last';
  $handler->display->display_options['fields']['body']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['body']['element_wrapper_class'] = 'row';
  $handler->display->display_options['fields']['body']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  /* Filter: Node: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';

  /* Display: Juarez Group About Page */
  $handler = $view->new_display('page', 'Juarez Group About Page', 'cdhj_about_page');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Node: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'node_revisions';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_class'] = 'twelvecol last';
  $handler->display->display_options['fields']['body']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['body']['element_wrapper_class'] = 'row';
  $handler->display->display_options['fields']['body']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Argument: Node: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['argument'] = '10014';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'group' => 'group',
  );
  /* Filter: Node: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['path'] = 'cdh-juarez/about';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'About';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-cdhjuarez';

  /* Display: Juarez Story List Page */
  $handler = $view->new_display('page', 'Juarez Story List Page', 'cdhj_story_list_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Gallery';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '21';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
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
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Node: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'node_revisions';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '150';
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Argument: Organic groups: Groups */
  $handler->display->display_options['arguments']['group_nid']['id'] = 'group_nid';
  $handler->display->display_options['arguments']['group_nid']['table'] = 'og_ancestry';
  $handler->display->display_options['arguments']['group_nid']['field'] = 'group_nid';
  $handler->display->display_options['arguments']['group_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['group_nid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['group_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['group_nid']['default_argument_options']['argument'] = '10014';
  $handler->display->display_options['arguments']['group_nid']['validate_type'] = 'node';
  $handler->display->display_options['arguments']['group_nid']['validate_options']['types'] = array(
    'group' => 'group',
  );
  $handler->display->display_options['arguments']['group_nid']['validate_options']['access'] = 0;
  $handler->display->display_options['arguments']['group_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['group_nid']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  $handler->display->display_options['path'] = 'cdh-juarez/browse';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Browse';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-cdhjuarez';

  /* Display: Juarez Story Submit Page */
  $handler = $view->new_display('page', 'Juarez Story Submit Page', 'cdhj_story_submit_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Submit';
  $handler->display->display_options['path'] = 'cdh-juarez/submit';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Submit';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-cdhjuarez';
  $translatables['cdhj_group_pages'] = array(
    t('Defaults'),
    t('About'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort By'),
    t('Asc'),
    t('Desc'),
    t('Title'),
    t('Juarez Group About Page'),
    t('All'),
    t('Juarez Story List Page'),
    t('Gallery'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Text area'),
    t('Juarez Story Submit Page'),
    t('Submit'),
  );

  $views[$view->name] = $view;

  // Exported view: cdhj_one_story
  $view = new view;
  $view->name = 'cdhj_one_story';
  $view->description = '';
  $view->tag = 'CDH Juarez';
  $view->base_table = 'node';
  $view->human_name = 'CDH Juarez Story';
  $view->core = 6;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
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
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Location: Latitude */
  $handler->display->display_options['fields']['latitude']['id'] = 'latitude';
  $handler->display->display_options['fields']['latitude']['table'] = 'location';
  $handler->display->display_options['fields']['latitude']['field'] = 'latitude';
  $handler->display->display_options['fields']['latitude']['exclude'] = TRUE;
  $handler->display->display_options['fields']['latitude']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['external'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['latitude']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['latitude']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['html'] = 0;
  $handler->display->display_options['fields']['latitude']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['latitude']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['latitude']['hide_empty'] = 0;
  $handler->display->display_options['fields']['latitude']['empty_zero'] = 0;
  /* Field: Location: Longitude */
  $handler->display->display_options['fields']['longitude']['id'] = 'longitude';
  $handler->display->display_options['fields']['longitude']['table'] = 'location';
  $handler->display->display_options['fields']['longitude']['field'] = 'longitude';
  $handler->display->display_options['fields']['longitude']['exclude'] = TRUE;
  $handler->display->display_options['fields']['longitude']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['external'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['longitude']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['longitude']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['html'] = 0;
  $handler->display->display_options['fields']['longitude']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['longitude']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['longitude']['hide_empty'] = 0;
  $handler->display->display_options['fields']['longitude']['empty_zero'] = 0;
  /* Argument: Node: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
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

  /* Display: CDH Juarez Story OL Data */
  $handler = $view->new_display('openlayers', 'CDH Juarez Story OL Data', 'cdhj_one_story_ol_data');
  $handler->display->display_options['display_description'] = 'The feed for a preset to show the location of CDH Juarez Story';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_data';
  $handler->display->display_options['style_options']['data_source'] = array(
    'value' => 'other_latlon',
    'other_lat' => 'latitude',
    'other_lon' => 'longitude',
    'openlayers_wkt' => 'title',
    'other_top' => 'title',
    'other_right' => 'title',
    'other_bottom' => 'title',
    'other_left' => 'title',
    'name_field' => '',
    'keep_orig_name_field' => 1,
    'description_field' => '',
    'keep_orig_desc_field' => 1,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;

  /* Display: CDH Juarez Story OL Map Pane */
  $handler = $view->new_display('panel_pane', 'CDH Juarez Story OL Map Pane', 'cdhj_one_story_old_map_pane');
  $handler->display->display_options['display_description'] = 'A map of just CDH Juarez Story node';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_map';
  $handler->display->display_options['style_options']['preset'] = 'cdh_story_preset';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['pane_title'] = 'CDH Juarez Story OL Map Pane';
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
  $translatables['cdhj_one_story'] = array(
    t('Defaults'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort By'),
    t('Asc'),
    t('Desc'),
    t('Title'),
    t('Latitude'),
    t('Longitude'),
    t('All'),
    t('CDH Juarez Story OL Data'),
    t('The feed for a preset to show the location of CDH Juarez Story'),
    t('CDH Juarez Story OL Map Pane'),
    t('A map of just CDH Juarez Story node'),
    t('View panes'),
  );

  $views[$view->name] = $view;

  return $views;
}
