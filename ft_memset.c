/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:37:18 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/10/06 11:37:19 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*str;

	str = b;
	i = 0;
	while (i < len)
	{
		str[i] = c; // str -> char , c -> int ?
		i++;
	}
	return (b);
}

#include <stdio.h>
#include <string.h>
int main()
{
	char a[] = "abcd";
	char b[] = "abcd";
	size_t len = 8;

	printf("%s %s", memset(a, 'f', len), b);
}