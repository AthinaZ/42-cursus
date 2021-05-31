sed -i "s|# urls = \[\"http://127.0.0.1:8086\"\]|urls = [\"${URLS}\"]|g" /etc/telegraf/telegraf.conf
sed -i "s|# skip_database_creation = false|skip_database_creation = ${SKIP_DB_CREATION}|g" /etc/telegraf/telegraf.conf
sed -i "s|# database = \"telegraf\"|database = \"${DATABASE}\"|g" /etc/telegraf/telegraf.conf
sed -i "s|# username = \"telegraf\"|username = \"${USER}\"|g" /etc/telegraf/telegraf.conf
sed -i "s|# password = \"metricsmetricsmetricsmetrics\"|password = \"${PASSWORD}\"|g" /etc/telegraf/telegraf.conf
sed -i "s|# dc = \"us-east-1\" # will tag all metrics with dc=us-east-1| dc = \"grafana\"|g" /etc/telegraf/telegraf.conf

telegraf &

cd grafana
./bin/grafana-server

while sleep 1; do
  ps aux |grep grafana-server |grep -q -v grep
  PROCESS_1_STATUS=$?
  if [ $PROCESS_1_STATUS -ne 0 ]; then
      echo "Grafana has already exited."
      exit 1
  fi
done