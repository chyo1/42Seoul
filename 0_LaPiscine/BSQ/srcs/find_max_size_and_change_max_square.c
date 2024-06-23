/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:33:21 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/08/09 19:27:40 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <input.h>
#include <find_square.h>

void	change_max_square(t_map pearl_map, int *idx, int size);

int	get_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	change_max_idx(int *idx, int i, int j)
{
	idx[0] = i;
	idx[1] = j;
}

void	find_max_size(t_map map)
{
	int	i;
	int	j;
	int	max_idx[2];
	int	max_size;

	i = 0;
	max_size = 0;
	while (++i < map.h)
	{
		j = 0;
		while (++j < map.w)
		{
			if (map.ans[i][j] == 0)
				continue ;
			map.ans[i][j] = get_min(map.ans[i - 1][j - 1], map.ans[i - 1][j]);
			map.ans[i][j] = get_min(map.ans[i][j - 1] + 1, map.ans[i][j] + 1);
			if (max_size >= map.ans[i][j])
				continue ;
			max_size = map.ans[i][j];
			change_max_idx(max_idx, i, j);
		}
	}
	if (max_size > 1)
		change_max_square(map, max_idx, max_size - 1);
}

void	change_max_square(t_map map, int *idx, int size)
{
	int	end_point_x;
	int	end_point_y;
	int	i;
	int	j;
	int	first_j_val;

	end_point_x = idx[0];
	end_point_y = idx[1];
	i = end_point_x - size;
	first_j_val = end_point_y - size;
	while (i <= end_point_x)
	{
		j = first_j_val;
		while (j <= end_point_y)
		{
			map.map[i][j] = map.full;
			j++;
		}
		i++;
	}
}
