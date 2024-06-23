/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 21:05:22 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/03/15 21:06:21 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>
# include "minirt_types.h"

// vector.c
t_vec	vec(double x, double y, double z);
t_color	color(int x, int y, int z);
t_vec	vec_unit(t_vec v);
double	vec_length2(t_vec v);
double	vec_length(t_vec v);

// vector_cal.c
t_vec	vec_plus(t_vec a, t_vec b);
t_vec	vec_sub(t_vec a, t_vec b);
double	vec_dot(t_vec a, t_vec b);
t_vec	vec_cross(t_vec a, t_vec b);
t_vec	vec_vec_mul(t_vec a, t_vec b);

// vector_scalar_cal.c
t_vec	vec_mul(t_vec a, double num);
t_vec	vec_div(t_vec a, double num);

// vector_compare.c
t_vec	vec_min(t_vec a, t_vec b);
t_vec	vec_max(t_vec a, t_vec b);

#endif
