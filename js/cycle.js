Drupal.behaviors.nodeCycle = function() {
  $('div.pane-blog-photos div.field-field-image div.field-items').cycle({
    fx: 'scrollLeft',
    speed:   700,
    timeout: 6000,
    prev: '#vojo-node-cycle-prev',
    next: '#vojo-node-cycle-next, div.pane-blog-photos div.field-items',
    pager:  '#vojo-node-cycle-pager',
    after: onAfter
  });
    
    // To get current slide number for see this example: http://www.malsup.com/jquery/cycle/count.html
  function onAfter(curr,next,opts) {
    var blog_pager = (opts.currSlide + 1) + ' of ' + opts.slideCount;
    $('#vojo-node-cycle-pager').html(blog_pager);
  }
}
