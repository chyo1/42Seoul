/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   postprocess.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:49:23 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 12:57:20 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_type.h"

void	restore_asterisk(char *str)
{
	while (str && *str)
	{
		if (*str == SUB_WILDCARD)
			*str = '*';
		str++;
	}
}

void	postprocess(void *p)
{
	static const char	sub[] = {SUB_TAB, SUB_SPACE, SUB_DOLLAR, SUB_DQUOTE,
		SUB_SQUOTE, SUB_OPENP, SUB_CLOSEP, SUB_LT, SUB_GT, SUB_OR, SUB_AND, 0};
	static const char	*ori = "\t $\"\'()<>|&";
	char				*str;
	int					i;

	str = p;
	while (str && *str)
	{
		i = -1;
		while (sub[++i])
		{
			if (sub[i] == *str)
			{
				*str = ori[i];
				break ;
			}
		}
		str++;
	}
}
