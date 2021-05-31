FROM alpine:3.13

RUN apk update && apk upgrade --no-cache

RUN apk add openrc openssl vsftpd telegraf --no-cache

RUN openssl req -x509 -nodes -days 3650 -subj "/C=IT/ST=ROMA/L=ROMA/O=42/OU=42ROME/CN=localhost" -newkey rsa:4048 -keyout etc/ssl/private/vsftpd.key -out etc/ssl/certs/vsftpd.crt

RUN mkdir ./etc/telegraf && mv /etc/telegraf.conf /etc/telegraf/telegraf.conf

COPY ./srcs/vsftpd.conf /etc/vsftpd/vsftpd.conf

# For influxDB
ENV USER="admin"
ENV PASSWORD="1234"
ENV DATABASE="grafana"
ENV URLS="http://influxdb:8086"
ENV SKIP_DB_CREATION="true"

RUN { echo "password"; echo "password"; } | adduser ftps_admin

COPY ./srcs/start.sh ./bin/start
RUN chmod +x /bin/start

CMD start
