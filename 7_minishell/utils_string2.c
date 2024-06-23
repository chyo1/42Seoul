/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_string2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:49:53 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 12:51:11 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_type.h"

void	remove_cond(t_list **lst, int (*to_delete)(void *), void (*del)(void *))
{
	t_list	*cur;
	t_list	*prev;
	t_list	*next;

	prev = 0;
	cur = *lst;
	while (cur)
	{
		next = cur->next;
		if (to_delete(cur->content))
		{
			if (prev)
				prev->next = next;
			else
				*lst = next;
			if (cur->content)
				ft_lstdelone(cur, del);
			else
				free(cur);
		}
		else
			prev = cur;
		cur = next;
	}
}

int	is_null(void *p)
{
	return (p == 0);
}
