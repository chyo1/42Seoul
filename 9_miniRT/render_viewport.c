/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_viewport.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 21:01:27 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/03/15 21:03:06 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

static void	get_dx_dy(t_info *info, double gx, double gy)
{
	const t_vec	xc = info->cam.x;
	const t_vec	yc = info->cam.y;

	info->dx = vec_mul(xc, 2 * gx / (WIDTH - 1));
	info->dy = vec_mul(yc, 2 * gy / (HEIGHT - 1));
}

static void	get_origin(t_info *info, t_vec xc, t_vec yc, t_vec zc)
{
	double	gx;
	double	gy;
	double	d_fov;

	d_fov = (double)info->cam.fov;
	gx = tan(d_fov / 2);
	gy = gx * HEIGHT / WIDTH;
	info->origin = vec_sub(zc, vec_plus(vec_mul(xc, gx), vec_mul(yc, gy)));
	get_dx_dy(info, gx, gy);
}

void	render_viewport(t_info *info, t_vars *vars)
{
	int			a;
	int			b;
	t_ray		r;
	t_color		color;

	get_origin(info, info->cam.x, info->cam.y, info->cam.z);
	r.pos = info->cam.pos;
	b = HEIGHT - 1;
	while (b >= 0)
	{
		a = 0;
		while (a < WIDTH)
		{
			r.d = vec_plus(info->origin, \
					vec_plus(vec_mul(info->dx, a), vec_mul(info->dy, b)));
			r.d = vec_unit(r.d);
			color = shoot_ray_to_viewport(vars, &r);
			my_mlx_pixel_put(&vars->image, a, HEIGHT - b - 1, color);
			a++;
		}
		b--;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->image.img, 0, 0);
}
