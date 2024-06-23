/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_get_next_line_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:32:35 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/03/15 21:23:31 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list_g	*find_or_make_lst(t_list_g **root, int fd)
{
	t_list_g	*node;

	node = *root;
	while (node)
	{
		if (node->fd == fd)
			return (node);
		node = node->next;
	}
	node = (t_list_g *)malloc(1 * sizeof(t_list_g));
	if (!node)
		return (0);
	if (!init_node(node, fd))
	{
		free(node);
		return (0);
	}
	lstadd_back(root, node);
	return (node);
}

int	init_node(t_list_g *node, int fd)
{
	char	*str1;

	str1 = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!str1)
		return (0);
	node->str = str1;
	node->fd = fd;
	node->len = 0;
	node->size = BUFFER_SIZE;
	node->loc = 0;
	node->next = 0;
	return (1);
}

void	lstadd_back(t_list_g **lst, t_list_g *new_node)
{
	t_list_g	*p;

	if (*lst == 0)
	{
		*lst = new_node;
		return ;
	}
	p = *lst;
	while (p->next)
		p = p->next;
	p->next = new_node;
}

char	*list_free_and_connect(t_list_g **lst, int fd, int type)
{
	t_list_g	*bef;
	t_list_g	*now;

	bef = *lst;
	now = *lst;
	if (now->next == 0)
		*lst = 0;
	else
	{
		while (now->fd != fd)
		{
			bef = now;
			now = now->next;
		}
		bef->next = now->next;
	}
	if (bef == now)
		*lst = now->next;
	free(now->str);
	free(now);
	if (type >= 0)
		error(type);
	return (0);
}
