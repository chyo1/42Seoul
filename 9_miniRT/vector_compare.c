/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_compare.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 21:04:06 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/03/15 21:04:12 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec	vec_min(t_vec a, t_vec b)
{
	t_vec	ret;

	ret.x = fmin(a.x, b.x);
	ret.y = fmin(a.y, b.y);
	ret.z = fmin(a.z, b.z);
	return (ret);
}

t_vec	vec_max(t_vec a, t_vec b)
{
	t_vec	ret;

	ret.x = fmax(a.x, b.x);
	ret.y = fmax(a.y, b.y);
	ret.z = fmax(a.z, b.z);
	return (ret);
}
