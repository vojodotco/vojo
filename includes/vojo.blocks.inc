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
                'info'=>t('Vojo: Powered by VozMob'),
                'cache'=>BLOCK_CACHE_GLOBAL,
                'status'=>1,
                'region'=>'footer',
                'visibility'=>0,
            );
            $block_list['powered-by-vozmob'] = $block;
            $block = array(
                'info'=>t('Vojo: Powered by Drupal'),
                'cache'=>BLOCK_CACHE_GLOBAL,
                'status'=>1,
                'region'=>'footer',
                'visibility'=>0,
            );
            $block_list['powered-by-drupal'] = $block;
            $block = array(
                'info'=>t('Vojo: Creative Commons License'),
                'cache'=>BLOCK_CACHE_GLOBAL,
                'status'=>1,
                'region'=>'footer',
                'visibility'=>0,
            );
            $block_list['creative-commons-license'] = $block;
            $to_return = $block_list;
            break;
        case 'view':
            $block = null;
            switch($delta){
                case 'powered-by-vozmob':
                    $block = array(
                        'subject'=>null,
                        'content'=>_vojo_block_powered_by_vozmob_contents()
                    );
                    break;
                case 'powered-by-drupal':
                    $block = array(
                        'subject'=>null,
                        'content'=>_vojo_block_powered_by_drupal_contents()
                    );
                    break;
                case 'creative-commons-license':
                    $block = array(
                        'subject'=>null,
                        'content'=>_vojo_block_creative_commons_license_contents()
                    );
                    break;                
            }
            $to_return = $block;
            break;
    }
    return $to_return;
}

function _vojo_block_powered_by_vozmob_contents(){
    $content = l(t('Vojo.co'),'http://www.vojo.co').t(' is powered by')." ".l(t('VozMob'),'http://www.vozmob.net');
    return $content;
}

function _vojo_block_powered_by_drupal_contents(){
    $content = l(t('Vojo.co'),'http://www.vojo.co').t(' is powered by')." ".l(t('Drupal'),'http://drupal.org/');
    return $content;
}

function _vojo_block_creative_commons_license_contents(){
    $content = l( theme_image(drupal_get_path('module','vojo')."/img/copy-left.png"), 'http://creativecommons.org/licenses/by-nc-sa/2.0/', array('html'=>true) );
    $content.= ' ';
    $content.= l( t('Creative Commons'), 'http://creativecommons.org/licenses/by-nc-sa/2.0/', array('html'=>true) );
    return $content;
}
