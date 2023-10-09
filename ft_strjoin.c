/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:16:59 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/10/07 15:17:00 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	len1;
	unsigned int	len2;

	len1 = 1;
	len2 = 1;
	while (s1[len1 - 1])
		len1++;
	while (s2[len2 - 1])
		len2++;
	str = (char *)malloc(sizeof(char) * (len1 + len2 + 2));
	if (str == NULL)
		return (NULL);
	len1 = 0;
	while (*s1)
	{
		str[len1++] = *s1;
		s1++;
	}
	while (*s2)
	{
		str[len1++] = *s2;
		s2++;
	}
	return (str);
}
