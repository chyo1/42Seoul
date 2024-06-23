RM=			rm -f
NAME=		fractol
CC=			cc
CFLAGS=		-Wall -Wextra -Werror -g -Lmlx -lmlx -framework OpenGL -framework AppKit -fsanitize=address
SRCS_MAN=	main.c\
			mandelbrot.c julia.c burningship.c\
			string_func.c color.c hooking.c\
			init_n_execute.c
SRCS_BONUS= main.c\
			mandelbrot.c julia.c burningship.c\
			string_func.c color.c hooking.c\
			init_n_execute.c
.PHONY : all bonus clean fclean re

all : $(NAME)

$(NAME) : LAST_ALL

LAST_ALL : $(SRCS_MAN)
	$(CC) $(CFLAGS) $(SRCS_MAN) -o $(NAME)
	touch LAST_ALL

bonus : LAST_BONUS

LAST_BONUS : $(SRCS_BONUS)
	$(CC) $(CFLAGS) $(SRCS_BONUS) -o $(NAME)
	touch LAST_BONUS

clean :
	rm LAST_ALL
	rm LAST_BONUS

fclean :
	make clean
	$(RM) $(NAME)

re :
	make fclean
	make all