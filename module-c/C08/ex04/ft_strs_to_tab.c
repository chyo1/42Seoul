/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:56:31 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/08/02 10:56:32 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	get_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*str_cpy(char *src, int src_len)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (src_len + 1));
	if (!str)
		return (NULL);
	while (i < src_len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*str;
	int					idx;

	idx = 0;
	str = (struct s_stock_str *)malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (str == NULL)
		return (NULL);
	while (idx < ac)
	{
		str[idx].size = get_strlen(av[idx]);
		str[idx].str = av[idx];
		str[idx].copy = str_cpy(av[idx], str[idx].size);
		idx++;
	}
	str[ac].str = NULL;
	return (str);
}
