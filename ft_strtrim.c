/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:29:18 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/10/12 17:07:17 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_set(char a, char const *set)
{
	while (*set)
	{
		if (a == *set)
			return (1);
		set++;
	}
	return (0);
}

unsigned int	get_start(char const *s1, char const *set, unsigned int end)
{
	unsigned int	start;

	start = 0;
	while (start < end)
	{
		if (!find_set(s1[start], set))
			return (start);
		start++;
	}
	return (start);
}

unsigned int	get_end(char const *s1, char const *set, unsigned int end)
{
	if (end == (unsigned int)-1)
		return (0);
	while (0 < end)
	{
		if (!find_set(s1[end], set))
			return (end);
		end--;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*str;
	unsigned int	start;
	unsigned int	end;
	unsigned int	len;

	len = ft_strlen(s1);
	start = get_start(s1, set, len);
	end = get_end(s1, set, len - 1);
	if (*s1 == '\0' || start == len || end == 0)
		return ((char *)ft_calloc(1, sizeof(char)));
	str = (char *)malloc(sizeof(char) * (end - start + 2));
	if (str == NULL)
		return (NULL);
	strlcpy(str, (s1 + start), end - start + 2);
	return (str);
}
