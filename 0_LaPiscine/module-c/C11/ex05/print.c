/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:19:02 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/08/06 17:19:02 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	show(char *a, int end)
{
	while (end > 0)
		write(1, &a[--end], 1);
	write(1, "\n", 1);
}

void	print(int nb)
{
	int		idx;
	char	a[12];

	idx = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648\n", 12);
		return ;
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	else if (nb == 0)
	{
		write(1, "0\n", 2);
		return ;
	}
	while (nb > 0)
	{
		a[idx++] = (nb % 10) + '0';
		nb /= 10;
	}
	show(a, idx);
}
