<?php

/**
 * Supply a "Powered by VozMob" block
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
