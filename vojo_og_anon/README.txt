Vojo Organic Groups Anonymous
=============================

This Vojo.co submodule extends organic groups to allow anonymous people to post to groups.  It does this by letting the admin pick a "fake anonymous" user (by id).  This fake anonymous user is then automatically added to all groups, and is set as the author for any posts in a group from anonymous.

Installation
------------

1. Install and activate the module as normal.
2. Create a new "Fake Anonymous" user and write down its id. 
3. Go to the admin settings for the module (admin/settings/vojo_og_anon) and set the user id field to the id you noted in step 2.

Ideas
-----
 - decide to use this feature on a per-group basis (with a checkbox while editing a group)
