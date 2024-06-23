/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:07:05 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/07/20 13:07:13 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char *a, int end)
{
	while (end > 0)
	{
		write(1, &a[--end], 1);
	}
}

void	ft_putnbr(int nb)
{
	int		idx;
	char	a[12];

	idx = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	else if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	while (nb > 0)
	{
		a[idx++] = (nb % 10) + '0';
		nb /= 10;
	}
	print(a, idx);
}
