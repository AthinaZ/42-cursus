FROM alpine:3.13

RUN apk update && apk upgrade --no-cache

RUN apk add vim openrc libc6-compat telegraf --no-cache

# Download tar file to install grafana, extract it and then remove it (-f = force; -r = recursively remove directories and all their contents)
RUN wget https://dl.grafana.com/oss/release/grafana-7.5.3.linux-amd64.tar.gz \
    && tar -zxvf grafana-7.5.3.linux-amd64.tar.gz  \
    && rm -rf grafana-7.5.3.linux-amd64.tar.gz \
    && mv grafana-7.5.3 grafana

RUN mkdir ./etc/telegraf && mv /etc/telegraf.conf /etc/telegraf/telegraf.conf
RUN mkdir ./etc/dashboards

COPY ./srcs/grafana.db /grafana/data/grafana.db
COPY ./srcs/dashboards ./etc/dashboards
COPY ./srcs/dashboards.yaml /grafana/conf/provisioning/dashboards/sample.yaml
COPY ./srcs/datasources.yaml /grafana/conf/provisioning/datasources/sample.yaml
COPY /srcs/start.sh ./bin/start

# For influxDB
ENV USER="admin"
ENV PASSWORD="1234"
ENV DATABASE="grafana"
ENV URLS="http://influxdb:8086"
ENV SKIP_DB_CREATION="true"

RUN chmod +x ./bin/start

CMD start

