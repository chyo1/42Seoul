/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:12:01 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/03/17 14:27:27 by semjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_bonus.h"

t_vec	vec(double x, double y, double z)
{
	t_vec	ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}

t_color	color(int x, int y, int z)
{
	return (vec((double)x, (double)y, (double)z));
}

t_vec	vec_unit(t_vec v)
{
	double	len;

	len = vec_length(v);
	if (len == 0)
		return (v);
	return (vec_div(v, len));
}

double	vec_length2(t_vec v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

double	vec_length(t_vec v)
{
	return (sqrt(vec_length2(v)));
}
