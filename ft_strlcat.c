/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:39:10 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/10/10 19:09:16 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d;
	size_t	s;
	size_t	len_d;
	size_t	len_s;

	s = 0;
	len_d = 0;
	len_s = 0;
	while (dst[len_d] != '\0')
		len_d++;
	while (src[len_s] != '\0')
		len_s++;
	d = len_d;
	if (size < len_d)
		return (len_s + size);
	if (size > 0)
	{
		while (d < size - 1 && src[s] != '\0')
			dst[d++] = src[s++];
		dst[d] = '\0';
	}
	return (len_d + len_s);
}
