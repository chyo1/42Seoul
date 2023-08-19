/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 10:57:27 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/08/09 10:57:28 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int		cnt;

	cnt = 0;
	if (begin_list == 0)
		return (0);
	while (begin_list != 0)
	{
		begin_list = begin_list->next;
		cnt++;
	}
	return (cnt);
}
