/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:47:26 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/10/10 16:54:41 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	change_i_to_c(char *str, long long n, unsigned int *len)
{
	int	minus;

	minus = 0;
	*len = 0;
	if (n < 0)
	{
		minus = 1;
		n = -n;
	}
	else if (n == 0)
	{
		str[0] = '0';
		(*len)++;
	}
	while (n != 0)
	{
		str[(*len)++] = (n % 10) + '0';
		n /= 10;
	}
	if (minus)
		str[(*len)++] = '-';
}

char	*ft_itoa(int n)
{
	char			*ans;
	char			str[12];
	unsigned int	idx;
	unsigned int	len;

	change_i_to_c(str, (long long)n, &len);
	ans = (char *)malloc(sizeof(char) * (len + 1));
	if (ans == NULL)
		return (NULL);
	ans[len] = '\0';
	idx = 0;
	while (idx < len)
	{
		ans[idx] = str[len - idx - 1];
		idx++;
	}
	return (ans);
}
