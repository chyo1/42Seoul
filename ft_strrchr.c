/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:26:49 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/10/11 13:58:17 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*loc;

	loc = (NULL);
	while (*s)
	{
		if (c == *s)
			loc = (char *)s;
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (loc);
}
