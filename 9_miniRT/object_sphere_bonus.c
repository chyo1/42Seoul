/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_sphere_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:10:58 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/03/17 14:18:44 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace_bonus.h"

void	get_circle_uv(t_hit_info *hit, t_sphere *sphere)
{
	t_vec	point;
	double	t;

	point = vec_sub(hit->p, sphere->pos);
	t = point.z / sphere->r;
	hit->len_u = acos(t);
	t = point.x / (sphere->r * sin(hit->len_u));
	hit->len_u /= PI;
	hit->len_v = check_acos(t);
	if (point.y < EPSILON)
		hit->len_v = 2 * PI - hit->len_v;
	hit->len_v /= 2 * PI;
}

static void	map_texture(t_vars *vars, t_hit_info *hit)
{
	int		u;
	int		v;
	double	uu;
	double	vv;

	if (hit->len_u < 0)
		hit->len_u += 1;
	if (hit->len_v < 0)
		hit->len_v += 1;
	uu = hit->len_u;
	vv = hit->len_v;
	u = ((int)floor(uu * vars->texture.bumpmap.width))
		% vars->texture.bumpmap.width;
	v = ((int)floor(vv * vars->texture.bumpmap.height)) \
		% vars->texture.bumpmap.height;
	uu = (get_pixel_grayscale(&vars->texture.bumpmap, \
		(u + 1) % vars->texture.bumpmap.width, v) \
		- get_pixel_grayscale(&vars->texture.bumpmap, u, v)) / 127.0;
	vv = (get_pixel_grayscale(&vars->texture.bumpmap, u, \
		(v + 1) % vars->texture.bumpmap.height) \
		- get_pixel_grayscale(&vars->texture.bumpmap, u, v)) / 127.0;
	hit->n = vec_unit(vec_plus(hit->n, \
		vec_plus(vec_mul(vec_cross(vec(1, 0, 0), hit->n), vv), \
		vec_mul(vec_cross(vec(0, 1, 0), hit->n), uu))));
	hit->color = get_pixel_color(&vars->texture.pixel_color, u, v);
}

static void	update_sphere_hit_info(t_hit_info *hit, t_ray *r, t_sphere *sphere,
	t_vars *vars)
{
	hit->p = vec_plus(r->pos, vec_mul(r->d, hit->t_max));
	get_circle_uv(hit, sphere);
	hit->n = vec_unit(vec_sub(hit->p, sphere->pos));
	hit->front_face = vec_dot(hit->n, r->d) < 0;
	if (!hit->front_face)
		hit->n = vec_mul(hit->n, -1);
	if (vars->info->flag & FLAG_TEXTURE)
		map_texture(vars, hit);
	else if (vars->info->flag & FLAG_CHECKER)
		hit->color = get_checker(hit, sphere->color);
	else
		hit->color = sphere->color;
}

int	shoot_ray_to_sphere(t_vars *vars, t_sphere *sphere,
	t_ray *r, t_hit_info *hit)
{
	const t_vec	ce = vec_sub(r->pos, sphere->pos);
	t_quad_eq	sol;

	sol.a = vec_dot(r->d, r->d);
	sol.b = vec_dot(ce, r->d);
	sol.c = vec_dot(ce, ce) - sphere->r * sphere->r;
	solve_quardatic_eq(&sol);
	if (sol.discriminant < 0)
		return (0);
	if (update_hit_info(&sol, hit))
	{
		update_sphere_hit_info(hit, r, sphere, vars);
		return (1);
	}
	return (0);
}
