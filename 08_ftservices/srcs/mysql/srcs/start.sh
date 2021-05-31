sed -i "s|# urls = \[\"http://127.0.0.1:8086\"\]|urls = [\"${URLS}\"]|g" /etc/telegraf/telegraf.conf
sed -i "s|# skip_database_creation = false|skip_database_creation = ${SKIP_DB_CREATION}|g" /etc/telegraf/telegraf.conf
sed -i "s|# database = \"telegraf\"|database = \"${DATABASE}\"|g" /etc/telegraf/telegraf.conf
sed -i "s|# username = \"telegraf\"|username = \"${USER}\"|g" /etc/telegraf/telegraf.conf
sed -i "s|# password = \"metricsmetricsmetricsmetrics\"|password = \"${PASSWORD}\"|g" /etc/telegraf/telegraf.conf
sed -i "s|# dc = \"us-east-1\" # will tag all metrics with dc=us-east-1| dc = \"mysql\"|g" /etc/telegraf/telegraf.conf

telegraf &
mkdir -p /run/mysqld
openrc default
openrc boot
/etc/init.d/mariadb setup
sleep 2
rc-service mariadb start

mysql --user=root << EOF
FLUSH PRIVILEGES;
CREATE DATABASE IF NOT EXISTS wordpress;
CREATE USER 'admin'@'%' IDENTIFIED BY 'admin';
GRANT ALL PRIVILEGES ON wordpress.* TO 'admin'@'%' IDENTIFIED BY 'admin' WITH GRANT OPTION;
CREATE USER 'admin'@'%' IDENTIFIED BY 'password';
GRANT ALL PRIVILEGES ON phpmyadmin.* TO 'admin'@'%' IDENTIFIED BY 'password' WITH GRANT OPTION;
FLUSH PRIVILEGES;
EOF

cd tmp
mysql < wordpress.sql

while sleep 1; do
  ps aux |grep mariadbd |grep -q -v grep
  PROCESS_1_STATUS=$?
if [ $PROCESS_1_STATUS -ne 0 ]; then
    echo "MariaDB has already exited."
    exit 1
  fi
done
