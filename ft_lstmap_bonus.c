/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:07:12 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/10/14 20:35:14 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	check_null(t_list *lst, void *(*f)(void *))
{
	void	*con;

	if (!lst)
		con = f(lst->content);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ans;
	t_list	*node;
	void	*con;

	ans = 0;
	check_null(lst, f);
	while (lst)
	{
		con = f(lst->content);
		if (!con)
		{
			ft_lstclear(&ans, del);
			return (0);
		}
		node = ft_lstnew(con);
		if (!node)
		{
			ft_lstclear(&ans, del);
			del(con);
			return (0);
		}
		ft_lstadd_back(&ans, node);
		lst = lst->next;
	}
	return (ans);
}
