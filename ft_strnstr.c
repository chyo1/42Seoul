/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:40:07 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/10/10 18:50:47 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	s;
	int				val;

	s = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[s] != '\0')
	{
		val = ft_strncmp(&haystack[s], needle, len);
		if (val == 0)
			return ((char *)(haystack + s));
		s++;
	}
	return (NULL);
}
