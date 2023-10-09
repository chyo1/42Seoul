/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:38:37 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/10/06 11:38:38 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*source;
	size_t		i;

	dest = dst;
	source = src;
	i = 0;

	while (i < len)
	{
		dest[i] = source[i];
		i++;
	}
	return (dst);
}

#include <stdio.h>
#include <string.h>
int main(){
	char c[] = "12345";
	char d[] = "98765";
	memcpy(c, d, 4);
	for(int i=0;i<5;i++)
		printf("%c", c[i]);

	printf("\n");
	char c1[] = "12345";	
	ft_memcpy(c1, d, 4);
	for(int i=0;i<5;i++)
		printf("%c", c1[i]);
}
