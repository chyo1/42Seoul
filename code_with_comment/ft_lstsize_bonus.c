/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:05:59 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/10/14 20:35:17 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{	
	int	size;

	size = 0;
	// list의 끝까지 탐색하며 list의 길이(size)를 잼
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
