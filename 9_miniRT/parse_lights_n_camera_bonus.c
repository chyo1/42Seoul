/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lights_n_camera_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:11:31 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/03/17 14:27:27 by semjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"

void	parse_ambient(t_info *info, t_ambient *amb, char **arr)
{
	if (get_arr_size(arr) != 2 || info->flag & FLAG_AMB)
		error(INVALID_FORMAT_ERR);
	amb->light_ratio = parse_double(arr[0], check_ratio);
	parse_colors(arr[1], &amb->color);
	info->flag |= FLAG_AMB;
}

void	parse_light(t_info *info, t_list **lights, char **arr)
{
	t_light	*light;

	light = (t_light *)ft_calloc(sizeof(t_light), 1);
	if (get_arr_size(arr) != 3)
		error(INVALID_FORMAT_ERR);
	parse_vector(arr[0], &light->pos, 0);
	light->brightness = parse_double(arr[1], check_ratio);
	parse_colors(arr[2], &light->color);
	ft_lstadd_back(lights, ft_lstnew(light));
	info->flag |= FLAG_LIGHT;
}

void	get_camera_axis(t_camera *cam)
{
	cam->x = vec_unit(vec_cross(vec(0, 1, 0), cam->z));
	if (equal_double(vec_length(cam->x), 0))
		cam->x = vec(1, 0, 0);
	cam->y = vec_unit(vec_cross(cam->z, cam->x));
}

void	parse_camera(t_info *info, t_camera *cam, char **arr)
{
	if (get_arr_size(arr) != 3 || info->flag & FLAG_CAM)
		error(INVALID_FORMAT_ERR);
	parse_vector(arr[0], &cam->pos, 0);
	parse_dir_vector(arr[1], &cam->z);
	cam->fov = parse_int(arr[2], check_cam_fov);
	cam->fov = cam->fov * PI / 180;
	info->flag |= FLAG_CAM;
	get_camera_axis(cam);
}
