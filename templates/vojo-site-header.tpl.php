<a id="beta" href="<?php print $base_path; ?>">beta</a>
<div id="vojo-site-header">
  <div class="container">
    <a  id="vojo-logo" href="<?php print $base_path; ?>"><img src="<?php print $base_path . drupal_get_path('theme', 'vojo_generic'); ?>/images/vojo/logo-top-header.png" alt="Vojo home page" /></a>
    <div class="block-voip-number"><?php print $vojo_callin_number; ?></div>
  <?php print $user_links; ?>
  <?php if (isset($primary_links)) : ?>
    <?php print theme('links', $primary_links, array('class' => 'links primary-links')) ?>
  <?php endif; ?>
  </div>
</div> <!-- /#vojo-top-header -->
