<?php

/**
 * Various vojo-specific blocks
 */
function vojo_block($op = 'list', $delta = 0, $edit = array()){
    $to_return = null;
    switch($op){
        case 'list':
            $block_list = array();
            $block = array(
                'info'=>t('Vojo: Powered By'),
//                'cache'=>BLOCK_CACHE_GLOBAL,
                'status'=>1,
                'region'=>'footer',
                'visibility'=>0,
            );
            $block_list['powered-by'] = $block;
            $block = array(
                'info'=>t('Vojo: Supported By'),
//                'cache'=>BLOCK_CACHE_GLOBAL,
                'status'=>1,
                'region'=>'footer',
                'visibility'=>0,
            );
            $block_list['supported-by'] = $block;
            $block = array(
                'info'=>t('Vojo: License'),
//                'cache'=>BLOCK_CACHE_GLOBAL,
                'status'=>1,
                'region'=>'footer',
                'visibility'=>0,
            );
            $block_list['license'] = $block;
            $to_return = $block_list;
            break;
        case 'view':
            $block = null;
            switch($delta){
                case 'powered-by':
                    $block = array(
                        'subject'=>null,
                        'content'=>_vojo_block_powered_by_contents()
                    );
                    break;
                case 'supported-by':
                    $block = array(
                        'subject'=>null,
                        'content'=>_vojo_block_supported_by_contents()
                    );
                    break;                
                case 'license':
                    $block = array(
                        'subject'=>null,
                        'content'=>_vojo_block_license_contents()
                    );
                    break;                
            }
            $to_return = $block;
            break;
    }
    return $to_return;
}

function _vojo_block_powered_by_contents(){
    $content = l( _vojo_image_path("powered-by-vozmob.gif"), "http://vozmob.net", array('html'=>true)  );
    $content.= ' ';
    $content.= l( _vojo_image_path("powered-by-drupal.png"), "http://drupal.org", array('html'=>true)  );
    return $content;
}

function _vojo_block_supported_by_contents(){
    $content = t('<a href="@site_link">@site_name</a> is a project of the <a href="http://civic.mit.edu">MIT Center for Civic Media</a>',
        array("@site_name"=>variable_get('site_name', "Vojo.co"), "@site_link"=>url('<front>')) );
    return $content;
}

function _vojo_block_license_contents(){
    $content = l( _vojo_image_path("copy-left.png"), 'http://creativecommons.org/licenses/by-nc-sa/2.0/', array('html'=>true) );
    $content.= ' ';
    $content.= l( t('Creative Commons'), 'http://creativecommons.org/licenses/by-nc-sa/2.0/', array('html'=>true) );
    return $content;
}

function _vojo_image_path($imgfile){
    return theme_image(drupal_get_path('module','vojo')."/img/".$imgfile);
}