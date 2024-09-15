RM = rm -f
CXX = c++
NAME = exec
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
CFLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
		$(CXX) $(CFLAGS) -o $@ $(OBJS)

%.o : %.cpp
	$(CXX) $(CFLAGS) -c $^ -o $@ -I./

clean:
	rm -f $(OBJS)

fclean: 
	make clean
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re