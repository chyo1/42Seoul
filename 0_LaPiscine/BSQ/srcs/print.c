/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:21:00 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/08/09 19:29:10 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <input.h>
#include <find_square.h>
#include <print.h>

void	print_map(t_map map)
{
	int	i;

	i = 0;
	while (i < map.h)
	{
		write(1, map.map[i], map.w);
		write(1, "\n", 1);
		i++;
	}
}

void	ft_puterr(char *str)
{
	while (*str)
		write(2, str++, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}
