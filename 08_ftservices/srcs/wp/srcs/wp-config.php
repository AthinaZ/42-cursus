<?php

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'admin' );

/** MySQL database password */
define( 'DB_PASSWORD', 'admin' );

/** MySQL hostname */
define( 'DB_HOST', 'mysql' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         'DMRI8wOr;%ct`yJ0m3Gsol>@cC$c^5kQr~T-pt}3PTBLYU+db8KCMV]60r^384l=');
define('SECURE_AUTH_KEY',  'iqu65=zp:(U|8tv,`B/?kgwjij9^1}?ubeQ!4amf ;zJRBrxI?)W<r)O{1W8bV+$');
define('LOGGED_IN_KEY',    'a-cMAm00];@alsoOsf&5hT&Y~3-tno& }zBWr><^)s^FEZ02(`U^nMdJCdhuI8C}');
define('NONCE_KEY',        ')?S(74q&e7<%Pqc!dEx)>H0v|a8<OqCIBp69W%+K*r0-E2fIr-._m->,y_+[G|c=');
define('AUTH_SALT',        'psr.V!RX$V7-QMTc2ih K{(TJ5dU*&Z=2Cu-Fsn27ct{-GhG6}1vY07+=0qngt|C');
define('SECURE_AUTH_SALT', 'f-9r+>$|l.KC2y4_^^iGuXa fmks_zb>R|Px-reDSc+t2V^Obo3Z-&4_A7K/Ta0%');
define('LOGGED_IN_SALT',   '5,j>*.(9mn}MFT=QQ$seZCX.);hU-B,h5XeTyyyS=PK<AA~E*Y&_o>pVor/$UF& ');
define('NONCE_SALT',       'm8N+m^2O->$i5f$P!@P:GRt^0buy,8UCSt58o&G  Cp@?ZW+?hBs6^U -?[a|4QM');

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the Codex.
 *
 * @link https://codex.wordpress.org/Debugging_in_WordPress
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', dirname( __FILE__ ) . '/' );
}

/** Sets up WordPress vars and included files. */
require_once( ABSPATH . 'wp-settings.php' );
