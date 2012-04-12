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
  'title' => t("Group: type"),
  'description' => t('Control access by group_type.'),
  'callback' => 'vojo_group_type_ctools_access_check',
  'defaults' => array(
    'type' => 'news',
  ),
  'settings form' => 'vojo_group_type_ctools_access_settings',
 // 'settings form submit' => 'vojo_group_type_ctools_access_settings_submit',
  'summary' => 'vojo_group_type_ctools_access_summary',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * Settings form for the 'by group_type' access plugin
 */
function vojo_group_type_ctools_access_settings(&$form, &$form_state, $conf) {
  // Get list of fields.
  $fields = content_fields();
  // Use allowed values from field_group_type for options.
  $options = content_allowed_values($fields['field_group_type']);
  $form['settings']['type'] = array(
    '#title' => t('Group type'),
    '#type' => 'select',
    '#options' => $options,
    '#default_value' => $conf['type'],
  );
}

/**
 * Compress the node_types allowed to the minimum.
 */
/* function vojo_group_ype_ctools_access_settings_submit(&$form, &$form_state) {
  $form_state['values']['settings']['type'] = array_filter($form_state['values']['settings']['type']);
} */

/**
 * Check for access.
 */
function vojo_group_type_ctools_access_check($conf, $context) {
  $node = $context->data;
  if (isset($node->field_group_type[0]['value']) && $node->field_group_type[0]['value'] == $conf['type']) {
    return TRUE;
  }
  // If the group type field has no value, it will default to a news group. 
  else if (!isset($node->field_group_type[0]['value'])) {
    return TRUE;
  }
}

/**
 * Provide a summary description based upon the checked node_types.
 */
function vojo_group_type_ctools_access_summary($conf, $context) {
  return $conf['type'];
}
