FROM alpine:3.13

RUN apk update && apk upgrade --no-cache

RUN apk add openrc influxdb telegraf openrc libc6-compat --no-cache

RUN mkdir ./etc/telegraf \
    && mv /etc/telegraf.conf /etc/telegraf/telegraf.conf

ENV USER="admin"
ENV PASSWORD="1234"
ENV DATABASE="grafana"
ENV URLS="http://influxdb:8086"
ENV SKIP_DB_CREATION="true"

COPY /srcs/start.sh ./bin/start
RUN chmod +x ./bin/start

CMD start