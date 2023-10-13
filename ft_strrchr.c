/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:26:49 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/10/13 12:07:33 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*loc;
	char	cmp;

	cmp = (char)c;
	loc = (NULL);
	while (*s)
	{
		if (cmp == *s)
			loc = (char *)s;
		s++;
	}
	if (cmp == 0)
		return ((char *)s);
	return (loc);
}

