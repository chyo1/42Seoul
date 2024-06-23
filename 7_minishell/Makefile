NAME = minishell
SRC = 	main.c parse.c tokenize.c expand.c preprocess.c utils_string.c utils_math.c\
		remove_quote.c ft_split_str.c expand_wildcard.c delete_heredoc.c make_tree.c\
		utils_heredoc.c open_heredoc.c expand_heredoc_list.c create_pipeline.c\
		utils_free.c utils_free2.c print_parse_error.c utils_token.c\
		do_builtin_func.c postprocess.c handle_signal.c expand_dollar.c\
		execute_cmd_cd.c execute_cmd_echo.c execute_cmd_env.c execute_cmd_exit.c\
		execute_cmd_export.c execute_cmd_export_add.c execute_cmd_pwd.c execute_cmd_unset.c\
		matrix_list_change.c sorting.c expand_redis.c utils_string2.c\
		execute_wildcard.c check_wildcard_condition.c\
		pipex_main.c pipex_find_env_path.c pipex_do_child.c pipex_redirection.c\
		pipex_fin_program.c pipex_heredoc_make_file_name.c\
		pipex_split.c
SRC_OBJ = $(SRC:.c=.o)
HEADER = parse.h tokenize.h pipex.h minishell_type.h
BONUS_DIR = bonus_files/
BONUS_HEADER = expand_bonus.h minishell_type_bonus.h\
		parse_bonus.h pipex_bonus.h signal_bonus.h tokenize_bonus.h util_bonus.h
BONUS_HEADER := $(addprefix $(BONUS_DIR),$(BONUS_HEADER))
BONUS_SRC = check_wildcard_condition_bonus.c create_pipeline_bonus.c\
		delete_heredoc_bonus.c do_builtin_func_bonus.c execute_cmd_cd_bonus.c\
		execute_cmd_echo_bonus.c execute_cmd_env_bonus.c execute_cmd_exit_bonus.c\
		execute_cmd_export_add_bonus.c execute_cmd_export_bonus.c execute_cmd_pwd_bonus.c\
		execute_cmd_unset_bonus.c execute_wildcard_bonus.c expand_bonus.c expand_dollar_bonus.c\
		expand_heredoc_list_bonus.c expand_redis_bonus.c expand_wildcard_bonus.c\
		ft_split_str_bonus.c handle_signal_bonus.c main_bonus.c make_tree_bonus.c\
		matrix_list_change_bonus.c open_heredoc_bonus.c parse_bonus.c pipex_do_child_bonus.c\
		pipex_fin_program_bonus.c pipex_find_env_path_bonus.c pipex_heredoc_make_file_name_bonus.c\
		pipex_main_bonus.c pipex_redirection_bonus.c pipex_split_bonus.c postprocess_bonus.c\
		preprocess_bonus.c print_parse_error_bonus.c remove_quote_bonus.c sorting_bonus.c\
		tokenize_bonus.c utils_free2_bonus.c utils_free_bonus.c utils_heredoc_bonus.c\
		utils_math_bonus.c utils_string2_bonus.c utils_string_bonus.c utils_token_bonus.c
BONUS_SRC := $(addprefix $(BONUS_DIR),$(BONUS_SRC))
BONUS_OBJ = $(BONUS_SRC:.c=.o)
CFLAGS = -Wall -Werror -Wextra -L$(LIBFT_DIR) -lft -lreadline
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

all: $(NAME)

$(NAME): $(SRC) $(LIBFT) $(HEADER)
	cc $(CFLAGS) -o $@ $(SRC) -I$(LIBFT_DIR)

bonus: $(BONUS_SRC) $(LIBFT) $(BONUS_HEADER)
	cc $(CFLAGS) -o $(NAME)_bonus $(BONUS_SRC) -I$(LIBFT_DIR)
	touch $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(SRC_OBJ) $(BONUS_OBJ)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	rm -rf debug*
	rm -f bonus

re:
	make fclean
	make all

debug: $(SRC) $(LIBFT)
	gcc -g $(CFLAGS) -o debug $(SRC) -I$(LIBFT_DIR)

.PHONY: all clean fclean re
