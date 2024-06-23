/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semjeong <semjeong@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:17:54 by semjeong          #+#    #+#             */
/*   Updated: 2024/03/17 11:14:23 by semjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

static void	map_texture(t_vars *vars, t_hit_info *hit, t_plane *p)
{
	int		u;
	int		v;
	double	bu;
	double	bv;

	u = ((int)floor(hit->len_u * vars->texture.bumpmap.width)) \
		% vars->texture.bumpmap.width;
	v = ((int)floor(hit->len_v * vars->texture.bumpmap.height)) \
		% vars->texture.bumpmap.height;
	bu = (get_pixel_grayscale(&vars->texture.bumpmap, \
		(u + 1) % vars->texture.bumpmap.width, v) \
		- get_pixel_grayscale(&vars->texture.bumpmap, u, v)) / 127.0;
	bv = (get_pixel_grayscale(&vars->texture.bumpmap, u, (v + 1) \
		% vars->texture.bumpmap.height) \
		- get_pixel_grayscale(&vars->texture.bumpmap, u, v)) / 127.0;
	hit->n = vec_unit(vec_plus(hit->n, \
		vec_plus(vec_mul(vec_cross(p->axis_x, hit->n), bv), \
		vec_mul(vec_cross(p->axis_y, hit->n), bu))));
	hit->color = get_pixel_color(&vars->texture.pixel_color, u, v);
}

static void	update_plane_hit_info(t_hit_info *hit, t_plane *p, t_ray *r,
	t_vars *vars)
{
	t_vec	pp;

	pp = vec_sub(hit->p, p->pos);
	hit->len_u = vec_dot(p->axis_x, pp);
	hit->len_u = hit->len_u - (int)hit->len_u;
	if (hit->len_u < 0)
		hit->len_u += 1;
	hit->len_v = vec_dot(p->axis_y, pp);
	hit->len_v = hit->len_v - (int)hit->len_v;
	if (hit->len_v < 0)
		hit->len_v += 1;
	hit->n = p->normal;
	hit->front_face = vec_dot(hit->n, r->d) < 0;
	if (!hit->front_face)
		hit->n = vec_mul(hit->n, -1);
	if (vars->info->flag & FLAG_TEXTURE)
		map_texture(vars, hit, p);
	else if (vars->info->flag & FLAG_CHECKER)
		hit->color = get_checker(hit, p->color);
	else
		hit->color = p->color;
}

int	shoot_ray_to_plane(t_vars *vars, t_plane *p, t_ray *r, t_hit_info *hit)
{
	t_vec	ea;
	double	dn;
	double	t;

	ea = vec_sub(p->pos, r->pos);
	dn = vec_dot(r->d, p->normal);
	if (fabs(dn) < EPSILON)
		return (0);
	t = vec_dot(ea, p->normal) / dn;
	if (t >= hit->t_min && t < hit->t_max)
	{
		hit->t_max = t;
		hit->p = vec_plus(r->pos, vec_mul(r->d, hit->t_max));
		update_plane_hit_info(hit, p, r, vars);
		return (1);
	}
	return (0);
}
