/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:10:16 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/03/17 14:18:44 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"
#include "ray_trace_bonus.h"

void	init_info(t_vars *vars)
{
	t_info	*info;

	info = vars->info;
	info->flag = 0;
	info->objs = 0;
	info->lights = 0;
}

int	main(int argc, char *argv[])
{
	t_info	info;
	t_vars	vars;

	if (argc != 2)
		error(INVALID_ARGNUM_ERR);
	vars.info = &info;
	init_mlx(&vars);
	init_info(&vars);
	parse(&vars, &info, argv[1]);
	get_objs_axis(info.objs);
	render_viewport(&info, &vars);
	mlx_loop(vars.mlx);
}
