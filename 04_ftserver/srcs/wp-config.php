<?php
/*
 * The basic WordPress configuration file.
 *
 * This file is used by the script during installation
 * to create wp-config.php. It is not necessary to use it only via the web
 * you can copy this file to "wp-config.php" and fill in the correct values.
 *
 * This file defines the following configurations:
 *
 * MySQL settings
 * Secret Keys
 * Table prefix
 * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

/* MySQL Settings - You can get this information from your hosting provider */
/* The name of the WordPress database */
define('DB_NAME', 'wordpress');

/* MySQL database username */
define('DB_USER', 'azouzoul');

/* MySQL database password */
define('DB_PASSWORD', 'password');

/* Hostname MySQL  */
define('DB_HOST', 'localhost');

/* Database charset to be used in creating tables. */
define('DB_CHARSET', 'utf8');

/* The type of database collation. Not to be changed if you have no idea what it is. */
define('DB_COLLATE', '');

/* # @ +
* Authentication Unique Keys and Salts
*
* Edit them with different unique phrases!
* These keys can be generated using {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
* You can change these keys at any time to invalidate all existing cookies. This will force all users to log in again.
*
* @since 2.6.0
*/
define('AUTH_KEY',         'Put your unique phrase here');
define('SECURE_AUTH_KEY',  'Put your unique phrase here');
define('LOGGED_IN_KEY',    'Put your unique phrase here');
define('NONCE_KEY',        'Put your unique phrase here');
define('AUTH_SALT',        'Put your unique phrase here');
define('SECURE_AUTH_SALT', 'Put your unique phrase here');
define('LOGGED_IN_SALT',   'Put your unique phrase here');
define('NONCE_SALT',       'Put your unique phrase here');

/**#@-*/

/*
* WordPress Database Table Prefix.
*
* It is possible to have multiple installations on a single database
* providing each installation with a unique prefix.
* Numbers, letters and underlining only!
*/
$table_prefix = 'wp_';

/*
* For developers: WordPress debug mode.
*
* Change this entry to TRUE to enable warnings to be displayed during development
* It is strongly recommended for plugin and theme developers to use
* WP_DEBUG within their development environments.
*
* For information on other constants that can be used for debugging,
* read the documentation
*
* @link https://wordpress.org/support/article/debugging-in-wordpress/
*/
define('WP_DEBUG', false);

/* Done, no more editing and time to start blogging./

/* Absolute path to the WordPress directory. */
if ( !defined('ABSPATH') )
        define('ABSPATH', dirname(__FILE__) . '/');

/* Set WordPress variables and include files. */
require_once(ABSPATH . 'wp-settings.php');
