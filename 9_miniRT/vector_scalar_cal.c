/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_scalar_cal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 21:04:28 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/03/15 21:04:40 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_types.h"
#include "error.h"

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
