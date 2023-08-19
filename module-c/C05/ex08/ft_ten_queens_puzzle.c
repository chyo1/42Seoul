/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:27:34 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/07/28 15:27:35 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print(int chess[5])
{
	int		i;
	char	c;

	i = 0;
	while (i < 5)
	{
		c = chess[i] + '0';
		write(1, &c, 1);
		c++;
		i++;
	}
	write(1, "\n", 1);
	return ;
}

int	get_abs(int a, int b)
{
	if (a < b)
		return (b - a);
	return (a - b);
}

int	is_in(int chess[5], int row, int num)
{
	int	i;

	i = 0;
	while (i < row)
	{
		if (chess[i] == num || get_abs(row, i) == get_abs(num, chess[i]))
			return (1);
		i++;
	}
	return (0);
}

int	get_ans(int chess[5], int row)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	if (row == 5)
	{
		print(chess);
		return (1);
	}
	while (i < 5)
	{
		if (!is_in(chess, row, i))
		{
			chess[row] = i;
			cnt += get_ans(chess, row + 1);
		}
		i++;
	}
	return (cnt);
}

int	ft_ten_queens_puzzle(void)
{
	int	i;
	int	chess[5];

	i = 0;
	while (i < 10)
		chess[i++] = 5;
	return (get_ans(chess, 0));
}
