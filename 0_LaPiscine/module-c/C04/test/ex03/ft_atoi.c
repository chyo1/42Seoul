/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:01:41 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/07/25 17:01:43 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c)
{
	if ((9 <= c && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	is_digit(char c)
{
	if (!('0' <= c && c <= '9'))
		return (0);
	return (1);
}

int	ft_atoi(char *str)
{
	long long	num;
	int			minus;

	minus = 1;
	num = 0;
	while (*str != '\0' && is_space(*str))
		str++;
	while (*str != '\0' && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			minus *= -1;
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
