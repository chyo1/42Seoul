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
		if (b[i] == '+' || b[i] == '-')
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

void	print_atoi(int nbr, char *base, unsigned int div)
{
	char		print[32];
	int			idx;
	long long	num;

	idx = 0;
	num = (long long)nbr;
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	else if (num == 0)
	{
		write(1, &base[0], 1);
		return ;
	}
	while (num > 0)
	{
		print[idx++] = base[num % div];
		num /= div;
	}
	while (idx > 0)
		write(1, &print[--idx], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	len_base;

	len_base = base_condition(base);
	if (len_base)
		print_atoi(nbr, base, len_base);
}
