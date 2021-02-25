service nginx start
service mysql start
service php7.3-fpm start

# Configure a wordpress database
echo "CREATE DATABASE wordpress;" | mysql -uroot
echo "CREATE USER 'azouzoul'@'localhost' IDENTIFIED BY 'password';" | mysql -uroot
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'azouzoul'@'localhost' WITH GRANT OPTION;"| mysql -uroot
echo "FLUSH PRIVILEGES;"| mysql -uroot
echo "update mysql.user set plugin='' where user='azouzoul';"| mysql -uroot

bash
