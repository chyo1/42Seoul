/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_info_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:10:26 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/03/17 14:17:35 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_INFO_BONUS_H
# define MLX_INFO_BONUS_H

# include <math.h>
# include <unistd.h> // write
# include <stdlib.h> // exit
# include <mlx.h>
# include "minirt_types_bonus.h"

// key code
# define KEY_ESC 53
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}t_data;

typedef struct s_texture
{
	t_data	bumpmap;
	t_data	pixel_color;
}	t_texture;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	int			set_info;
	t_data		image;
	t_info		*info;
	t_texture	texture;
}t_vars;

// mlx_init.c
void	init_mlx(t_vars *vars);

// mlx_hooking.c
int		turn_off_win_n_fin_program(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
void	my_mlx_pixel_put(t_data *data, int x, int y, t_color color);

#endif
