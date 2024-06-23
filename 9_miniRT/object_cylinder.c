/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:10:06 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/03/17 13:21:53 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

static int	check_cylinder_hit(double t, \
	t_hit_info *hit, t_cylinder *c, t_ray *r)
{
	t_vec	p;
	double	cp;

	p = vec_plus(r->pos, vec_mul(r->d, t));
	cp = vec_dot(vec_sub(p, c->pos), c->axis);
	return (t >= hit->t_min && t < hit->t_max && cp >= 0 && cp <= c->height);
}

static int	cylinder_update_hit_info(t_quad_eq *sol, \
	t_hit_info *hit, t_ray *r, t_cylinder *c)
{
	int	check_r1;

	check_r1 = check_cylinder_hit(sol->r1, hit, c, r);
	if (sol->r1 < sol->r2 && check_r1)
		hit->t_max = sol->r1;
	else if (check_cylinder_hit(sol->r2, hit, c, r))
		hit->t_max = sol->r2;
	else if (check_r1)
		hit->t_max = sol->r1;
	else
		return (0);
	hit->p = vec_plus(r->pos, vec_mul(r->d, hit->t_max));
	return (1);
}

void	map_texture(t_vars *vars, t_cylinder *c, t_hit_info *hit)
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
	uu = (get_pixel_grayscale(&vars->texture.bumpmap, \
		(u + 1) % vars->texture.bumpmap.width, v) - \
		get_pixel_grayscale(&vars->texture.bumpmap, \
		u % vars->texture.bumpmap.width, v)) / 127.0;
	vv = (get_pixel_grayscale(&vars->texture.bumpmap, u, \
		(v + 1) % vars->texture.bumpmap.height) - \
		get_pixel_grayscale(&vars->texture.bumpmap, u, \
		v % vars->texture.bumpmap.height)) / 127.0;
	hit->n = vec_unit(vec_plus(hit->n, \
		vec_plus(vec_mul(vec_cross(c->axis_x, hit->n), vv), \
		vec_mul(vec_cross(c->axis_y, hit->n), uu))));
	hit->color = get_pixel_color(&vars->texture.pixel_color, u, v);
}

static int	update_hit_info_after_hit(t_vars *vars, \
		t_cylinder *c, t_ray *r, t_hit_info *hit)
{
	t_vec		cp;
	double		cc_len;
	t_vec		cc;

	hit->n = vec_unit(vec_sub(vec_sub(hit->p, c->pos), \
		vec_mul(c->axis, vec_dot(vec_sub(hit->p, c->pos), c->axis))));
	hit->front_face = vec_dot(hit->n, r->d) < 0;
	if (!hit->front_face)
		hit->n = vec_mul(hit->n, -1);
	cp = vec_sub(hit->p, c->pos);
	cc_len = vec_dot(c->axis, cp);
	cc = vec_mul(c->axis, cc_len);
	hit->len_u = check_acos(vec_dot(vec_sub(cp, cc), c->axis_x) / c->r);
	if (vec_dot(cp, c->axis_y) < EPSILON)
		hit->len_u = 2 * PI - hit->len_u;
	hit->len_u /= 2 * PI;
	hit->len_v = cc_len / c->height;
	if (vars->info->flag & FLAG_TEXTURE)
		map_texture(vars, c, hit);
	else if (vars->info->flag & FLAG_CHECKER)
		hit->color = get_checker(hit, c->color);
	else
		hit->color = c->color;
	return (1);
}

int	shoot_ray_to_cylinder(t_vars *vars, t_cylinder *c, \
	t_ray *r, t_hit_info *hit)
{
	t_quad_eq	sol;
	t_vec		ce;

	ce = vec_sub(r->pos, c->pos);
	sol.a = vec_dot(r->d, c->axis) * vec_dot(r->d, c->axis) - 1;
	sol.b = vec_dot(r->d, c->axis) * vec_dot(ce, c->axis) - vec_dot(ce, r->d);
	sol.c = (c->r * c->r) - vec_dot(ce, ce) \
		+ vec_dot(ce, c->axis) * vec_dot(ce, c->axis);
	solve_quardatic_eq(&sol);
	if (sol.discriminant < 0)
		return (0);
	if (cylinder_update_hit_info(&sol, hit, r, c))
		return (update_hit_info_after_hit(vars, c, r, hit));
	return (0);
}
