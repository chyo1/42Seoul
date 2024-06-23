/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:11:44 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/03/17 14:27:27 by semjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"

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
