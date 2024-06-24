RM = rm -f
CXX = c++
NAME = megaphone
SRC = Megaphone.cpp
SRC_OBJ = Megaphone.o main.o
CFLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(SRC_OBJ)
		$(CXX) $(CFLAGS) -o $@ $(SRC)

%.o : %.cpp
	$(CXX) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(SRC_OBJ)

fclean: 
	make clean
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re