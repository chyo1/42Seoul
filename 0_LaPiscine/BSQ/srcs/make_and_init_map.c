/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_and_init_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:14:08 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/08/09 19:29:00 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

#include <input.h>
#include <find_square.h>

void	init_vertical(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->h)
	{
		if (map->map[i][0] == map->empty)
			map->ans[i][0] = 1;
		else if (map->map[i][0] == map->obstacle)
			map->ans[i][0] = 0;
		i++;
	}
}

void	init_horizon(t_map *map)
{
	int	j;

	j = 0;
	while (j < map->w)
	{
		if (map->map[0][j] == map->empty)
			map->ans[0][j] = 1;
		else if (map->map[0][j] == map->obstacle)
			map->ans[0][j] = 0;
		j++;
	}
}

void	init_o_area(t_map *map)
{
	int	i;
	int	j;

	i = 1;
	while (i < map->h)
	{
		j = 1;
		while (j < map->w)
		{
			if (map->map[i][j] == map->obstacle)
				map->ans[i][j] = 0;
			else
				map->ans[i][j] = 1;
			j++;
		}
		i++;
	}
}

int	make_map(t_map *map)
{
	int	i;

	map->ans = malloc(sizeof(int *) * map->h);
	if (map->ans == NULL)
		return (1);
	i = 0;
	while (i < map->h)
	{
		map->ans[i] = malloc(sizeof(int) * map->w);
		if (map->ans[i] == NULL)
			return (1);
		i++;
	}
	init_vertical(map);
	init_horizon(map);
	init_o_area(map);
	return (0);
}
