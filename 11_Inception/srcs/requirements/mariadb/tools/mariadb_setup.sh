#!/bin/bash
# 스크립트를 실행할 셸을 지정. 여기서는 bash를 사용

if [ -d "/var/lib/mysql/$MARIADB_DATABASE" ]
then
    echo "Database already exists"
else
    # 데이터베이스가 존재하지 않으면 /tmp/init.sql 파일을 생성하여 MariaDB의 초기화 SQL 명령을 작성
    cat <<EOF > /tmp/init.sql
USE mysql;
ALTER USER 'root'@'localhost' IDENTIFIED BY '${MARIADB_ROOT_PASSWORD}';
FLUSH PRIVILEGES;
CREATE DATABASE IF NOT EXISTS ${MARIADB_DATABASE};
USE ${MARIADB_DATABASE};
CREATE USER '${MARIADB_USER}'@'%' IDENTIFIED BY '${MARIADB_PASSWORD}';
GRANT ALL PRIVILEGES ON ${MARIADB_DATABASE}.* TO '${MARIADB_USER}'@'%';
FLUSH PRIVILEGES;
EOF

    # mysqld_safe를 사용하여 MariaDB 서버를 시작하고, 생성한 SQL 초기화 스크립트를 사용하여 데이터베이스를 초기화
	# exec : 이 프로세스를 현재 셸의 프로세스 공간에서 실행
    exec mysqld_safe --init-file=/tmp/init.sql
fi

# 스크립트에 제공된 추가 명령어를 실행, Dockerfile에서 설정한 ENTRYPOINT와 CMD의 조합을 사용하여 컨테이너가 시작된 후 특정 명령어를 실행하는 데 유용
exec "$@"
