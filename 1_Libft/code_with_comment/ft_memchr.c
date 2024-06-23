/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:39:53 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/10/13 15:43:27 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;
	unsigned char	cmp;

	// man page에 unsigned char로 비교
	/*
	why? memory가 8비트씩 비교연산을 하는데 signed로 비교할 경우
	127 ~의 수가 c에 들어왔을 때 비교할 수 없기 때문
	*/
	str = (unsigned char *)s;
	cmp = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == cmp)
			return (str + i);
		i++;
	}
	return (NULL);
}
