/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:40:22 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/10/06 11:40:24 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*c;
	size_t	i;

	c = (size_t *)malloc(count * sizeof(size));
	// memory allocation error
	if (c == NULL)
		return (NULL);
	while (i < count)
	{
		c[i] = 0;
		i++;
	}
	return (c);
}
