/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_invalid_angle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:14:14 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/03/17 13:20:51 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

double	check_acos(double val)
{
	double	ret;

	ret = acos(val);
	if (isnan(ret))
	{
		if (equal_double(val, 1))
			ret = 0;
		else
			ret = PI;
	}
	return (ret);
}
