NAME = bsq
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJECTS = srcs/ft_atoi.o srcs/ft_realloc.o srcs/ft_string.o srcs/input.o srcs/input2.o srcs/main.o srcs/vector.o srcs/find_max_size_and_change_max_square.o srcs/make_and_init_map.o srcs/print.o srcs/utils.o srcs/find_max_size_at_line.o
SRC_DIR = ./srcs
INCLUDE = -Iincludes/
HEADERS = includes/ft_atoi.h includes/ft_realloc.h includes/ft_string.h includes/input.h includes/vector.h includes/find_square.h includes/utils.h

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDE) $^ -o $@

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean:
	make clean
	rm -rf $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
