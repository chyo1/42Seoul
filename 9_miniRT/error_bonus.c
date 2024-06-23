/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:09:38 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/03/17 14:19:37 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_bonus.h"

void	error(t_error_type type)
{
	char	*msg;

	msg = "";
	ft_putstr_fd("ERROR\n", 2);
	if (type == DEFAULT_ERR)
		msg = "error";
	else if (type == MALLOC_ERR)
		msg = "malloc failed";
	else if (type == FILE_ERR)
		msg = "file error";
	else if (type == INVALID_ID_ERR)
		msg = "invalid id";
	else if (type == INVALID_FORMAT_ERR)
		msg = "invalid format";
	else if (type == DIVIDE_BY_ZERO)
		msg = "division by zero";
	else if (type == INVALID_ARGNUM_ERR)
		msg = "invalid argument number";
	ft_putendl_fd(msg, 2);
	exit(1);
}

void	free_arr(char **arr)
{
	char	**ori;

	ori = arr;
	while (*arr)
	{
		free(*arr);
		arr++;
	}
	free(ori);
}
