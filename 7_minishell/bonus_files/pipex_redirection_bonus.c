/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_redirection_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:44:49 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 12:44:50 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	do_infile_redirection(t_defaults *def, t_redi *r_info, pid_t pid)
{
	if (access(r_info->file, F_OK) == -1)
		return (print_error_n_exit(OPEN_ERROR, NULL, pid));
	if (access(r_info->file, R_OK) == -1)
		return (print_error_n_exit(FILE_ACCESS_ERROR, NULL, pid));
	if (def->infile_fd != INIT_FD)
		close(def->infile_fd);
	def->infile_fd = open(r_info->file, O_RDONLY);
	if (def->infile_fd == -1)
		return (print_error_n_exit(OPEN_ERROR, NULL, pid));
	return (0);
}

static int	do_outfile_redirection(t_defaults *def, t_redi *r_info, pid_t pid)
{
	if (def->outfile_fd != INIT_FD)
		close(def->outfile_fd);
	if (r_info->type == OUTREDI_APPEN_T)
		def->outfile_fd = open(r_info->file, O_RDWR | O_CREAT | O_APPEND, 0644);
	else
		def->outfile_fd = open(r_info->file, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (def->outfile_fd == -1)
		return (print_error_n_exit(OPEN_ERROR, NULL, pid));
	return (0);
}

int	check_redirection(t_defaults *def, t_cmd *cmds, pid_t pid)
{
	t_list	*redi;
	t_redi	*r_info;
	int		ret_val;

	ret_val = 0;
	redi = cmds->redi;
	while (redi)
	{
		r_info = (t_redi *)redi->content;
		if (r_info->type == ERROR_T)
			return (print_error_n_exit(AMBIGUOS_ERROR, r_info->file, pid));
		if (r_info->type == INREDI_T || r_info->type == HEREDOC_NOEX_T)
			ret_val = do_infile_redirection(def, r_info, pid);
		if (!ret_val && (r_info->type == OUTREDI_APPEN_T || \
			r_info->type == OUTREDI_TRUNC_T))
			ret_val = do_outfile_redirection(def, r_info, pid);
		if (ret_val)
			return (ret_val);
		redi = redi->next;
	}
	return (ret_val);
}

void	check_redirect_n_dup_fd(t_defaults *def, \
	t_cmd *cmds, t_list *cmd_list, pid_t pid)
{
	check_redirection(def, cmds, pid);
	if (def->infile_fd == INIT_FD)
		dup2(def->bef_pipe_fd, STDIN_FILENO);
	else
		dup2(def->infile_fd, STDIN_FILENO);
	if (def->outfile_fd == INIT_FD && cmd_list->next != NULL)
		dup2(def->pipes[1], STDOUT_FILENO);
	else
		dup2(def->outfile_fd, STDOUT_FILENO);
	if (close(def->pipes[0]) == -1 || close(def->pipes[1]) == -1 \
	|| close(def->bef_pipe_fd) == -1)
		print_error_n_exit(CLOSE_ERROR, NULL, pid);
}
