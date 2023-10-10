/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:07:12 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/10/10 17:13:01 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ans;
	t_list	*node;

	ans = ft_lstnew(f(lst->content));
	lst = lst->next;
	if (!ans)
		return (NULL);
	while (!lst)
	{
		node = ft_lstnew(f(lst->content));
		ft_lstadd_back(&ans, node);
		if (!lst)
		{
			ft_lstclear(&ans, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (ans);
}
