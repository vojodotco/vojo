Drupal.behaviors.nodeCycle = function() {
  $('div.pane-blog-photos div.field-field-image div.field-items').cycle({
    fx: 'fade',
    timeout: 5000,
    prev: '#vojo-node-cycle-prev',
    next: '#vojo-node-cycle-next, div.pane-blog-photos div.field-items',
    pager:  '#vojo-node-cycle-pager'
  });
}
