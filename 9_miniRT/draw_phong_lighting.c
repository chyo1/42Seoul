/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_phong_lighting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:07:26 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/03/17 16:55:23 by semjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

t_color	get_diffuse(t_light *light, t_hit_info *hit)
{
	t_vec	ld;
	double	nl;
	double	kd;

	kd = 0.3;
	ld = vec_unit(vec_sub(light->pos, hit->p));
	nl = fmax(vec_dot(ld, hit->n), 0.0);
	return (vec_vec_mul(vec_mul(light->color, kd * nl), \
			vec_div(hit->color, 255)));
}

t_color	get_specular(t_light *light, t_hit_info *hit, t_ray *ray)
{
	double	is;
	double	ks;
	double	ka;
	t_vec	r;
	t_vec	l;

	ks = 0.5;
	ka = 50;
	is = light->brightness;
	l = vec_unit(vec_sub(hit->p, light->pos));
	r = vec_sub(l, vec_mul(hit->n, 2 * fmin(vec_dot(l, hit->n), 0)));
	if (vec_dot(r, ray->d) > 0)
		return (vec(0, 0, 0));
	return (vec_mul(light->color, is * ks * \
		pow(vec_dot(r, vec_mul(ray->d, -1)), ka)));
}

t_color	phong_lighting(t_vars *vars, t_info *info, t_ray *r, t_hit_info *hit)
{
	t_color	ret;
	t_list	*cur_light;

	ret = vec_vec_mul(vec_mul(info->amb.color, info->amb.light_ratio), \
			vec_div(hit->color, 255));
	cur_light = info->lights;
	while (cur_light)
	{
		if (is_shadow(vars, info, cur_light->content, hit))
		{
			cur_light = cur_light->next;
			continue ;
		}
		ret = vec_plus(ret, get_diffuse(cur_light->content, hit));
		ret = vec_plus(ret, get_specular(cur_light->content, hit, r));
		cur_light = cur_light->next;
	}
	return (vec_min(ret, color(255, 255, 255)));
}
