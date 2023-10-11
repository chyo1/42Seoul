
RM=			rm -f
NAME=		libft.a
CC=			gcc -Wall -Wextra -Werror
SRCS_MANDATORY=	ft_calloc.c ft_isprint.c  ft_memset.c ft_split.c ft_strlcat.c ft_strnstr.c ft_toupper.c ft_isalnum.c ft_itoa.c ft_memchr.c ft_putchar_fd.c ft_strchr.c ft_strlcpy.c ft_strrchr.c ft_isalpha.c ft_memcmp.c ft_putendl_fd.c ft_strdup.c ft_strlen.c ft_strtrim.c ft_atoi.c ft_isascii.c ft_memcpy.c ft_putnbr_fd.c ft_striteri.c ft_strmapi.c ft_substr.c ft_bzero.c ft_isdigit.c ft_memmove.c ft_putstr_fd.c ft_strjoin.c ft_strncmp.c ft_tolower.c
SRCS_bonus=	ft_lstdelone.c ft_lstsize.c ft_lstiter.c ft_lstadd_back.c ft_lstlast.c ft_lstadd_front.c ft_lstmap.c ft_lstclear.c ft_lstnew.c 
OBJS_MANDATORY =  $(SRCS_MANDATORY:.c=.o)
SRCS_bonus=	$(SRCS_bonus:.c=.o)
.PHONY : all bonus clean fclean re

all : $(NAME)
	
$(NAME) : $(OBJS_MANDATORY)
	ar rc $(NAME) $(OBJS_MANDATORY)

$(OBJS_MANDATORY) : $(SRCS_MANDATORY)
	
%.o : %.c
	$(CC) -c $< -o $@ -I./

bonus : $(OBJS_bonus)
	
$(OBJS_bonus) : $(SRCS_bonus)

clean :
	$(RM) $(OBJS_MANDATORY) $(OBJS_bonus) 

fclean :
	make clean
	$(RM) $(NAME)

re :
	make fclean
	make all