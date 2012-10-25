Drupal.behaviors.nodeCycle = function() {
  $('div.pane-blog-photos div.field-field-image div.field-items').cycle({
    fx: 'scrollLeft',
    speed:   700,
    timeout: 6000,
    prev: '#vojo-node-cycle-prev',
    next: '#vojo-node-cycle-next, div.pane-blog-photos div.field-items',
    after: onAfter,
    height: 'auto'
  });
    
    // To get current slide number for see this example: http://www.malsup.com/jquery/cycle/count.html
  function onAfter(curr,next,opts) {
    var blog_pager = (opts.currSlide + 1) + ' of ' + opts.slideCount;
    $('#vojo-node-cycle-pager').html(blog_pager);
  }
}
Drupal.behaviors.frontCycle = function() {
  // TODO - Make jquery cycle work with responsive layout 
  $('#front-slideshow ul, .view-vojo-group-featured-stories ul').cycle({
    fx: 'fade',
    slideExpr: '.slide',
    speed:   700,
    timeout: 6000,
    prev: '#vojo-slide-prev',
    next: '#vojo-slide-next',
    slideResize: 0,
    containerResize: 0
  });
}
