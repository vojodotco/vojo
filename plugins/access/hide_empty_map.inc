<?php
// $Id: node_type.inc,v 1.7.2.2 2009/11/13 00:44:16 merlinofchaos Exp $

/**
 * @file
 * Plugin to provide access control based upon a field on the group node that
 * selects the type of group, either mapping or journalism.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t("Node: check peresence of location data on blog entires"),
  'description' => t('Control access based on presense of location data in blog entries.'),
  'callback' => 'vojo_hide_empty_map_ctools_access_check',
  'defaults' => array(
    'type' => FALSE,
  ),
  'settings form' => 'vojo_hide_empty_map_ctools_access_settings',
 // 'settings form submit' => 'vojo_hide_empty_map_ctools_access_settings_submit',
  'summary' => 'vojo_hide_empty_map_ctools_access_summary',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * Settings form for the 'by group_type' access plugin
 */
function vojo_hide_empty_map_ctools_access_settings(&$form, &$form_state, $conf) {
}

/**
 * Compress the node_types allowed to the minimum.
 */
/* function vojo_hide_empty_map_ctools_access_settings_submit(&$form, &$form_state) {
  $form_state['values']['settings']['type'] = array_filter($form_state['values']['settings']['type']);
} */

/**
 * Check for access.
 */
function vojo_hide_empty_map_ctools_access_check($conf, $context) {
  $node = $context->data;
  if (!empty($node->locations)) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}

/**
 * Provide a summary description based upon the checked node_types.
 */
function vojo_hide_empty_map_ctools_access_summary($conf, $context) {
  return $conf['type'];
}
