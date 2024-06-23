/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:30:07 by younghoc          #+#    #+#             */
/*   Updated: 2023/08/10 11:38:50 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#include <input.h>
#include <vector.h>
#include <ft_atoi.h>
#include <ft_string.h>
#include <utils.h>

int	readline(int fd, t_vector **vector)
{
	int			n;
	char		c;

	*vector = new_vector();
	if (*vector == NULL)
		return (0);
	n = read(fd, &c, 1);
	while (1)
	{
		if (n <= 0 || c == '\0')
			return (1);
		if (c == '\n')
			break ;
		if (vector_push(*vector, c))
			return (1);
		n = read(fd, &c, 1);
	}
	if (vector_push(*vector, '\0'))
		return (1);
	return (0);
}

int	parse_header_empty_obstacle(t_vector *vector, t_map *map)
{
	if (vector->len < 5)
		return (1);
	map->empty = vector->arr[vector->len - 4];
	map->obstacle = vector->arr[vector->len - 3];
	map->full = vector->arr[vector->len - 2];
	if (!is_printable(map->empty)
		|| !is_printable(map->obstacle)
		|| !is_printable(map->full))
		return (1);
	if (map->empty == map->obstacle
		|| map->obstacle == map->full
		|| map->full == map->empty)
		return (1);
	return (0);
}

int	parse_header(int fd, t_map *map)
{
	t_vector	*vector;

	if (readline(fd, &vector))
	{
		free_vector(vector);
		return (1);
	}
	map->h = ft_atoi(vector->arr, vector->len - 4);
	if (map->h < 0 || 200000000 < map->h)
	{
		free_vector(vector);
		return (1);
	}
	if (parse_header_empty_obstacle(vector, map))
	{
		free_vector(vector);
		return (1);
	}
	free_vector(vector);
	return (0);
}

int	parse_body(int fd, t_map *map)
{
	t_vector	*vector;
	int			i;

	i = 0;
	while (i < map->h)
	{
		if (readline(fd, &vector))
		{
			free_vector(vector);
			intermediate_free_map(map, i);
			return (1);
		}
		map->map[i] = vector->arr;
		free(vector);
		i++;
	}
	if (map->h != 0)
		map->w = ft_strlen(map->map[0]);
	if (check_validation_map(map))
	{
		free_map_map(*map);
		return (1);
	}
	return (0);
}

int	parse_map(int fd, t_map *map)
{
	char	c;

	if (parse_header(fd, map))
		return (1);
	map->map = malloc(sizeof(char *) * map->h);
	if (map->map == NULL)
		return (1);
	if (parse_body(fd, map))
		return (1);
	if (read(fd, &c, 1) != 0)
	{
		free_map_map(*map);
		return (1);
	}
	return (0);
}
