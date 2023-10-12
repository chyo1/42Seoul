/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:40:22 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/10/12 15:22:45 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*c;
	size_t	i;

	i = 0;
	if (size && count > (size_t) - 1 / size)
		return (NULL);
	c = (char *)malloc(count * size);
	printf("c: %p\n", c);
	if (c == NULL)
		return (NULL);
	while (i / size < count)
	{
		c[i] = 0;
		i++;
	}
	return ((void *)c);
}

int main()
{
	ft_calloc(1, 0);
}