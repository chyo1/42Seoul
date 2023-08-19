/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:33:32 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/07/30 16:33:33 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*str;
	int		src_len;
	int		i;

	i = 0;
	src_len = 0;
	while (src[src_len])
		src_len++;
	str = (char *)malloc(sizeof(char) * (src_len + 1));
	if (!str)
		return (0);
	while (i < src_len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
