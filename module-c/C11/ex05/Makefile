# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/05 12:33:08 by hyowchoi          #+#    #+#              #
#    Updated: 2023/08/05 12:33:09 by hyowchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -Wall -Wextra -Werror
NAME = do-op
OBJS = main.o calculate.o print.o
SRCS = main.c calculate.c print.c

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

main.o : main.c
	$(CC) -c main.c -o main.o

calculate.o : calculate.c
	$(CC) -c calculate.c -o calculate.o

print.o : print.c
	$(CC) -c print.c -o print.o

clean : 
	rm -f $(OBJS)

fclean :
	make clean
	rm -f $(NAME)

re :
	make fclean
	make all