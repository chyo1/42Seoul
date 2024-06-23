/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_n_hooking.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:15:15 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/03/15 20:15:17 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_info.h"
#include "minirt_types.h"
#include "ray_trace.h"

void	init_mlx(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->image.img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "miniRT");
	vars->image.addr = mlx_get_data_addr(vars->image.img, \
	&vars->image.bits_per_pixel, &vars->image.line_length, &vars->image.endian);
	mlx_hook(vars->win, 17, 0, turn_off_win_n_fin_program, vars);
	mlx_hook(vars->win, 2, 0, key_hook, vars);
}

int	turn_off_win_n_fin_program(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->image.img);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		turn_off_win_n_fin_program(vars);
	if (keycode == KEY_Q)
		vars->info->cam.pos = \
			vec_plus(vars->info->cam.pos, vec_mul(vars->info->cam.x, 0.5));
	if (keycode == KEY_W)
		vars->info->cam.pos = \
			vec_plus(vars->info->cam.pos, vec_mul(vars->info->cam.y, 0.5));
	if (keycode == KEY_E)
		vars->info->cam.pos = \
			vec_plus(vars->info->cam.pos, vec_mul(vars->info->cam.z, 0.5));
	if (keycode == KEY_A)
		vars->info->cam.pos = \
			vec_sub(vars->info->cam.pos, vec_mul(vars->info->cam.x, 0.5));
	if (keycode == KEY_S)
		vars->info->cam.pos = \
			vec_sub(vars->info->cam.pos, vec_mul(vars->info->cam.y, 0.5));
	if (keycode == KEY_D)
		vars->info->cam.pos = \
			vec_sub(vars->info->cam.pos, vec_mul(vars->info->cam.z, 0.5));
	render_viewport(vars->info, vars);
	return (0);
}
