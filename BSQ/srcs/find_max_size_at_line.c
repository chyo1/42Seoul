/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_size_at_line.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:02:50 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/08/09 19:27:46 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <input.h>

void	change_max_square(t_map map, int *idx, int size);

void	find_max_size_at_horizon(t_map map)
{
	int	j;
	int	max_idx[2];
	int	max_size;

	max_size = 0;
	j = 0;
	while (j < map.w)
	{
		if (map.ans[0][j] == 1)
		max_size = map.ans[0][j];
		max_idx[0] = 0;
		max_idx[1] = j;
		j++;
		break ;
	}
	if (max_size)
		change_max_square(map, max_idx, max_size - 1);
}

void	find_max_size_at_vertical(t_map map)
{
	int	i;
	int	max_idx[2];
	int	max_size;

	i = 0;
	max_size = 0;
	while (i < map.h)
	{
		if (map.ans[i][0] == 1)
		max_size = map.ans[i][0];
		max_idx[0] = i;
		max_idx[1] = 0;
		i++;
		break ;
	}
	if (max_size)
		change_max_square(map, max_idx, max_size - 1);
}
