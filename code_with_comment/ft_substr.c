/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:44:32 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/10/14 18:51:52 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// s[start]부터 len만큼 자르기
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	s_len;

	s_len = ft_strlen(s);
	
	// len = 0이거나 시작 index가 문자열 길이를 넘어갈 때
	if (!len || start >= s_len)
		return (ft_calloc(1, sizeof(char)));
	
	// (start ~ 문자열 끝) < len일 경우 len을 작은 값으로 바꿔줌
	if (s_len - start < len)
		len = s_len - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, &s[start], len + 1);
	return (str);
}
