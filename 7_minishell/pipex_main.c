/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:28:07 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 12:05:08 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "signal.h"

static int	fin_child_process(t_defaults def, int last_child_pid)
{
	int	i;
	int	status;
	int	value;

	i = 0;
	while (i < def.cnt_child)
	{
		if (wait(&status) == last_child_pid)
		{
			if (WIFEXITED(status))
				value = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
			{
				value = WTERMSIG(status);
				if (value == SIGINT)
					ft_putendl_fd("", 2);
				else if (value == SIGQUIT)
					ft_putendl_fd("Quit: 3", 2);
				value = WTERMSIG(status) + 128;
			}
		}
		i++;
	}
	parent_signal_handler();
	return (value);
}

static void	free_def(t_defaults *def)
{
	char	**env;
	char	**path;

	env = def->env;
	path = def->path;
	while (env && *env)
	{
		free(*env);
		env++;
	}
	free(def->env);
	while (path && *path)
	{
		free(*path);
		path++;
	}
	free(def->path);
}

int	execute_pipeline(t_list	*cmds, t_info *info)
{
	pid_t		last_child_pid;
	t_defaults	def;
	int			ret_value;

	make_struct_n_pipe(&def, info);
	if (cmds->next == NULL && check_builtin_func(cmds->content) == TRUE)
		ret_value = do_builtin_func(&def, cmds->content, info, 1);
	else
	{
		last_child_pid = do_child(&def, cmds, info);
		ret_value = fin_child_process(def, last_child_pid);
	}
	free_def(&def);
	info->ret = ret_value;
	return (ret_value);
}
