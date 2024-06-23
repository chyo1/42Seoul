/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:51:53 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/08/09 16:51:54 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*a;
	t_list	*root;

	root = ft_create_elem(strs[0]);
	root->next = 0;
	i = 1;
	while (i < size)
	{
		a = ft_create_elem(strs[i]);
		a->next = root;
		root = a;
		i++;
	}
	return (a);
}
