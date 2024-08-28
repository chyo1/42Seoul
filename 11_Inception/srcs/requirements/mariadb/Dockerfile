# Debian Bookworm 버전을 기반으로 하는 Docker 이미지를 사용
FROM debian:bookworm

# 컨테이너가 3306 포트를 사용하여 외부와 통신할 수 있도록 설정. 3306은 MariaDB의 기본 포트
EXPOSE 3306

# 패키지 목록 업데이트, 시스템을 업그레이드 후
# vim, dumb-init, mariadb-server, mariadb-client를 설치.
# 이후 패키지 캐시를 삭제하여 이미지 크기를 줄임
RUN apt-get update -y && \
    apt-get upgrade -y && \
    apt-get install -y vim dumb-init \
    mariadb-server \
    mariadb-client && \
    rm -rf /var/lib/apt/lists/*

# MariaDB의 소켓 파일이 위치할 곳
RUN mkdir -p /var/run/mysqld

# 디렉토리의 소유자를 mysql:mysql로 변경
RUN chown -R mysql:mysql /var/run/mysqld
# 디렉토리의 권한을 777로 설정
RUN chmod 777 /var/run/mysqld

# conf/mysqld.conf 파일을 컨테이너의 /etc/mysql/mariadb.conf.d/50-server.cnf 위치로 복사, MariaDB의 설정을 적용
COPY conf/mysqld.conf /etc/mysql/mariadb.conf.d/50-server.cnf

# 호스트의 ./tools/mariadb_setup.sh 스크립트를 컨테이너의 /usr/local/bin/ 디렉토리로 복사
COPY ./tools/mariadb_setup.sh /usr/local/bin/

# 복사한 스크립트에 실행 권한을 부여
RUN chmod +x /usr/local/bin/mariadb_setup.sh

# 컨테이너가 시작될 때 dumb-init을 사용하여 /usr/local/bin/mariadb_setup.sh 스크립트를 실행하도록 설정
# dumb-init은 PID 1 프로세스의 문제를 해결하는데 도움을 주는 프로세스 관리자
ENTRYPOINT [ "/usr/bin/dumb-init", "--", "/usr/local/bin/mariadb_setup.sh" ]

# 기본 명령: 컨테이너가 시작될 때 mysqld 명령어를 실행하며
# --bind-address=0.0.0.0 옵션을 통해 모든 네트워크 인터페이스에서 MariaDB 서버가 접근 가능하도록 설정
CMD [ "mysqld", "--bind-address=0.0.0.0" ]