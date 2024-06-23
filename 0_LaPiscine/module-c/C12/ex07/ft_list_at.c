/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:27:12 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/08/09 19:27:13 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	int	cnt;

	cnt = 0;
	while (begin_list && cnt < nbr)
	{
		begin_list = begin_list->next;
		cnt++;
	}
	if (begin_list == 0)
		return (0);
	return (begin_list);
}
