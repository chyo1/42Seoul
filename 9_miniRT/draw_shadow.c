/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shadow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:09:02 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/03/15 20:09:06 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

int	is_shadow(t_vars *vars, t_info *info, t_light *l, t_hit_info *h)
{
	t_hit_info	shadow_hit;
	t_ray		r;

	r.pos = vec_plus(h->p, vec_mul(h->n, 0.0001));
	r.d = vec_sub(l->pos, h->p);
	shadow_hit.t_min = EPSILON;
	shadow_hit.t_max = vec_length(r.d);
	r.d = vec_unit(r.d);
	if (shoot_ray_to_objects(vars, info->objs, &r, &shadow_hit))
		return (1);
	return (0);
}
