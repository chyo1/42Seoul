/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pattern.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:07:19 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/03/15 20:07:20 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

t_color	get_checker(t_hit_info *hit, t_color c)
{
	const int	u2 = floor(hit->len_u * CHECKER_N);
	const int	v2 = floor(hit->len_v * CHECKER_N);

	if ((u2 + v2) % 2)
		return (c);
	return (color(255, 255, 255));
}
