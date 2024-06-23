/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:34:33 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/03/17 16:16:17 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	parse_colors(char *in, t_color *color)
{
	char	**arr;

	arr = ft_split(in, ',');
	if (get_arr_size(arr) != 3)
		error(INVALID_FORMAT_ERR);
	color->x = parse_int(arr[0], check_color);
	color->y = parse_int(arr[1], check_color);
	color->z = parse_int(arr[2], check_color);
	free_arr(arr);
}

void	parse_dir_vector(char *in, t_vec *vec)
{
	parse_vector(in, vec, check_normalized);
	if (!equal_double(vec_length(*vec), 1))
		error(INVALID_FORMAT_ERR);
}

void	parse_vector(char *in, t_vec *vec, int (*check)(double))
{
	char	**arr;

	arr = ft_split(in, ',');
	if (get_arr_size(arr) != 3)
		error(INVALID_FORMAT_ERR);
	vec->x = parse_double(arr[0], check);
	vec->y = parse_double(arr[1], check);
	vec->z = parse_double(arr[2], check);
	free_arr(arr);
}

void	parse_type(t_vars *vars, char *line)
{
	t_info	*info;
	char	**arr;

	info = vars->info;
	arr = ft_split(line, ' ');
	if (ft_strcmp(*arr, AMBIENT_ID) == 0)
		parse_ambient(info, &info->amb, arr + 1);
	else if (ft_strcmp(*arr, CAMERA_ID) == 0)
		parse_camera(info, &info->cam, arr + 1);
	else if (ft_strcmp(*arr, LIGHT_ID) == 0)
		parse_light(info, &info->lights, arr + 1);
	else if (ft_strcmp(*arr, TEXTURE_ID) == 0)
		parse_bumpmap(vars, arr + 1);
	else if (ft_strcmp(*arr, CHECKER_ID) == 0 \
		&& arr[1] == 0 && (info->flag & FLAG_CHECKER) == 0)
		info->flag |= FLAG_CHECKER;
	else
		parse_objects(info, arr);
	free_arr(arr);
}

void	parse(t_vars *vars, t_info *info, char *argv)
{
	ssize_t	fd;
	char	*line;

	fd = check_filename_n_open(argv);
	line = get_next_line(fd);
	while (line)
	{
		trim_newline(line);
		if (line[0] != '#' && ft_strlen(line) != 0 && !is_all_space(line))
			parse_type(vars, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (!(info->flag & FLAG_AMB) || !(info->flag & FLAG_CAM) \
		|| !(info->flag & FLAG_LIGHT))
		error(INVALID_FORMAT_ERR);
	if ((info->flag & FLAG_CHECKER) && (info->flag & FLAG_TEXTURE))
		error(INVALID_FORMAT_ERR);
}
