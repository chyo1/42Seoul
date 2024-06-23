/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:47:26 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/10/14 12:42:01 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	change_i_to_c(char *str, long long n)
{
	int				minus;
	unsigned int	idx;

	minus = 0;
	idx = 0;
	if (n < 0)
	{
		minus = 1;
		n = -n;
	}
	else if (n == 0)
		str[idx++] = '0';
	while (n != 0)
	{
		str[idx++] = (n % 10) + '0';
		n /= 10;
	}
	if (minus)
		str[idx++] = '-';
}

static unsigned int	get_len(int n)
{
	unsigned int	idx;

	idx = 0;
	if (n <= 0)
		idx = 1;
	while (n != 0)
	{
		idx++;
		n /= 10;
	}
	return (idx);
}

static void	str_swap(char *ans, unsigned int len)
{
	unsigned int	idx;
	char			tmp;

	ans[len] = '\0';
	idx = 0;
	while (idx < len / 2)
	{
		tmp = ans[idx];
		ans[idx] = ans[len - idx - 1];
		ans[len - idx -1] = tmp;
		idx++;
	}
}

char	*ft_itoa(int n)
{
	char			*ans;
	unsigned int	len;

	len = get_len(n);
	ans = (char *)malloc(sizeof(char) * (len + 1));
	if (ans == NULL)
		exit (1);
	change_i_to_c(ans, (long long)n);
	str_swap(ans, len);
	return (ans);
}
