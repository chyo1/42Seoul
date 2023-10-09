/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:29:18 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/10/07 15:29:18 by hyowchoi         ###   ########.fr       */
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
// abcdeba ab

unsigned int	get_end(char const *s1, char const *set, unsigned int end)
{
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
	unsigned int	idx;

	len = 0;
	while (s1[len])
		len++;
	start = get_start(s1, set, len);
	end = get_end(s1, set, len - 1);

	printf("s: %d e: %d\n", start, end);

	str = (char *)malloc(sizeof(char) * (end - start + 2));
	if (str == NULL)
		return (NULL);
	idx = 0;
	while (start <= end)
		str[idx++] = s1[start++];
	str[start] = 0;
	return (str);
}

int main()
{
	char c[] = "12345654321";
	char s[] = "123";
	printf("%s", ft_strtrim(c, s));
}