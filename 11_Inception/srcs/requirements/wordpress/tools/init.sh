#!/bin/sh

if  [ -f ./wp-config.php ]
then
	echo "wordpress is already installed"
else
	# WordPress 최신 버전을 다운로드하고 압축을 푼 후, /var/www/html/ 디렉터리로 파일을 이동.
	# www-data 사용자와 그룹에게 소유권을 부여한 후, 다운로드한 압축 파일과 디렉터리를 삭제
	echo "Downloading and installing WordPress..."
	wget http://wordpress.org/latest.tar.gz
	tar xfz latest.tar.gz
	mv wordpress/* /var/www/html/
	chown -R www-data:www-data /var/www/html
	rm -rf latest.tar.gz wordpress

	# wp-config-sample.php 파일에서 데이터베이스 사용자, 비밀번호, 호스트 및 데이터베이스 이름을 환경 변수로 대체
	# 수정된 wp-config-sample.php를 wp-config.php로 이름을 바꿔서 /var/www/html/로 이동
	echo "Configuring WordPress..."
	sed -i "s/username_here/$MARIADB_USER/g" wp-config-sample.php
	sed -i "s/password_here/$MARIADB_PASSWORD/g" wp-config-sample.php
	sed -i "s/localhost/mariadb/g" wp-config-sample.php
	sed -i "s/database_name_here/$MARIADB_DATABASE/g" wp-config-sample.php
	mv /var/www/html/wp-config-sample.php /var/www/html/wp-config.php

	# WordPress 설치를 진행하며, 관리자를 위한 기본 설정과 함께 첫 사용자 계정을 생성
	echo "Installing WordPress..."
	cd /var/www/html
	wp core install --url=$DOMAIN_NAME --admin_user=$WP_ADMIN --admin_password=$WP_ADMIN_PASSWORD --admin_email=$WP_ADMIN_EMAIL --title="$WP_TITLE" --allow-root
	wp user create $WP_USER $WP_USER_EMAIL --user_pass=$WP_USER_PASSWORD --allow-root

	echo "WordPress installation complete."
fi

# 컨테이너의 주 프로세스를 실행. Docker에서는 이 명령어가 ENTRYPOINT에 의해 전달된 명령어를 실행
exec "$@"