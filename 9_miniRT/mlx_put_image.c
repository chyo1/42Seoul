/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:15:34 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/03/15 20:15:49 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_info.h"

static unsigned int	convert_color(t_color color)
{
	unsigned int	ret;
	int				t;

	ret = 0;
	t = (int)color.x;
	ret = (ret << 8) + (t & 0xFF);
	t = (int)color.y;
	ret = (ret << 8) + (t & 0xFF);
	t = (int)color.z;
	ret = (ret << 8) + (t & 0xFF);
	return (ret);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, t_color color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = convert_color(color);
}
