/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:07:05 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/07/21 20:44:12 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	init_a(char *a)
{
	a[0] = '0';
	a[1] = '0';
	a[2] = ' ';
	a[5] = ',';
	a[6] = ' ';
}

void	print(char *a)
{
	if (a[0] == '9' && a[1] == '8' && a[3] == '9' && a[4] == '9')
		write(1, a, 5);
	else
		write(1, a, 7);
}

void	comb2(char *a)
{
	a[3] = '0';
	while (a[3] <= '9')
	{
		a[4] = '0';
		while (a[4] <= '9')
		{	
			if (a[0] < a[3] || (a[0] == a[3] && a[1] < a[4]))
				print(a);
			a[4]++;
		}
		a[3]++;
	}
}

void	ft_print_comb2(void)
{
	char	a[7];

	init_a(a);
	while (a[0] <= '9')
	{
		a[1] = '0';
		while (a[1] <= '9')
		{
			comb2(a);
			a[1]++;
		}
		a[0]++;
	}
}
