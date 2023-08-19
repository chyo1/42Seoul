/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 16:43:15 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/08/06 16:43:17 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int nb);

void	plus(int a, int b)
{
	print(a + b);
}

void	minus(int a, int b)
{
	print(a - b);
}

void	mul(int a, int b)
{
	print(a * b);
}

void	div(int a, int b)
{
	if (b == 0)
		write(1, "Stop : division by zero\n", 24);
	else
		print(a / b);
}

void	mod(int a, int b)
{
	if (b == 0)
		write(1, "Stop : modulo by zero\n", 22);
	else
		print(a % b);
}
