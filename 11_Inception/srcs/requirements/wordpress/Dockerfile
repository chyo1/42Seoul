FROM debian:bookworm

EXPOSE 9000

RUN apt-get update -y && \
	apt-get upgrade -y && \
	apt-get install -y \
	dumb-init \
	curl \
	php \
	php-fpm \
	php-cli \
	php-mysql \
	php-cgi \
	php-pdo \
	php-gd \
	php-mbstring \
	wget && \
	rm -rf /var/lib/apt/lists/*

# PHP-FPM 설정 파일(www.conf)과 초기화 스크립트(init.sh)를 컨테이너에 복사, 스크립트에 실행 권한을 부여
RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar
RUN mv wp-cli.phar /usr/bin/wp 

# 작업 디렉터리를 /var/www/html/로 설정, dumb-init을 사용하여 초기화 스크립트를 실행.
COPY ./conf/www.conf /etc/php/8.2/fpm/pool.d/
COPY ./tools/init.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/init.sh

RUN mkdir -p /run/php

ENTRYPOINT ["/usr/bin/dumb-init", "--", "/usr/local/bin/init.sh"]

WORKDIR /var/www/html/

# php-fpm을 포그라운드 모드로 실행하여 컨테이너가 PHP-FPM을 계속 실행하도록 함.
CMD ["php-fpm8.2", "-F"]