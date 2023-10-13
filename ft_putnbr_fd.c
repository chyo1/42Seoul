/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:46:45 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/10/13 15:48:07 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print(char *a, int end, int fd)
{
	while (end > 0)
		write(fd, &a[--end], 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		idx;
	char	a[12];

	idx = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	else if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	while (n > 0)
	{
		a[idx++] = (n % 10) + '0';
		n /= 10;
	}
	print(a, idx, fd);
}
