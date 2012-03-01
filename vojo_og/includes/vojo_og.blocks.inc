<?php

/**
 * Implementation of hook_block().
 */
function vojo_og_block($op = 'list', $delta = 0, $edit = array()) {
    $to_return = null;
    switch($op){
        case 'list':
            $block= array(
                'info'=>t('Vojo: Generic Group Menu'),
                'region'=>'navigation',
            );
            $block_list['generic-group-menu'] = $block;
            $to_return = $block_list;
            break;
        case 'view':
            $block = null;
            switch($delta){
                case 'generic-group-menu':
                    $block = array(
                        'subject'=>null,
                        'content'=>_vojo_og_generic_group_menu_block_contents()
                    );
                    break;
            }
            $to_return = $block;
            break;
    }
    return $to_return;
}

/**
 * Supply a generic menu for un-themed groups
 */
function _vojo_og_generic_group_menu_block_contents(){
    $contents = null;
    $group_nid = vojo_og_get_group_nid();
    if($group_nid){
        $group_node = node_load($group_nid);
        // group name
        $contents.= "<h2>".$group_node->title."</h2>";
        $contents.= " ";
        // MENU LINKS
        $contents.= '<ul class="menu">';
        // group homepage
        $contents.= '<li class="leaf first">';
        $contents.= l(t('Home'), drupal_get_path_alias("node/".$group_nid));
        $contents.= "</li>";
        // group about page
        $contents.= '<li class="leaf first">';
        $contents.= l(t('About'), drupal_get_path_alias("node/".$group_nid."/about"));
        $contents.= "</li>";        
        // group story submit page
        $contents.= '<li class="leaf first">';
        $contents.= l(t('Submit'), drupal_get_path_alias("node/".$group_nid."/submit"));
        $contents.= "</li>";        
        // group map
        $contents.= '<li class="leaf">';
        $contents.= l(t('Map'), drupal_get_path_alias("node/".$group_nid."/map"));
        $contents.= "</li>";
        // admin: group unpublished blog entries
        if(user_access( variable_get('og_user_roles_default_admin_role', 0) )  ){
        $contents.= '<li class="leaf">';
            $contents.= l(t('Unpublished'), drupal_get_path_alias("node/".$group_nid."/unpublished"));
            $contents.= "</li>";
        }
        $contents.= "</ul>";
    }
    return $contents;
}
