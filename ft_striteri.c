/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:25:07 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/10/10 17:30:18 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	len;
	unsigned int	idx;
	char			*ans;

	len = 0;
	idx = 0;
	while (s[len])
		len++;
	ans = (char *)malloc(sizeof(char) * (len + 1));
	if (ans == NULL)
		return (NULL);
	while (idx < len)
	{
		f(idx, s[idx]);
		ans[idx] = s[idx];
		idx++;
	}
	ans[idx] = '\0';
	return (ans);
}
