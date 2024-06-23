/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:05:19 by younghoc          #+#    #+#             */
/*   Updated: 2023/08/08 19:05:01 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIND_SQUARE_H
# define FIND_SQUARE_H

int		make_map(t_map *map);
void	find_max_size(t_map map);
void	find_max_size_at_horizon(t_map map);
void	find_max_size_at_vertical(t_map map);

#endif
