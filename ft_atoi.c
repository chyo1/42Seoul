/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:40:13 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/10/06 11:40:14 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	is_space(char c)
{
	if ((9 <= c && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	is_digit(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long long	num;
	int			minus;

	minus = 1;
	num = 0;
	while (*str != '\0' && is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus = -1;
		str++;
	}
	while (*str)
	{
		if (is_digit(*str))
			num = num * 10 + (*str - '0');
		else
			return ((int) minus * num);
		str++;
	}
	return ((int) minus * num);
}


int main()
{
	char s[] = "  2147483648";
	printf("%d %d", atoi(s), ft_atoi(s));
}