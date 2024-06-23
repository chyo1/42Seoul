/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_str_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:42:47 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 12:42:48 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	addback_substr(t_list **lst, size_t *prev, size_t i, char *str)
{
	char	*tmp;

	if (i == *prev)
	{
		(*prev)++;
		return ;
	}
	tmp = ft_substr(str, *prev, i - *prev);
	ft_lstadd_back(lst, ft_lstnew(tmp));
	*prev = i + 1;
}

t_list	*ft_split_str(char *str, char *charset)
{
	t_list	*ret;
	char	*tmp;
	size_t	i;
	size_t	prev;

	if (!str)
		return (0);
	ret = 0;
	i = 0;
	prev = 0;
	while (str[i])
	{
		if (str[i] && ft_strchr(charset, str[i]))
			addback_substr(&ret, &prev, i, str);
		i++;
	}
	addback_substr(&ret, &prev, i, str);
	if (!ret)
	{
		tmp = ft_calloc(1, sizeof(char));
		tmp[0] = 0;
		ft_lstadd_back(&ret, ft_lstnew(tmp));
	}
	return (ret);
}
