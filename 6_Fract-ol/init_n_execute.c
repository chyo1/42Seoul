/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_n_execute.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:02:25 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/01/14 13:02:45 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_vars(t_vars *vars, char **argv)
{
	vars->zoom_scale = X_SIZE / 4;
	vars->loc_mouse[0] = 0;
	vars->loc_mouse[1] = 0;
	vars->move_xy[0] = 0;
	vars->move_xy[1] = 0;
	vars->color = RED;
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		vars->set_info = MANDELBROT;
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		vars->c[0] = str_to_double(argv[2]);
		vars->c[1] = str_to_double(argv[3]);
		vars->set_info = JULIA;
	}
	else if (ft_strcmp(argv[1], "burningship") == 0)
		vars->set_info = SHIP;
}

void	execute_set(t_vars vars)
{
	if (vars.set_info == MANDELBROT)
		mandelbrot(&(vars.image), vars);
	else if (vars.set_info == JULIA)
		julia(&(vars.image), vars);
	else if (vars.set_info == SHIP)
		burningship(&(vars.image), vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.image.img, 0, 0);
}