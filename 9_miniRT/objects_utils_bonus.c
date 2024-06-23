/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:11:02 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/03/17 14:18:44 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace_bonus.h"

void	solve_quardatic_eq(t_quad_eq *sol)
{
	sol->discriminant = sol->b * sol->b - sol->a * sol->c;
	sol->r1 = (-sol->b - sqrt(sol->discriminant)) / sol->a;
	sol->r2 = (-sol->b + sqrt(sol->discriminant)) / sol->a;
}

int	update_hit_info(t_quad_eq *sol, t_hit_info *hit)
{
	if (sol->r1 < hit->t_min || sol->r1 > hit->t_max)
	{
		if (sol->r2 < hit->t_min || sol->r2 > hit->t_max)
			return (0);
		hit->t_max = sol->r2;
		return (1);
	}
	hit->t_max = sol->r1;
	return (1);
}
