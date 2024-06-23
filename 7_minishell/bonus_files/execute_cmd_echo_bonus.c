/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd_echo_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:25:12 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 12:25:12 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	find_n_flag(t_list *cmds)
{
	char			*content;
	unsigned int	idx;

	if (!cmds)
		return (FALSE);
	idx = 2;
	content = cmds->content;
	if (ft_strncmp(content, "-n", 2) == 0)
	{
		while (content[idx] == 'n')
			idx++;
		if (content[idx] == '\0')
			return (TRUE);
	}
	return (FALSE);
}

int	execute_cmd_echo(t_list *cmds)
{
	char	*content;
	int		enter_flag;

	enter_flag = TRUE;
	while (find_n_flag(cmds) == TRUE)
	{	
		enter_flag = FALSE;
		cmds = cmds->next;
	}
	while (cmds)
	{
		content = cmds->content;
		write(1, content, ft_strlen(content));
		if (cmds->next)
			write(1, " ", 1);
		cmds = cmds->next;
	}
	if (enter_flag == TRUE)
		write(1, "\n", 1);
	return (0);
}
