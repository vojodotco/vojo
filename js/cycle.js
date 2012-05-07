Drupal.behaviors.nodeCycle = function() {
  $('div.pane-blog-photos div.field-field-image div.field-items').cycle({
    fx: 'scrollLeft',
    speed:   700,
    timeout: 6000,
    prev: '#vojo-node-cycle-prev',
    next: '#vojo-node-cycle-next, div.pane-blog-photos div.field-items',
    pager:  '#vojo-node-cycle-pager'
  });
}
