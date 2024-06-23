/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:11:27 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/03/17 14:25:23 by semjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"

int	check_ratio(double val)
{
	return (0.0 <= val && val <= 1.0);
}

int	check_cam_fov(int val)
{
	return (0 <= val && val < 180);
}

int	check_normalized(double val)
{
	return (-1.0 <= val && val <= 1.0);
}

int	check_color(int val)
{
	return (0 <= val && val <= 255);
}

int	check_filename_n_open(char *file)
{
	size_t	len;
	int		fd;

	len = ft_strlen(file);
	if (len >= 3 && ft_strcmp(file + len - 3, RT_EXT) != 0)
		error(INVALID_FORMAT_ERR);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error(FILE_ERR);
	return (fd);
}
