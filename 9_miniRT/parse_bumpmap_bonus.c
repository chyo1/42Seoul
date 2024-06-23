/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bumpmap_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:11:23 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/03/17 14:25:12 by semjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"

void	parse_bumpmap(t_vars *vars, char **arr)
{
	char		*filename;
	t_texture	*tx;

	if (get_arr_size(arr) != 2 || vars->info->flag & FLAG_TEXTURE)
		error(INVALID_FORMAT_ERR);
	vars->info->flag |= FLAG_TEXTURE;
	filename = arr[0];
	tx = &vars->texture;
	tx->bumpmap.img = mlx_xpm_file_to_image(vars->mlx, filename, \
		&tx->bumpmap.width, &tx->bumpmap.height);
	filename = arr[1];
	tx->pixel_color.img = mlx_xpm_file_to_image(vars->mlx, filename, \
		&tx->pixel_color.width, &tx->pixel_color.height);
	if (tx->bumpmap.img == NULL || tx->pixel_color.img == NULL)
		error(INVALID_FORMAT_ERR);
	tx->bumpmap.addr = mlx_get_data_addr(tx->bumpmap.img, \
	&tx->bumpmap.bits_per_pixel, &tx->bumpmap.line_length, &tx->bumpmap.endian);
	filename = arr[1];
	tx->pixel_color.addr = mlx_get_data_addr(tx->pixel_color.img, \
	&tx->pixel_color.bits_per_pixel, \
	&tx->pixel_color.line_length, &tx->pixel_color.endian);
	if (tx->bumpmap.width <= 0 || tx->bumpmap.height <= 0 || \
	tx->pixel_color.width <= 0 || tx->pixel_color.height <= 0)
		error(INVALID_FORMAT_ERR);
}

t_color	get_pixel_color(t_data *data, int u, int v)
{
	int				r;
	int				g;
	int				b;
	char			*dst;
	unsigned int	color;

	dst = data->addr + (v * data->line_length + u * (data->bits_per_pixel / 8));
	color = *((unsigned int *)dst);
	r = ((color >> 16) & 0xFF);
	g = ((color >> 8) & 0xFF);
	b = (color & 0xFF);
	return (vec(r, g, b));
}

int	get_pixel_grayscale(t_data *data, int u, int v)
{
	char			*dst;
	unsigned int	color;

	dst = data->addr + (v * data->line_length + u * (data->bits_per_pixel / 8));
	color = *((unsigned int *)dst);
	return (color & 0xff);
}
