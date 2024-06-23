/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:48:43 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 18:18:34 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

#include "parse.h"
#include "libft/libft.h"
#include "signal.h"

static void	check_n_add_env_path(t_list **env)
{
	static char	*path_name = "PATH";
	static char	*path_value = "/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin:.";
	t_env		*new_t_env_node;
	t_list		*new_node;
	t_env		*path_loc;

	path_loc = find_name_in_env(*env, "PATH");
	if (path_loc == NULL)
	{
		new_t_env_node = (t_env *)ft_calloc(1, sizeof(t_env));
		new_t_env_node->name = path_name;
		new_t_env_node->value = path_value;
		new_node = ft_lstnew(new_t_env_node);
		ft_lstadd_back(env, new_node);
	}
}

static int	is_all_white(char *in)
{
	while (*in)
	{
		if (*in != ' ' && *in != '\t')
			return (0);
		in++;
	}
	return (1);
}

int	init_info(t_info *info, char *envp[])
{
	info->prompt_indent = 0;
	info->ret = 0;
	info->env = matrix_to_list(envp, env_to_list);
	check_n_add_env_path(&(info->env));
	info->pwd = getcwd(NULL, 0);
	return (1);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	*in;
	t_info	info;

	rl_catch_signals = 0;
	parent_signal_handler();
	if (argc != 1 || argv == 0)
		return (1);
	init_info(&info, envp);
	in = readline(PROMPT);
	while (in)
	{
		info.prompt_indent = 0;
		if (!in || ft_strlen(in) == 0 || is_all_white(in))
		{
			free(in);
			in = readline(PROMPT);
			continue ;
		}
		add_history(in);
		process_input(&info, in);
		free(in);
		in = readline(PROMPT);
	}
	printf("\033[1B\033[1A\033[%dCexit\n", info.prompt_indent * 2 + 11);
	exit(info.ret);
}
