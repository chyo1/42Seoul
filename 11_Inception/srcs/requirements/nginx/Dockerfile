FROM debian:bookworm

RUN apt-get update -y && \
    apt-get upgrade -y && \
    apt-get install -y nginx openssl vim dumb-init && \

	# SSL 인증서를 저장할 디렉터리, Nginx 런타임 디렉터리 생성
    mkdir -p /etc/nginx/ssl /run/nginx && \

	# SSL 인증서와 개인 키를 생성합니다. 이 인증서는 1년 동안 유효
    openssl req -x509 -nodes -days 365 -newkey rsa:4096 -sha256 \
    -keyout /etc/nginx/ssl/hyowchoi.key \
    -out /etc/nginx/ssl/hyowchoi.crt \
    -subj "/C=KO/ST=Seoul/L=Seoul/O=42Seoul/OU=hyowchoi/CN=hyowchoi/" && \

    # 불필요한 캐시 파일을 삭제
	apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# 컨테이너가 포트 443을 사용할 수 있도록 설정
EXPOSE	443

# 호스트의 Nginx 설정 파일을 컨테이너의 적절한 디렉터리로 복사
COPY ./conf/nginx.conf /etc/nginx/conf.d

# dumb-init을 사용하여 PID 1 문제를 해결, Nginx를 포그라운드 모드로 실행
ENTRYPOINT [ "/usr/bin/dumb-init", "--" ]

CMD ["nginx", "-g", "daemon off;"]