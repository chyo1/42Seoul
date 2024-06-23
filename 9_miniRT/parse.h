/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:35:25 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/03/17 12:37:06 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <fcntl.h>

# include "get_next_line.h"
# include "vector.h"
# include "error.h"
# include "mlx_info.h"

// parse.c
void	parse(t_vars *vars, t_info *info, char *argv);
void	parse_colors(char *in, t_color *color);
void	parse_vector(char *in, t_vec *vec, int (*check)(double));
void	parse_dir_vector(char *in, t_vec *vec);
void	parse_type(t_vars *vars, char *line);

// parse_number.c
int		parse_int(char *in, int (*check)(int));
double	parse_double(char *in, int (*check)(double));
double	ft_atod(char *in);
double	equal_double(double target, double check);

// parse_string.c
int		is_space(char c);
int		is_all_space(char *line);
int		get_arr_size(char **arr);
void	trim_newline(char *in);

// parse_check.c
int		check_ratio(double val);
int		check_cam_fov(int val);
int		check_normalized(double val);
int		check_color(int val);
int		check_filename_n_open(char *file);

// parse_light_n_camera.c
void	parse_ambient(t_info *info, t_ambient *amb, char **arr);
void	parse_light(t_info *info, t_list **lights, char **arr);
void	parse_camera(t_info *info, t_camera *cam, char **arr);

// parse_objects.c
void	parse_objects(t_info *info, char **arr);
void	parse_sphere(t_list **lst, char **arr);
void	parse_plane(t_list **lst, char **arr);
void	parse_cylinder(t_list **lst, char **arr);
void	parse_cone(t_list **list, char **arr);

// parse_bumpmap.c
void	parse_bumpmap(t_vars *vars, char **arr);

#endif
