/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:39:40 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/10/13 12:08:08 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	cmp;

	cmp = (char)c;
	while (*s)
	{
		if (cmp == *s)
			return ((char *)s);
			s++;
	}
	if (cmp == 0)
		return ((char *)s);
	return (NULL);
}
