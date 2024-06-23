/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:06:20 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/01/14 13:04:50 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <unistd.h> // write
# include <stdlib.h> // exit
# include <mlx.h>

# define X_SIZE 1000
# define Y_SIZE 1000

# define TRUE 1
# define FALSE 0

# define REPEAT_CNT 500

# define KEY_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define SPACE 49

# define WHEEL_UP 5
# define WHEEL_DOWN 4

# define MANDELBROT 1
# define JULIA 2
# define SHIP 3

# define PURPLE 35
# define RED 15

//이미지의 정보를 나타내는 변수를 저장한 구조체
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_data;

// mlx 구조체 mlx 포인터와 생성할 win 포인터를 가지고 있다.
typedef struct s_vars
{
	void		*mlx;
	void		*win;
	double		zoom_scale;
	double		loc_mouse[2];
	double		move_xy[2];
	int			set_info;
	double		c[2];
	int			color;
	t_data		image;
}t_vars;

// main.c
int				main(int argc, char **argv);

// init_n_execute.c
void			init_vars(t_vars *vars, char **argv);
void			execute_set(t_vars vars);

// mandelbrot.c
void			mandelbrot(t_data *data, t_vars vars);

// julia.c
void			julia(t_data *data, t_vars vars);

// string_func.c
double			str_to_double(char *str);
int				ft_strcmp(const char *s1, const char *s2);

// color.c
unsigned int	fractol_color(int now, int which_color);

// burningship.c
void			burningship(t_data *data, t_vars vars);

// hooking.c
int				turn_off_win_n_fin_program(t_vars *vars);
int				key_hook(int keycode, t_vars *vars);
int				mouse_hook(int mousecode, int x, int y, t_vars *vars);
void			print_error_n_fin_program(int argc, char **argv);
#endif
