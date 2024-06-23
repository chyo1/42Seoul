/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_compare_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:12:13 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/03/17 14:27:27 by semjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_bonus.h"

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
