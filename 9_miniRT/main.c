/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:12:38 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/03/15 20:57:02 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "ray_trace.h"

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
