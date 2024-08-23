FROM debian:bookworm

RUN apt-get update -y && \
	apt-get upgrade -y && \
	apt-get -y install nginx openssl vim dumb-init

RUN mkdir /etc/nginx/ssl

RUN openssl req -x509 -nodes -days 365 -newkey rsa:4096 -sha256 \
	-keyout /etc/nginx/ssl/hyowchoi.key \
	-out /etc/nginx/ssl/hyowchoi.crt \
	-subj "/C=KO/ST=Seoul/L=Seoul/O=42Seoul/OU=hyowchoi/CN=hyowchoi/"

RUN mkdir -p /run/nginx

EXPOSE	443

COPY ./conf/nginx.conf /etc/nginx/conf.d

ENTRYPOINT [ "/usr/bin/dumb-init", "--" ]

CMD ["nginx", "-g", "daemon off;"]