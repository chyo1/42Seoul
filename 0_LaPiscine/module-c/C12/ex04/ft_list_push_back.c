/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:34:00 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/08/09 16:34:01 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*a;

	ft_create_elem(data);
	while ((*begin_list)->next != 0)
	{
		(*begin_list) = (*begin_list)->next;
	}
	(*begin_list)->next = a;
}
