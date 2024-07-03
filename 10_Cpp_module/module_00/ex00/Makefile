RM = rm -f
CXX = c++
NAME = megaphone
SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)
CFLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
		$(CXX) $(CFLAGS) -o $@ $(SRCS)

%.o : %.cpp
	$(CXX) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(OBJS)

fclean: 
	make clean
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re