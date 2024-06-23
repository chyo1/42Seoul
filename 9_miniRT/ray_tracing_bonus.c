/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:11:54 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/03/17 14:27:27 by semjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace_bonus.h"

int	shoot_ray_to_objects(t_vars *vars, t_list *objs, t_ray *r, t_hit_info *hit)
{
	t_object	*obj;
	int			ret;

	ret = 0;
	while (objs)
	{
		obj = objs->content;
		if (obj->type == OBJ_SP)
			ret |= shoot_ray_to_sphere(vars, obj->obj, r, hit);
		else if (obj->type == OBJ_PL)
			ret |= shoot_ray_to_plane(vars, obj->obj, r, hit);
		else if (obj->type == OBJ_CY)
			ret |= shoot_ray_to_cylinder(vars, obj->obj, r, hit);
		else if (obj->type == OBJ_CO)
			ret |= shoot_ray_to_cone(vars, obj->obj, r, hit);
		objs = objs->next;
	}
	return (ret);
}

t_color	shoot_ray_to_viewport(t_vars *vars, t_ray *r)
{
	t_info		*info;
	t_hit_info	hit;

	info = vars->info;
	hit.t_min = EPSILON;
	hit.t_max = INFINITY;
	if (shoot_ray_to_objects(vars, info->objs, r, &hit))
		return (phong_lighting(vars, info, r, &hit));
	return (color(0, 0, 0));
}
