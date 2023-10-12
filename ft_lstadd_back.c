/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:53:05 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/10/12 18:25:23 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

	// if (lst == 0)
	// 	return ;
	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	p = ft_lstlast(*lst);
	(p)->next = new;
}


// int main()
// {
// 	t_list	*head;

// 	head = 0;
// 	ft_lstadd_back(&head, ft_lstnew(2));
// }