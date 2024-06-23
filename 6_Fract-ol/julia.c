/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:41:23 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/01/14 13:23:04 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Zn+1 = Zn^2 + c
static void	is_julia(double zx, double zy, char **dst, t_vars vars)
{
	double			z[2];
	double			tmp;
	unsigned int	i;

	z[0] = zx;
	z[1] = zy;
	i = 0;
	while (i < REPEAT_CNT)
	{
		if (z[0] * z[0] + z[1] * z[1] > 4)
		{
			*((unsigned int *) *dst) = fractol_color(i, vars.color);
			return ;
		}
		tmp = z[0];
		z[0] = z[0] * z[0] - z[1] * z[1] + vars.c[0];
		z[1] = 2 * tmp * z[1] + vars.c[1];
		i++;
	}
	*((unsigned int *) *dst) = 0x00FFFFFF;
	return ;
}

//원하는 좌표에 해당하는 주소에 color값을 넣는 함수
void	julia(t_data *data, t_vars vars)
{
	char	*dst;
	int		x;
	int		y;

	x = 0;
	while (x < X_SIZE)
	{
		y = 0;
		while (y < Y_SIZE)
		{
			dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
			is_julia((double)(x + vars.move_xy[0] - X_SIZE / 2) / vars.zoom_scale - vars.loc_mouse[0],
					(double)(Y_SIZE / 2 + vars.move_xy[1] - y) / vars.zoom_scale - vars.loc_mouse[1],
					&dst, vars);
			y++;
		}
		x++;
	}
}
