<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function vojo_feature_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_voipnode_settings
  $groups['group-group_blog_publishing_options'] = array(
    'group_type' => 'standard',
    'type_name' => 'blog',
    'group_name' => 'group_blog_publishing_options',
    'label' => 'Promote story',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => t('This will feature your story on the group landing page. It will also appear on the vojo.co front page until replaced by newer stories.'),
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'label' => 'above',
      ),
    ),
    'weight' => '7',
    'fields' => array(
      '0' => 'field_blog_promote',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Publishing options');

  return $groups;
}