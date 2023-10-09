/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:40:29 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/10/06 11:40:30 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*a;
	size_t	len;
	size_t	i;

	len = 0;
	while (s1[len])
		len++;
	a = (char *)malloc(sizeof(char) * (len + 2)); // length + null
	// memory allocation error
	if (a == NULL)
		return (NULL);
	while (i <= len)
	{
		a[i] = s1[i];
		i++;
	}
	a[i] = NULL;
	return (NULL);
}
