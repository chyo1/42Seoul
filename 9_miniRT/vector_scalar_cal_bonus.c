/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_scalar_cal_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:12:17 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/03/17 14:27:27 by semjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_types_bonus.h"
#include "error_bonus.h"

t_vec	vec_mul(t_vec a, double num)
{
	t_vec	ret;

	ret.x = a.x * num;
	ret.y = a.y * num;
	ret.z = a.z * num;
	return (ret);
}

t_vec	vec_div(t_vec a, double num)
{
	t_vec	ret;

	if (num == 0)
		error(DIVIDE_BY_ZERO);
	ret.x = a.x / num;
	ret.y = a.y / num;
	ret.z = a.z / num;
	return (ret);
}
