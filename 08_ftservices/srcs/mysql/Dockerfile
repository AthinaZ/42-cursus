FROM alpine:3.13

RUN apk update && apk upgrade --no-cache
RUN apk add mariadb mariadb-client openrc telegraf --no-cache

RUN mkdir ./etc/telegraf && mv /etc/telegraf.conf /etc/telegraf/telegraf.conf

COPY ./srcs/mariadb-server.cnf /etc/my.cnf.d/mariadb-server.cnf

COPY ./srcs/wordpress.sql /tmp/wordpress.sql

ENV USER="admin"
ENV PASSWORD="1234"
ENV DATABASE="grafana"
ENV URLS="http://influxdb:8086"
ENV SKIP_DB_CREATION="true"

COPY ./srcs/start.sh /bin/start
RUN chmod +x /bin/start

CMD start