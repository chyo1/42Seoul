/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:38:26 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/01/14 13:00:09 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_error_n_fin_program(int argc, char **argv)
{
	// no input
	if (argc == 1)
	{
		write(1, "Enter \"mandelbrot\", \"julia\", \"burningship\" set\n", 47);
		exit(1);
	}
	// additional input
	else if (argc != 2 && (ft_strcmp(argv[1], "mandelbrot") == 0 \
		|| ft_strcmp(argv[1], "burningship") == 0))
	{
		write(1, "write only set name\n", 20);
		exit(1);
	}
	// !(julia set + 2 argument)
	else if (argc != 4 && ft_strcmp(argv[1], "julia") == 0)
	{
		write(1, "enter 2 parameters more\n", 24);
		exit(1);
	}
}

int	turn_off_win_n_fin_program(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	key_hook(int keycode, t_vars *vars)
{
	// finish program
	if (keycode == KEY_ESC)
		turn_off_win_n_fin_program(vars);

	// move image
	else if (keycode == KEY_UP)
		vars->move_xy[1] += 20;
	else if (keycode == KEY_DOWN)
		vars->move_xy[1] -= 20;
	else if (keycode == KEY_LEFT)
		vars->move_xy[0] -= 20;
	else if (keycode == KEY_RIGHT)
		vars->move_xy[0] += 20;

	else if (keycode == RED)
		vars->color = RED;
	else if (keycode == PURPLE)
		vars->color = PURPLE;

	// init status
	else if (keycode == SPACE)
	{
		vars->zoom_scale = X_SIZE / 4;
		vars->loc_mouse[0] = 0;
		vars->loc_mouse[1] = 0;
		vars->move_xy[0] = 0;
		vars->move_xy[1] = 0;
	}
	// draw present set
	execute_set(*vars);
	return (0);
}

int	mouse_hook(int mousecode, int x, int y, t_vars *vars)
{
	double	bef_x;
	double	bef_y;

	// zoom in
	if (mousecode == WHEEL_UP)
	{
		bef_x = (x - X_SIZE / 2) / vars->zoom_scale;
		bef_y = (Y_SIZE / 2 - y) / vars->zoom_scale;

		// magnification up
		vars->zoom_scale *= 1.2;

		// apply mouse location
		vars->loc_mouse[0] -= bef_x - (x - X_SIZE / 2) / vars->zoom_scale;
		vars->loc_mouse[1] -= bef_y - (Y_SIZE / 2 - y) / vars->zoom_scale;
	}

	// zoom out
	else if (mousecode == WHEEL_DOWN)
	{
		bef_x = (x - X_SIZE / 2) / vars->zoom_scale;
		bef_y = (Y_SIZE / 2 - y) / vars->zoom_scale;

		// magnification down
		vars->zoom_scale *= 0.8;

		// apply mouse location
		vars->loc_mouse[0] += bef_x - (x - X_SIZE / 2) / vars->zoom_scale;
		vars->loc_mouse[1] += bef_y - (Y_SIZE / 2 - y) / vars->zoom_scale;
	}
	execute_set(*vars);
	return (0);
}
