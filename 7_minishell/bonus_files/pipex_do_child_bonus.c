/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_do_child_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:00:12 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 12:44:10 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	execute_func(t_defaults *def, t_list *cmds, t_info *info, int pid)
{
	child_signal_handler();
	check_redirect_n_dup_fd(def, cmds->content, cmds, pid);
	if (check_builtin_func(cmds->content) == TRUE)
		do_builtin_func(def, cmds->content, info, pid);
	else
		read_n_write_pipes(def, ((t_cmd *)cmds->content)->args);
}

int	do_child(t_defaults *def, t_list *cmds, t_info *info)
{
	pid_t	child_pid;

	def->bef_pipe_fd = dup(STDIN_FILENO);
	while (cmds)
	{
		if (pipe(def->pipes) == -1)
			print_error_n_exit(PIPE_CREATE_ERROR, NULL, 1);
		def->cnt_child++;
		child_pid = fork();
		if (child_pid == -1)
			print_error_n_exit(FORK_ERROR, NULL, 1);
		if (child_pid == 0)
			execute_func(def, cmds, info, child_pid);
		else
			parent_signal_ignore();
		close(def->bef_pipe_fd);
		close(def->pipes[1]);
		def->bef_pipe_fd = def->pipes[0];
		cmds = cmds->next;
	}
	close(def->pipes[0]);
	return (child_pid);
}

void	read_n_write_pipes(t_defaults *def, t_list *cmd_list)
{
	char	*path;
	char	**cmd;

	if (!cmd_list)
		exit (0);
	cmd = list_to_matrix(cmd_list);
	if (!cmd)
	{
		if (def->infile_fd != INIT_FD)
			close(def->infile_fd);
		if (def->outfile_fd != INIT_FD)
			close(def->outfile_fd);
		exit (0);
	}
	else
		path = find_n_make_path(def->path, cmd[0]);
	if (!path)
		return ;
	execve(path, cmd, def->env);
	print_error_n_exit(EXECUVE_ERROR, path, 0);
}
