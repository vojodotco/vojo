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
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'All Stories';
  $handler->display->display_options['css_class'] = 'vojo-story-list';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = 1;
  $handler->display->display_options['row_options']['comments'] = 0;
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
  $handler->display->display_options['path'] = 'groups/%/unpublished';
  $translatables['vojo_group_all_stories'] = array(
    t('Defaults'),
    t('All Stories'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort By'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('All'),
    t('Vojo Group All Stories Pane'),
    t('View panes'),
    t('Vojo Group Unpublished Stories Page'),
    t('Unpublished Stories'),
  );

  $views[$view->name] = $view;

  // Exported view: vojo_group_pages
  $view = new view;
  $view->name = 'vojo_group_pages';
  $view->description = 'Random pages to support generic vojo groups';
  $view->tag = 'vojo';
  $view->base_table = 'node';
  $view->human_name = 'Vojo Group Pages';
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
  /* Field: Node: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'node_revisions';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  /* Sort criterion: Node: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Argument: Node: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['validate_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'group' => 'group',
  );
  $handler->display->display_options['arguments']['nid']['validate_options']['access'] = 1;
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
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
    'group' => 'group',
  );

  /* Display: Vojo Group About Page */
  $handler = $view->new_display('page', 'Vojo Group About Page', 'vojo_group_about_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'About';
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
  $handler->display->display_options['fields']['body']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['path'] = 'node/%/about';
  $handler->display->display_options['menu']['weight'] = '0';

  /* Display: Vojo Group Submit Page */
  $handler = $view->new_display('page', 'Vojo Group Submit Page', 'vojo_group_submit_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Submit';
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
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  $handler->display->display_options['path'] = 'node/%/submit';
  $translatables['vojo_group_pages'] = array(
    t('Defaults'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort By'),
    t('Asc'),
    t('Desc'),
    t('Title'),
    t('Body'),
    t('All'),
    t('Vojo Group About Page'),
    t('About'),
    t('Vojo Group Submit Page'),
    t('Submit'),
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
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
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
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
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
    'description_field' => 'body',
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
  $translatables['vojo_group_stories_map'] = array(
    t('Defaults'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort By'),
    t('Asc'),
    t('Desc'),
    t('Group node (post)'),
    t('Latitude'),
    t('Longitude'),
    t('All'),
    t('Vojo Group Stories OL Data'),
    t('Vojo Group Stories Map Page'),
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
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'All Groups';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
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
  $handler->display->display_options['empty']['text']['content'] = 'No groups';
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
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
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
  $handler->display->display_options['fields']['description']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['description']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['description']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['description']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['description']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['description']['alter']['html'] = 0;
  $handler->display->display_options['fields']['description']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['description']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['description']['hide_empty'] = 0;
  $handler->display->display_options['fields']['description']['empty_zero'] = 0;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Manager';
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
  $handler->display->display_options['fields']['post_count']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['post_count']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['post_count']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['post_count']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['post_count']['alter']['strip_tags'] = 0;
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
  $handler->display->display_options['fields']['member_count']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['member_count']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['member_count']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['member_count']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['member_count']['alter']['strip_tags'] = 0;
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
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
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
  $handler->display->display_options['fields']['description']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['description']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['description']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['description']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['description']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['description']['alter']['html'] = 0;
  $handler->display->display_options['fields']['description']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['description']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['description']['hide_empty'] = 0;
  $handler->display->display_options['fields']['description']['empty_zero'] = 0;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Manager';
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
  $handler->display->display_options['fields']['post_count']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['post_count']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['post_count']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['post_count']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['post_count']['alter']['strip_tags'] = 0;
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
  $handler->display->display_options['fields']['member_count']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['member_count']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['member_count']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['member_count']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['member_count']['alter']['strip_tags'] = 0;
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
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
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
    t('Reset'),
    t('Sort By'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('No groups'),
    t('Manager'),
    t('.'),
    t(','),
    t('Created'),
    t('Join Link'),
    t('Nid'),
    t('Feed'),
    t('Page'),
    t(' stories'),
    t(' members'),
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
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Search';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'search content';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'input_required';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
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
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
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
  $handler->display->display_options['fields']['body']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '150';
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
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
  $handler->display->display_options['defaults']['exposed_block'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'node/%/search';
  $translatables['vojo_og_search'] = array(
    t('Defaults'),
    t('Search'),
    t('more'),
    t('Reset'),
    t('Sort By'),
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

  return $views;
}
