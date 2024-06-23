/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_builtin_func_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:14:01 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 16:30:38 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	check_builtin_func(t_cmd *cmds)
{
	t_list	*cmd;

	cmd = cmds->args;
	if (!cmd)
		return (FALSE);
	if (ft_strcmp(cmd->content, "cd") == 0
		|| ft_strcmp(cmd->content, "echo") == 0
		|| ft_strcmp(cmd->content, "env") == 0
		|| ft_strcmp(cmd->content, "exit") == 0
		|| ft_strcmp(cmd->content, "export") == 0
		|| ft_strcmp(cmd->content, "unset") == 0
		|| ft_strcmp(cmd->content, "pwd") == 0)
		return (TRUE);
	return (FALSE);
}

static int	execute_builtin_func(t_cmd *cmds, t_info *info, pid_t is_child)
{
	t_list	*cmd;

	cmd = cmds->args;
	if (ft_strcmp(cmd->content, "cd") == 0)
		return (execute_cmd_cd(cmd->next, info));
	if (ft_strcmp(cmd->content, "echo") == 0)
		return (execute_cmd_echo(cmd->next));
	if (ft_strcmp(cmd->content, "env") == 0)
		return (execute_cmd_env(info->env));
	if (ft_strcmp(cmd->content, "exit") == 0)
		return (execute_cmd_exit(cmds->args, is_child));
	if (ft_strcmp(cmd->content, "export") == 0)
		return (execute_cmd_export(cmds->args, info));
	if (ft_strcmp(cmd->content, "unset") == 0)
		return (execute_cmd_unset(&info->env, cmd->next));
	if (ft_strcmp(cmd->content, "pwd") == 0)
		return (execute_cmd_pwd(info));
	return (0);
}

static int	do_parent_redirection(t_defaults *def, t_cmd *cmds, pid_t pid)
{
	int	ret_val;

	ret_val = check_redirection(def, cmds, pid);
	if (def->infile_fd != INIT_FD)
	{
		dup2(def->infile_fd, STDIN_FILENO);
		close(def->infile_fd);
	}
	if (def->outfile_fd != INIT_FD)
	{
		dup2(def->outfile_fd, STDOUT_FILENO);
		close(def->outfile_fd);
	}
	return (ret_val);
}

int	do_builtin_func(t_defaults *def, t_cmd *cmds, t_info *info, pid_t is_child)
{
	int	std_fd[2];
	int	return_value;

	return_value = 0;
	if (is_child != 0)
	{
		std_fd[0] = dup(STDIN_FILENO);
		std_fd[1] = dup(STDOUT_FILENO);
		return_value = do_parent_redirection(def, cmds, is_child);
	}
	if (!return_value)
		return_value = execute_builtin_func(cmds, info, is_child);
	if (is_child == 0)
		exit (info->ret);
	else
	{
		dup2(std_fd[0], STDIN_FILENO);
		dup2(std_fd[1], STDOUT_FILENO);
		close(std_fd[0]);
		close(std_fd[1]);
	}
	return (return_value);
}
