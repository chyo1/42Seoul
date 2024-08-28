all:
	mkdir -p /Users/hyowon/42Seoul/11_Inception/inception/mariadb 
	# /home/hyowchoi/data/mariadb
	mkdir -p /Users/hyowon/42Seoul/11_Inception/inception/wordpress
	# /home/hyowchoi/data/wordpress
	@docker compose -f ./srcs/docker-compose.yml up -d --build

down:
	@docker compose -f ./srcs/docker-compose.yml down

clean:
	@docker stop `docker ps -qa`; \
	docker rm -f `docker ps -qa`; \
	docker rmi -f `docker images -qa`; \
	docker volume rm `docker volume ls -q`; \
	docker network prune -f;

fclean:
	make clean
	rm -rf /Users/hyowon/42Seoul/11_Inception/inception
	# rm -rf /home/hyowchoi/data
re:
	make fclean
	make all

.PHONY: all re down clean fclean