# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/02 13:42:04 by hyowchoi          #+#    #+#              #
#    Updated: 2023/08/02 13:42:04 by hyowchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RM = rm -f
NAME = libft.a
SRCS = ./srcs/
INCLUDES = -Iincludes
OBJS = $(SRCS)ft_putchar.o $(SRCS)ft_putstr.o $(SRCS)ft_strcmp.o $(SRCS)ft_strlen.o $(SRCS)ft_swap.o
CC = gcc -Wall -Wextra -Werror

.PHONY : all clean fclean re 

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

$(SRCS)ft_putchar.o : $(SRCS)ft_putchar.c ./includes/ft.h
	$(CC) -c $(INCLUDES) $(SRCS)ft_putchar.c -o $(SRCS)ft_putchar.o

$(SRCS)ft_putstr.o : $(SRCS)ft_putstr.c ./includes/ft.h
	$(CC) -c $(INCLUDES) $(SRCS)ft_putstr.c -o $(SRCS)ft_putstr.o

$(SRCS)ft_strcmp.o : $(SRCS)ft_strcmp.c ./includes/ft.h
	$(CC) -c $(INCLUDES) $(SRCS)ft_strcmp.c -o $(SRCS)ft_strcmp.o

$(SRCS)ft_strlen.o : $(SRCS)ft_strlen.c ./includes/ft.h
	$(CC) -c $(INCLUDES) $(SRCS)ft_strlen.c -o $(SRCS)ft_strlen.o

$(SRCS)ft_swap.o : $(SRCS)ft_swap.c ./includes/ft.h
	$(CC) -c $(INCLUDES) $(SRCS)ft_swap.c -o $(SRCS)ft_swap.o

clean :
	$(RM) $(OBJS)

fclean :
	make clean
	$(RM) $(NAME)

re :
	make fclean
	make all
