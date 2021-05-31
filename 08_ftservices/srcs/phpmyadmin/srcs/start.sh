php-config
openrc default
openrc boot

sed -i "s|# urls = \[\"http://127.0.0.1:8086\"\]|urls = [\"${URLS}\"]|g" /etc/telegraf/telegraf.conf
sed -i "s|# skip_database_creation = false|skip_database_creation = ${SKIP_DB_CREATION}|g" /etc/telegraf/telegraf.conf
sed -i "s|# database = \"telegraf\"|database = \"${DATABASE}\"|g" /etc/telegraf/telegraf.conf
sed -i "s|# username = \"telegraf\"|username = \"${USER}\"|g" /etc/telegraf/telegraf.conf
sed -i "s|# password = \"metricsmetricsmetricsmetrics\"|password = \"${PASSWORD}\"|g" /etc/telegraf/telegraf.conf
sed -i "s|# dc = \"us-east-1\" # will tag all metrics with dc=us-east-1| dc = \"phpmyadmin\"|g" /etc/telegraf/telegraf.conf

telegraf &
rc-service php-fpm7 start
rc-service nginx start

# Check every second to see if one of the two processes it is running has aborted unexpectedly:
# in that case, the container is aborted with that error message; otherwise keep running (and testing every second)
while sleep 1; do
  # With "ps aux" you get the list of active processes with their CPU and RAM consumption
  ps aux |grep php-fpm7 |grep -q -v grep
  PROCESS_1_STATUS=$?
  ps aux |grep nginx |grep -q -v grep
  PROCESS_2_STATUS=$?
  # If the grep above finds what it is looking for, then everything is fine
  # Then I check that the status of the two processes is equal to 0 and, if not, it comes out with an error
  if [ $PROCESS_1_STATUS -ne 0 -o $PROCESS_2_STATUS -ne 0 ]; then
    echo "One of the processes has already exited."
    exit 1
  fi
done
