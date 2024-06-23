/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:38:44 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/10/14 11:11:12 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// memcpy에서 값이 덮어쓰여지는 걸 방지하기 위해 만든? 버전, 지금은 똑같이 동작
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*source;
	size_t		i;

	if (!dst && !src)
		return (NULL);
	dest = (char *)dst;
	source = (const char *)src;

	/*
	source < dest일 때 앞에서부터 복사하면 override의 위험성 존재
	이를 방지하기 위해 값을 뒤에서부터 복사
	*/
	if (len && source < dest)
	{
		while (--len > 0)
			dest[len] = source[len];
		dest[0] = source[0];
	}
	else if (len && dest <= source)
	{
		i = 0;
		while (i < len)
		{
			dest[i] = source[i];
			i++;
		}
	}
	return (dst);
}
