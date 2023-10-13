/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:38:37 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/10/13 12:20:26 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*source;
	size_t		i;

	dest = (char *)dst;
	source = (const char *)src;
	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = source[i];
		i++;
	}
	return (dst);
}
