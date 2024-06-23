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
	int	fin_num;

	fin_num = a[1] - '0';
	write(1, a + 1, end);
	if (9 - fin_num + 1 != end)
		write(1, ", ", 2);
}

void	rec(char *a, int idx, int end)
{
	char	num;

	num = a[idx];
	if (idx == end)
	{
		print(a, end);
		return ;
	}
	while (num < '9')
	{
		num++;
		a[idx + 1] = num;
		rec(a, idx + 1, end);
	}
}

void	ft_print_combn(int n)
{
	char	a[10];

	a[0] = '0' - 1;
	rec(a, 0, n);
}
