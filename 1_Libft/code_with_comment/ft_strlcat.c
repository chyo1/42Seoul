/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:39:10 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/10/14 11:28:53 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_d;
	size_t	len_s;

	if (!dst && !size)
		return (ft_strlen(src));
	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
	
	// 이 경우 복사하려면 len_s + size만큼의 공간이 더 필요함을 return
	/*
	size < len_d인데 왜 반환값은 size?
	len_d의 길이와 상관 없이 buffer size만큼만 읽을 것이기에
	*/
	if (size < len_d)
		return (len_s + size);
	if (size > 0)
	{
		i = 0;
		while (len_d + i + 1 < size && src[i] != '\0')
		{
			dst[len_d + i] = src[i];
			i++;
		}
		dst[len_d + i] = '\0';
	}
	// 버퍼 사이즈와 비교해 size < len_d + len_s라면
	// 문자열 전체가 복사가 되지 않았다는 걸 알 수 있음
	return (len_d + len_s);
}
