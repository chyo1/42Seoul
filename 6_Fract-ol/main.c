/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:11:42 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/01/14 13:10:35 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	// check input error
	print_error_n_fin_program(argc, argv);

	init_vars(&vars, argv);

	// execute mlx
	vars.mlx = mlx_init();
	
	// create window named "fract-ol"
	vars.win = mlx_new_window(vars.mlx, X_SIZE, Y_SIZE, "Fract-ol");
	
	// create image objects
	vars.image.img = mlx_new_image(vars.mlx, X_SIZE, Y_SIZE);
	
	// allocate image address
	vars.image.addr = mlx_get_data_addr(vars.image.img,	&vars.image.bits_per_pixel,	&vars.image.line_length, &vars.image.endian);

	execute_set(vars);

	// mouse sensing
	mlx_hook(vars.win, 4, 0, mouse_hook, &vars);

	// close button press event
	mlx_hook(vars.win, 17, 0, turn_off_win_n_fin_program, &vars);
	
	// esc key press event
	mlx_hook(vars.win, 2, 0, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
