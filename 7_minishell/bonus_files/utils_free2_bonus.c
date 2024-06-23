/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:45:34 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 12:45:35 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_type_bonus.h"

void	free_redi(void *c)
{
	t_redi	*r;

	if (!c)
		return ;
	r = (t_redi *)c;
	free(r->file);
	free(r);
}
