FROM  alpine:3.13

RUN	apk update && apk upgrade --no-cache

RUN apk add vim openrc wget nginx openssl telegraf php7 php7-fpm php7-pdo_mysql php7-cli php7-json php7-mbstring php7-common php7-session php7-iconv php7-gd php7-curl php7-xml php7-mysqli php7-imap php7-cgi fcgi php7-pdo php7-soap php7-xmlrpc php7-posix php7-mcrypt php7-gettext php7-ldap php7-ctype php7-dom --no-cache

RUN wget https://wordpress.org/latest.tar.gz \
    && tar -xvzf latest.tar.gz && rm -rf latest.tar.gz

RUN mkdir -p run/nginx

RUN mkdir -p /www \
    && mv /wordpress/ /www

RUN	adduser -D -g 'www' www

RUN mkdir ./etc/telegraf && mv /etc/telegraf.conf /etc/telegraf/telegraf.conf

# for php
ENV PHP_FPM_USER="www"
ENV PHP_FPM_GROUP="www"
ENV PHP_FPM_LISTEN_MODE="0660"
ENV PHP_MEMORY_LIMIT="512M"
ENV PHP_MAX_UPLOAD="52M"
ENV PHP_MAX_FILE_UPLOAD="200"
ENV PHP_MAX_POST="100M"
ENV PHP_DISPLAY_ERRORS="On"
ENV PHP_DISPLAY_STARTUP_ERRORS="On"
ENV PHP_ERROR_REPORTING="E_COMPILE_ERROR\|E_RECOVERABLE_ERROR\|E_ERROR\|E_CORE_ERROR"
ENV PHP_CGI_FIX_PATHINFO=0
# for influxDB
ENV USER="admin"
ENV PASSWORD="1234"
ENV DATABASE="grafana"
ENV URLS="http://influxdb:8086"
ENV SKIP_DB_CREATION="true"

COPY /srcs/nginx-conf /etc/nginx/conf.d/default.conf
COPY /srcs/wp-config.php /www/wordpress/wp-config.php
COPY /srcs/start.sh /bin/start
COPY srcs/php-config /bin/php-config

RUN chmod +x ./bin/start && chmod +x ./bin/php-config

CMD start
