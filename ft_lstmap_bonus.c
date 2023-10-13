/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:07:12 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/10/13 17:45:42 by hyowchoi         ###   ########.fr       */
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

	ans = NULL;
	check_null(lst, f);
	while (lst)
	{
		con = f(lst->content);
		if (!con)
		{
			ft_lstclear_bonus(&ans, del);
			return (NULL);
		}
		node = ft_lstnew_bonus(con);
		if (!node)
		{
			ft_lstclear_bonus(&ans, del);
			del(con);
			return (NULL);
		}
		ft_lstadd_back_bonus(&ans, node);
		lst = lst->next;
	}
	return (ans);
}
