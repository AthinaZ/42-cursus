# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/24 15:31:37 by azouzoul          #+#    #+#              #
#    Updated: 2021/02/24 15:31:40 by azouzoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Install OS
FROM debian:buster

# Update OS

RUN apt update
RUN apt upgrade -y

# Install Nginx

RUN apt install -y wget nginx mariadb-server

# Install phpMyAdmin

RUN apt-get -y install php7.3 php-mysql php-fpm php-pdo php-gd php-cli php-mbstring php-gettext
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-english.tar.gz
RUN tar xvf phpMyAdmin-5.0.4-english.tar.gz
RUN mv phpMyAdmin-5.0.4-english /var/www/html/phpmyadmin
RUN rm -rf phpMyAdmin-5.0.4-english.tar.gz

# Install wordpress

RUN wget https://wordpress.org/latest.tar.gz && \
    tar -xzvf latest.tar.gz && \
    mv wordpress /var/www/html/ && \
    rm -rf latest.tar.gz

# Expose port 80 (HTTP) and 443 (HTTPS)
EXPOSE 80 443

# Copy config file from src

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
		-subj "/C=IT/ST=Lazio/L=Rome/O=42/OU=Luiss/CN=localhost" \
		-keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt
COPY ./srcs/wp-config.php var/www/html/wordpress
COPY ./srcs/config.inc.php /var/www/html/phpmyadmin
COPY ./srcs/default /etc/nginx/sites-available
COPY ./srcs/init.sh /
COPY ./srcs/autoindex ./bin
COPY ./srcs/index.html /var/www/html
RUN chmod 777 ./bin/autoindex
CMD bash init.sh
RUN mkdir /var/www/html/phpmyadmin/tmp/
RUN chmod -R 777 /var/www/html/phpmyadmin/tmp/
