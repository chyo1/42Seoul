/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:26:49 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/10/13 17:20:48 by hyowchoi         ###   ########.fr       */
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
		// strchr에선 찾았을 때 return, 여기선 해당 위치 저장
		if (cmp == *s)
			loc = (char *)s;
		s++;
	}
	// 비교 문자가 null 문자일 경우 문자열의 끝 위치 반환
	if (cmp == 0)
		return ((char *)s);
	return (loc);
}
