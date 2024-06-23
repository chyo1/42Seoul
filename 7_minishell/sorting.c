/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:49:33 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 12:51:00 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_cmp(void *now, void *next)
{
	unsigned int	i;
	char			*s1;
	char			*s2;

	s1 = ((t_env *)now)->name;
	s2 = ((t_env *)next)->name;
	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	do_strcmp(void *s1, void *s2)
{
	return (ft_strcmp(s1, s2));
}

static void	swap(t_list **a, t_list **b)
{
	t_env	*tmp;

	tmp = (t_env *)(*a)->content;
	(*a)->content = (*b)->content;
	(*b)->content = tmp;
}

void	bubble_sort(t_list *lst, int (*f)(void *, void *))
{
	int		i;
	int		j;
	int		size;
	t_list	*fir;
	t_list	*sec;

	size = ft_lstsize(lst) - 1;
	i = 0;
	while (i < size)
	{
		fir = lst;
		sec = lst->next;
		j = 0;
		while (j < size)
		{
			if (f(fir->content, sec->content) > 0)
				swap(&fir, &sec);
			j++;
			fir = sec;
			sec = sec->next;
		}
		i++;
	}
}
