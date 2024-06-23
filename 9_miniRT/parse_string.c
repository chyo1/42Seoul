/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:44:10 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/03/15 20:46:01 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	is_space(char c)
{
	return (c == ' ');
}

int	is_all_space(char *line)
{
	while (line)
	{
		if (!is_space(*line))
			return (0);
		line++;
	}
	return (1);
}

int	get_arr_size(char **arr)
{
	int	size;

	size = 0;
	while (arr[size])
		size++;
	return (size);
}

void	trim_newline(char *in)
{
	size_t	len;

	len = ft_strlen(in);
	if (in[len - 1] == '\n')
		in[len - 1] = 0;
}
