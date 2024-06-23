/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_cone_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:10:45 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/03/17 17:50:55 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace_bonus.h"

static int	check_cone_hit(double t, t_hit_info *hit, t_cone *cone, t_ray *ray)
{
	t_vec	p;
	t_vec	cp;

	p = vec_plus(ray->pos, vec_mul(ray->d, t));
	cp = vec_sub(p, cone->pos);
	return (hit->t_min <= t && t < hit->t_max && \
	0 <= vec_dot(cp, cone->axis) && vec_dot(cp, cone->axis) <= cone->height);
}

static int	cone_update_hit_info(t_quad_eq *sol, \
	t_hit_info *hit, t_ray *ray, t_cone *cone)
{
	int	is_r1_hit;

	is_r1_hit = check_cone_hit(sol->r1, hit, cone, ray);
	if (sol->r1 < sol->r2)
	{
		if (check_cone_hit(sol->r1, hit, cone, ray))
			hit->t_max = sol->r1;
		else if (check_cone_hit(sol->r2, hit, cone, ray))
			hit->t_max = sol->r2;
		else
			return (0);
	}
	else
	{
		if (check_cone_hit(sol->r2, hit, cone, ray))
			hit->t_max = sol->r2;
		else if (check_cone_hit(sol->r1, hit, cone, ray))
			hit->t_max = sol->r1;
		else
			return (0);
	}
	hit->p = vec_plus(ray->pos, vec_mul(ray->d, hit->t_max));
	return (1);
}

static void	map_texture(t_vars *vars, t_cone *cone, t_hit_info *hit)
{
	int		u;
	int		v;
	double	uu;
	double	vv;

	if (hit->len_u < 0)
		hit->len_u += 1;
	uu = hit->len_u;
	vv = hit->len_v;
	u = ((int)floor(uu * vars->texture.bumpmap.width)) \
		% vars->texture.bumpmap.width;
	v = ((int)floor(vv * vars->texture.bumpmap.height)) \
		% vars->texture.bumpmap.height;
	uu = (get_pixel_grayscale(&vars->texture.bumpmap, (u + 1) \
		% vars->texture.bumpmap.width, v) \
			- get_pixel_grayscale(&vars->texture.bumpmap, \
		u % vars->texture.bumpmap.width, v)) / 127.0;
	vv = (get_pixel_grayscale(&vars->texture.bumpmap, u, \
		(v + 1) % vars->texture.bumpmap.height) \
		- get_pixel_grayscale(&vars->texture.bumpmap, u, \
		v % vars->texture.bumpmap.height)) / 127.0;
	hit->n = vec_unit(vec_plus(hit->n, \
		vec_plus(vec_mul(vec_cross(cone->axis_x, hit->n), vv), \
		vec_mul(vec_cross(cone->axis_y, hit->n), uu))));
	hit->color = get_pixel_color(&vars->texture.pixel_color, u, v);
}

static int	update_hit_info_after_hit(t_vars *vars, \
	t_cone *cone, t_ray *ray, t_hit_info *hit)
{
	t_vec		cp;
	double		cc_len;
	t_vec		cc;

	cp = vec_sub(hit->p, cone->pos);
	cc_len = vec_dot(cp, cone->axis);
	cc = vec_mul(cone->axis, cc_len);
	hit->len_u = check_acos(vec_dot(vec_sub(cp, cc), \
	cone->axis_x) / (cc_len * tan(cone->angle)));
	if (vec_dot(cp, cone->axis_y) < EPSILON)
		hit->len_u = 2 * PI - hit->len_u;
	hit->len_u /= 2 * PI;
	hit->len_v = (cone->height - cc_len) / cone->height;
	hit->n = vec_unit(vec_sub(cp, \
		vec_mul(cone->axis, vec_length2(cp) / vec_dot(cp, cone->axis))));
	hit->front_face = vec_dot(hit->n, ray->d) < 0;
	if (!hit->front_face)
		hit->n = vec_mul(hit->n, -1);
	if (vars->info->flag & FLAG_TEXTURE)
		map_texture(vars, cone, hit);
	else if (vars->info->flag & FLAG_CHECKER)
		hit->color = get_checker(hit, cone->color);
	else
		hit->color = cone->color;
	return (1);
}

int	shoot_ray_to_cone(t_vars *vars, t_cone *cone, t_ray *ray, t_hit_info *hit)
{
	t_quad_eq	sol;
	t_vec		ce;

	ce = vec_sub(ray->pos, cone->pos);
	sol.a = pow(vec_dot(ray->d, cone->axis), 2) - pow(cos(cone->angle), 2);
	sol.b = vec_dot(ray->d, cone->axis) * vec_dot(ce, cone->axis) \
			- vec_dot(ce, ray->d) * pow(cos(cone->angle), 2);
	sol.c = pow(vec_dot(ce, cone->axis), 2) \
		- vec_dot(ce, ce) * pow(cos(cone->angle), 2);
	solve_quardatic_eq(&sol);
	if (sol.discriminant < 0)
		return (0);
	if (cone_update_hit_info(&sol, hit, ray, cone))
		return (update_hit_info_after_hit(vars, cone, ray, hit));
	return (0);
}
