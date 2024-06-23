/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pattern_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:09:07 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/03/17 14:18:44 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace_bonus.h"

t_color	get_checker(t_hit_info *hit, t_color c)
{
	const int	u2 = floor(hit->len_u * CHECKER_N);
	const int	v2 = floor(hit->len_v * CHECKER_N);

	if ((u2 + v2) % 2)
		return (c);
	return (color(255, 255, 255));
}
