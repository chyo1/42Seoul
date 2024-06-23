/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_wildcard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:48:31 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 12:50:34 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include "expand.h"

static t_list	*check_expand_wildcard(t_list **cur, t_list **prev)
{
	t_list	*tmp;

	tmp = 0;
	if (!(*cur)->content || !contain_char((*cur)->content, SUB_WILDCARD))
	{
		*prev = *cur;
		*cur = (*cur)->next;
		return (0);
	}
	tmp = execute_wildcard((*cur)->content);
	if (!tmp)
	{
		*prev = *cur;
		*cur = (*cur)->next;
	}
	return (tmp);
}

void	expand_wildcard(t_list **lst)
{
	t_list	*cur;
	t_list	*prev;
	t_list	*tmp;

	cur = *lst;
	prev = 0;
	while (cur)
	{
		tmp = check_expand_wildcard(&cur, &prev);
		if (!tmp)
			continue ;
		if (prev)
			prev->next = tmp;
		else
			*lst = tmp;
		prev = ft_lstlast(tmp);
		tmp = cur;
		prev->next = cur->next;
		cur = cur->next;
		tmp->next = 0;
		ft_lstclear(&tmp, free);
	}
}
