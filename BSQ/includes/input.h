/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:40:38 by younghoc          #+#    #+#             */
/*   Updated: 2023/08/09 20:20:04 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "vector.h"

typedef struct s_map
{
	char	**map;
	int		**ans;
	int		h;
	int		w;
	char	empty;
	char	obstacle;
	char	full;
}t_map;

int		readline(int fd, t_vector **vector);
int		parse_map(int fd, t_map *map);
int		check_validation_map(t_map *map);
int		check_validation_empty_obstacle(t_map *map);
void	free_map(t_map map);
void	free_map_map(t_map map);
void	intermediate_free_map(t_map *map, int i);

#endif
