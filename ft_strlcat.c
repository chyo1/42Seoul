/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:39:10 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/10/06 11:39:11 by hyowchoi         ###   ########.fr       */
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
	// 버퍼가 dst 실행할 때 사용한 버퍼라면
	// 복사를 안 하면 len_src + size -> 더 필요한 버퍼 사이즈 -1 (null)
	if (size < len_d)
		return (len_s + size);

	if (size > 0)
	{
		while (d < size - 1 && src[s] != '\0')
			dst[d++] = src[s++];
		dst[d] = '\0';
	}

	// len_dst + len_src -> 완전한 문자열 길이 -1
	// size - return_val < 0 : 복사가 다 안 됨
	return (len_d + len_s);
}