/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd_exit_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:41:47 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 12:41:48 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	is_str_digit(char *str)
{
	unsigned int	idx;

	if (str[0] == '\0')
		return (FALSE);
	idx = 0;
	if (str[idx] == '+' || str[idx] == '-')
		idx++;
	while (str[idx])
	{
		if (!ft_isdigit(str[idx]))
			return (FALSE);
		idx++;
	}
	return (TRUE);
}

static int	check_num_range(t_list *args)
{
	char	*str;
	int		minus_flag;
	int		idx;

	minus_flag = FALSE;
	str = args->content;
	if (ft_strlen(str) > 20)
		return (TRUE);
	idx = 0;
	if (str[idx] == '+' || str[idx] == '-')
	{
		if (str[idx] == '-')
			minus_flag = TRUE;
		idx++;
	}
	if (ft_strlen(&str[idx]) == 19)
	{
		if (minus_flag && ft_strncmp(&str[idx], "9223372036854775808", 19) > 0)
			return (TRUE);
		else if (!minus_flag && \
			ft_strncmp(&str[idx], "9223372036854775807", 19) > 0)
			return (TRUE);
	}
	return (FALSE);
}

int	execute_cmd_exit(t_list *args, pid_t is_child)
{
	unsigned char	exit_code;

	exit_code = 0;
	if (is_child)
		write(1, "exit\n", 5);
	if (args->next)
	{
		if (!is_str_digit(args->next->content) || check_num_range(args->next))
		{
			write (2, "minishell: exit: ", 17);
			write (2, args->next->content, ft_strlen(args->next->content));
			write (2, ": numeric argument required\n", 28);
			exit(255);
		}
		if (is_str_digit(args->next->content) == TRUE && !args->next->next)
			exit_code = ft_atoi(args->next->content);
		else if (args->next->next)
		{
			exit_code = 1;
			write (2, "minishell: exit: too many arguments\n", 36);
			return (1);
		}
	}
	exit(exit_code);
	return (0);
}
