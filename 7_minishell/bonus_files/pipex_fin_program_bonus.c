/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_fin_program_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:45:56 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 12:44:23 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	print_ambiguos_error(char *file_name, pid_t pid, int *ret_val)
{
	write (2, "minishell: ", 11);
	write (2, file_name, ft_strlen(file_name));
	write (2, ": ambiguous redirect\n", 21);
	if (pid == 0)
		exit (1);
	*ret_val = 1;
}

static void	print_command_error(char *file_name, pid_t pid, int *ret_val)
{
	write (2, "minishell: ", 11);
	write (2, file_name, ft_strlen(file_name));
	write (2, ": command not found\n", 20);
	if (pid == 0)
		exit (127);
	*ret_val = 127;
}

static void	print_no_such_file_error(char *file_name, pid_t pid, int *ret_val)
{
	write (2, "minishell: ", 11);
	write (2, file_name, ft_strlen(file_name));
	write (2, ": No such file or directory\n", 28);
	if (pid == 0)
		exit (127);
	*ret_val = 127;
}

static void	print_execve_error(char *file_name, pid_t pid, int *ret_val)
{
	struct stat	buffer;

	write (2, "minishell: ", 11);
	if (stat(file_name, &buffer) == 0)
	{
		if (S_ISDIR(buffer.st_mode))
		{
			write (2, file_name, ft_strlen(file_name));
			write(2, ": is a directory\n", 17);
		}
		else
			perror("");
	}
	if (pid == 0)
		exit(126);
	*ret_val = 126;
}

int	print_error_n_exit(int which, char *file_name, pid_t pid)
{
	int	ret_val;

	ret_val = 1;
	if (which == FILE_ACCESS_ERROR || which == OPEN_ERROR)
	{
		write (2, "minishell: ", 11);
		perror("");
	}
	else if (which == EXECUVE_ERROR)
		print_execve_error(file_name, pid, &ret_val);
	else if (which == AMBIGUOS_ERROR)
		print_ambiguos_error(file_name, pid, &ret_val);
	else if (which == COMMAND_NOT_FOUND)
		print_command_error(file_name, pid, &ret_val);
	else if (which == NO_SUCH_FILE)
		print_no_such_file_error(file_name, pid, &ret_val);
	if (pid == 0)
		exit(1);
	return (ret_val);
}
