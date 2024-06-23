/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objs_axis_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:10:11 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/03/17 14:18:44 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace_bonus.h"

static void	get_plane_axis(t_plane *plane)
{
	t_vec	x;
	t_vec	y;

	x = vec(1, 0, 0);
	y = vec(0, 1, 0);
	plane->axis_x = vec_unit(vec_cross(y, plane->normal));
	if (vec_length(plane->axis_x) < EPSILON)
		plane->axis_x = x;
	plane->axis_y = vec_unit(vec_cross(plane->normal, plane->axis_x));
}

static void	get_cylinder_axis(t_cylinder *cylinder)
{
	t_vec	x;
	t_vec	y;

	x = vec(1, 0, 0);
	y = vec(0, 1, 0);
	cylinder->axis_x = vec_unit(vec_cross(y, cylinder->axis));
	if (vec_length(cylinder->axis_x) < EPSILON)
		cylinder->axis_x = x;
	cylinder->axis_y = vec_unit(vec_cross(cylinder->axis, cylinder->axis_x));
}

static void	get_cone_axis(t_cone *cone)
{
	t_vec	x;
	t_vec	y;

	x = vec(1, 0, 0);
	y = vec(0, 1, 0);
	cone->axis_x = vec_unit(vec_cross(cone->axis, y));
	if (vec_length(cone->axis_x) < EPSILON)
		cone->axis_x = x;
	cone->axis_y = vec_unit(vec_cross(cone->axis, cone->axis_x));
}

void	get_objs_axis(t_list *objs)
{
	t_list		*tmp;
	t_object	*obj;

	tmp = objs;
	while (tmp)
	{
		obj = tmp->content;
		if (obj->type == OBJ_PL)
			get_plane_axis(obj->obj);
		else if (obj->type == OBJ_CY)
			get_cylinder_axis(obj->obj);
		else if (obj->type == OBJ_CO)
			get_cone_axis(obj->obj);
		tmp = tmp->next;
	}
}
