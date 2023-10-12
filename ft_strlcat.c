/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:39:10 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/10/12 14:49:16 by hyowchoi         ###   ########.fr       */
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
	i = 0;
	if (size < len_d)
		return (len_s + size);
	if (size > 0)
	{
		while (len_d + i + 1 < size && src[i] != '\0')
		{
			dst[len_d + i] = src[i];
			i++;
		}
		dst[len_d + i] = '\0';
	}
	return (len_d + len_s);
}

// int main()
// {
// 	char a[] = "asdf";
// 	printf("%lu", ft_strlcat(a, NULL, 0));
// }