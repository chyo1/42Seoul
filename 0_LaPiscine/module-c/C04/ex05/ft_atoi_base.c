/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:02:02 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/07/25 17:02:03 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	is_space(char c)
{
	if ((9 <= c && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	base_condition(char *b)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	l;

	i = 0;
	j = 0;
	l = 0;
	while (b[l])
		l++;
	if (l < 2)
		return (0);
	while (i < l)
	{
		if (b[i] == '+' || b[i] == '-' || is_space(b[i]))
			return (0);
		j = i + 1;
		while (j < l)
		{
			if (b[i] == b[j])
				return (0);
			j++;
		}
		i++;
	}
	return (l);
}

int	find_loc(char *s1, char c)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	get_num(char *str, char *base, int len_base)
{
	long long	num;
	int			minus;
	int			loc;

	minus = 1;
	num = 0;
	while (*str && is_space(*str))
		str++;
	while (*str != '\0' && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			minus *= -1;
			str++;
	}
	while (*str)
	{
		loc = find_loc(base, *str);
		if (loc >= 0)
			num = num * len_base + loc;
		else
			return ((int)minus * num);
		str++;
	}
	return ((int)minus * num);
}

int	ft_atoi_base(char *str, char *base)
{
	int	len_base;

	len_base = base_condition(base);
	if (!len_base)
		return (0);
	return (get_num(str, base, len_base));
}
