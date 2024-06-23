/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_type.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:48:59 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 16:31:51 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_TYPE_H
# define MINISHELL_TYPE_H

# include <stdio.h>

# include "libft/libft.h"
# include <unistd.h> 
# include <stdlib.h> 
# include <fcntl.h> 
# include <sys/wait.h> 
# include <stdio.h>
# include <dirent.h> 
# include <sys/types.h> 

# define NAME	"minishell: "
# define PROMPT	"minishell$ "

int		g_is_ctrl_c;

typedef enum e_token_type
{
	WORD_T,
	OPENP_T,
	CLOSEP_T,
	PIPE_T,
	INREDI_T,
	OUTREDI_TRUNC_T,
	OUTREDI_APPEN_T,
	HEREDOC_T,
	HEREDOC_NOEX_T,
	HEREDOC_EX_T,
	OR_T,
	AND_T,
	ERROR_T
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*word;
}	t_token;

typedef struct s_env
{
	char	*name;
	char	*value;
}	t_env;

typedef struct s_info
{
	t_list	*env;
	int		ret;
	int		prompt_indent;
	char	*pwd;
}	t_info;

typedef struct s_redi
{
	t_token_type	type;
	char			*file;
}	t_redi;

typedef struct s_cmd
{
	t_list		*args;
	t_list		*redi;
}	t_cmd;

typedef struct s_tree
{
	t_token_type	type;
	struct s_tree	*left;
	struct s_tree	*right;
	t_list			*cmds;
}	t_tree;

typedef struct s_defaults
{
	t_list	*env_list;
	char	**env;
	char	**path;
	int		pipes[2];
	int		bef_pipe_fd;
	int		infile_fd;
	int		outfile_fd;
	int		cnt_child;
	char	*now_loc;
}	t_defaults;

# define DQUOTE_IN	0
# define SQUOTE_IN	1
# define QUOTE_OUT	2

# define SUB_TAB	0x2
# define SUB_SPACE	0x3
# define SUB_DOLLAR	0x4
# define SUB_DQUOTE	0x5
# define SUB_SQUOTE	0x6
# define SUB_OPENP	0x7
# define SUB_CLOSEP	0x8
# define SUB_LT		0xe
# define SUB_GT		0xf
# define SUB_OR		0x10
# define SUB_AND	0x11
# define PATH_MAX 4096

# define SUB_WILDCARD -100

# define ARGUMENT_ERROR 0
# define PIPE_CREATE_ERROR 1
# define FORK_ERROR 2 
# define FILE_ACCESS_ERROR 3
# define OPEN_ERROR 4
# define MALLOC_ERROR 5
# define INVALID_CMD 6
# define EXECUVE_ERROR 7
# define CLOSE_ERROR 8
# define AMBIGUOS_ERROR 9
# define COMMAND_NOT_FOUND 10
# define NO_SUCH_FILE 11

# define TRUE 1
# define FALSE 0

# define TYPE_DIR 4

# define INIT_FD -2

# define HEREDOC_NAME "/tmp/heredoc"

typedef struct s_var
{
	size_t	start;
	size_t	len;
	char	*v;
	char	*n;
}	t_var;

# define HEREDOC_PROMPT "> "
# define DOLLAR_START 0
# define DOLLAR_END 1 

typedef struct s_cnode
{
	char	c;
}	t_cnode;

typedef struct s_h_arg
{
	int		size;
	char	c;
	int		flag;
	int		is_first;
	ssize_t	in_fd;
	ssize_t	out_fd;
}	t_h_arg;

#endif
