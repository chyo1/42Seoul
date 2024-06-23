/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:39:43 by younghoc          #+#    #+#             */
/*   Updated: 2023/08/09 20:19:40 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <input.h>
#include <ft_string.h>

int	check_validation_map(t_map *map)
{
	int	i;

	if (map->h == 0)
		return (1);
	i = 0;
	while (i < map->h)
	{
		if (ft_strlen(map->map[i]) != map->w)
			return (1);
		i++;
	}
	if (check_validation_empty_obstacle(map))
		return (1);
	return (0);
}

int	check_validation_empty_obstacle(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->h)
	{
		j = 0;
		while (j < map->w)
		{
			if (map->map[i][j] != map->empty
				&& map->map[i][j] != map->obstacle)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	free_map_map(t_map map)
{
	int	i;

	i = 0;
	while (i < map.h)
	{
		free(map.map[i]);
		i++;
	}
	free(map.map);
}

void	free_map(t_map map)
{
	int	i;

	i = 0;
	while (i < map.h)
	{
		free(map.map[i]);
		free(map.ans[i]);
		i++;
	}
	free(map.map);
	free(map.ans);
}

void	intermediate_free_map(t_map *map, int i)
{
	while (i--)
		free(map->map[i]);
	free(map->map);
}
