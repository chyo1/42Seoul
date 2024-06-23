/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:57:41 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/10/14 20:35:07 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node_free; // free할 node 가리킴
	t_list	*node_next; // free할 node의 다음 노드 가리킴

	node_next = *lst;
	while (node_next)
	{
		node_free = node_next;
		node_next = node_next->next;
		ft_lstdelone(node_free, del);
	}
	*lst = 0;
}
