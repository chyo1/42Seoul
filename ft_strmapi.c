/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:12:09 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/10/10 17:37:52 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		ans[idx] = f(idx, s[idx]);
		idx++;
	}
	ans[idx] = '\0';
	return (ans);
}
