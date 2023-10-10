/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:07:12 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/10/10 18:42:49 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ans;
	t_list	*node;
	void	*res;

	res = f(lst->content);
	if (!res)
		return (NULL);
	ans = ft_lstnew(res);
	if (!ans)
		return (NULL);
	lst = lst->next;
	while (!lst)
	{
		res = f(lst->content);
		if (!res)
			return (NULL);
		node = ft_lstnew(res);
		if (!node)
		{
			ft_lstclear(&ans, del);
			return (NULL);
		}
		ft_lstadd_back(&ans, node);
		lst = lst->next;
	}
	return (ans);
}
