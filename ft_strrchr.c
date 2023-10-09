/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:26:49 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/10/06 17:26:51 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*loc;

	// cannot find & init
	loc = (NULL);
	while (*s)
	{
		if (c == *s)
			loc = s;
		s++;
	}
	return (loc);
}
