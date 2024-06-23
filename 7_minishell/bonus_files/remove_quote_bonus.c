/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:45:06 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 12:45:07 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_quotes(char *str)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] == '\"' || str[i] == '\'')
			cnt++;
		i++;
	}
	return (cnt);
}

char	*remove_quote(char *str)
{
	size_t	cnt;
	size_t	i;
	size_t	len;
	char	*ret;
	char	*ori;

	ori = str;
	if (!str)
		return (0);
	cnt = count_quotes(str);
	if (!cnt)
		return (ori);
	len = ft_strlen(str);
	ret = ft_calloc(len - cnt + 1, sizeof(char));
	i = 0;
	while (*str)
	{
		if (*str != '\"' && *str != '\'')
			ret[i++] = *str;
		str++;
	}
	free(ori);
	return (ret);
}
