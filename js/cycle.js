Drupal.behaviors.nodeCycle = function() {
  $('div.pane-blog-photos div.field-field-image div.field-items').cycle({
    fx: 'scrollLeft',
    speed:   700,
    timeout: 6000,
    prev: '#vojo-node-cycle-prev',
    next: '#vojo-node-cycle-next, div.pane-blog-photos div.field-items',
    after: onAfter
  });
    
    // To get current slide number for see this example: http://www.malsup.com/jquery/cycle/count.html
  function onAfter(curr,next,opts) {
    var blog_pager = (opts.currSlide + 1) + ' of ' + opts.slideCount;
    $('#vojo-node-cycle-pager').html(blog_pager);
  }

  /*  $('#front-slideshow ul').cycle({
    fx: 'fade',
    speed:   700,
    timeout: 0,
    prev: '#front-slideshow #vojo-slide-prev',
    next: '#front-slideshow #vojo-slide-next',
    slideResize: 0
  }); */
    
  $('#front-slideshow ul li.views-row-first').addClass("current-slide");
  $('#front-slideshow #vojo-slide-next').click(function () {
    $('#front-slideshow ul li.current-slide').not("#front-slideshow ul li.views-row-last").next().addClass("current-slide").prev().removeClass("current-slide");
  });
  $('#front-slideshow #vojo-slide-prev').click(function () {
    $('#front-slideshow ul li.current-slide').not("#front-slideshow ul li.views-row-first").prev().addClass("current-slide").next().removeClass("current-slide");
  });
}
