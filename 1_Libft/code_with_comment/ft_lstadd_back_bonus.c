/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:53:05 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/10/14 20:35:04 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

	// list == NULL일 때 new를 헤드 노드로 만들어줌
	if (*lst == 0)
	{
		*lst = new;
		return ;
	}

	// 입력받은 list의 마지막 노드를 찾아 해당 위치에 새로운 노드 붙여줌
	p = ft_lstlast(*lst);
	p->next = new;
}
