/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:40:07 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/10/13 17:14:44 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cmp(const char *s1, const char *s2, size_t i, size_t n)
{
	size_t	start;

	start = 0;
	while ((s1[i] != '\0' && s2[start] != '\0') && i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[start])
			return ((unsigned char)s1[i] - (unsigned char)s2[start]);
		i++;
		start++;
	}
	if (s2[start] != '\0')
		return (1);
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	s;
	int		val;

	s = 0;
	if (!haystack && !len)
		return (NULL);
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[s] != '\0' && s < len)
	{
		val = cmp(haystack, needle, s, len);
		if (val == 0)
			return ((char *)(haystack + s));
		s++;
	}
	return (NULL);
}
