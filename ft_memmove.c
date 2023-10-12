/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:38:44 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/10/12 12:58:12 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*source;
	size_t		i;

	if (!dst && !src)
		return (NULL);
	dest = dst;
	source = src;
	i = 0;
	if (len && source < dest)
	{
		while (--len > 0)
			dest[len] = source[len];
		dest[0] = source[0];
	}
	else if (len && dest <= source)
	{
		while (i < len)
		{
			dest[i] = source[i];
			i++;
		}
	}
	return (dst);
}
