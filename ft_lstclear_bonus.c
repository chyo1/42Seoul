/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:57:41 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/10/13 18:05:57 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node_next;
	t_list	*node_free;

	node_next = *lst;
	while (node_next)
	{
		node_free = node_next;
		node_next = node_next->next;
		del(node_free->content);
		free(node_free);
	}
	*lst = NULL;
}
