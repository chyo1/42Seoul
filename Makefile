
RM = rm -f
NAME = libft.a
CC = gcc -Wall -Wextra -Werror
OBJS = $(.c =.o) (srcs로 참조를 해줘야되나? ex. SRCS :.c=.o)
.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $@ $^

%.o : %.c
	$(CC) -c $< -o $@ -I libft.h

clean :
	$(RM) $(OBJS)

fclean :
	make clean
	$(RM) $(NAME)

re :
	make fclean
	make all