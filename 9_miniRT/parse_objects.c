/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:34:47 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/03/17 12:46:46 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	parse_sphere(t_list **lst, char **arr)
{
	t_sphere	*s;
	t_object	*obj;

	if (get_arr_size(arr) != 3)
		error(INVALID_FORMAT_ERR);
	s = (t_sphere *)ft_calloc(sizeof(t_sphere), 1);
	obj = (t_object *)ft_calloc(sizeof(t_object), 1);
	parse_vector(arr[0], &s->pos, 0);
	s->diameter = parse_double(arr[1], 0);
	s->r = s->diameter / 2;
	parse_colors(arr[2], &s->color);
	obj->obj = s;
	obj->type = OBJ_SP;
	ft_lstadd_front(lst, ft_lstnew(obj));
}

void	parse_plane(t_list **lst, char **arr)
{
	t_plane		*p;
	t_object	*obj;

	if (get_arr_size(arr) != 3)
		error(INVALID_FORMAT_ERR);
	p = (t_plane *)ft_calloc(sizeof(t_plane), 1);
	obj = (t_object *)ft_calloc(sizeof(t_object), 1);
	parse_vector(arr[0], &p->pos, 0);
	parse_dir_vector(arr[1], &p->normal);
	parse_colors(arr[2], &p->color);
	obj->obj = p;
	obj->type = OBJ_PL;
	ft_lstadd_front(lst, ft_lstnew(obj));
}

void	parse_cylinder(t_list **lst, char **arr)
{
	t_cylinder	*c;
	t_object	*obj;

	if (get_arr_size(arr) != 5)
		error(INVALID_FORMAT_ERR);
	c = (t_cylinder *)ft_calloc(sizeof(t_cylinder), 1);
	obj = (t_object *)ft_calloc(sizeof(t_object), 1);
	parse_vector(arr[0], &c->pos, 0);
	parse_dir_vector(arr[1], &c->axis);
	c->diameter = parse_double(arr[2], 0);
	c->r = c->diameter / 2;
	c->height = parse_double(arr[3], 0);
	parse_colors(arr[4], &c->color);
	obj->obj = c;
	obj->type = OBJ_CY;
	ft_lstadd_front(lst, ft_lstnew(obj));
}

void	parse_cone(t_list **list, char **arr)
{
	t_cone		*cone;
	t_object	*obj;

	if (get_arr_size(arr) != 5)
		error(INVALID_FORMAT_ERR);
	cone = (t_cone *)ft_calloc(sizeof(t_cone), 1);
	obj = (t_object *)ft_calloc(sizeof(t_object), 1);
	parse_vector(arr[0], &cone->pos, 0);
	parse_dir_vector(arr[1], &cone->axis);
	cone->angle = parse_double(arr[2], 0);
	if (!(0 < cone->angle && cone->angle < 90))
		error(INVALID_FORMAT_ERR);
	cone->angle = cone->angle * PI / 180;
	cone->height = parse_double(arr[3], 0);
	parse_colors(arr[4], &cone->color);
	obj->obj = cone;
	obj->type = OBJ_CO;
	ft_lstadd_front(list, ft_lstnew(obj));
}

void	parse_objects(t_info *info, char **arr)
{
	if (ft_strcmp(*arr, SPHERE_ID) == 0)
		parse_sphere(&info->objs, arr + 1);
	else if (ft_strcmp(*arr, PLANE_ID) == 0)
		parse_plane(&info->objs, arr + 1);
	else if (ft_strcmp(*arr, CYLINDER_ID) == 0)
		parse_cylinder(&info->objs, arr + 1);
	else if (ft_strcmp(*arr, CONE_ID) == 0)
		parse_cone(&info->objs, arr + 1);
	else
		error(INVALID_ID_ERR);
}
