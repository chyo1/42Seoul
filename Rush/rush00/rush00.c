/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoo <jakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:43:46 by jakoo             #+#    #+#             */
/*   Updated: 2023/07/22 17:28:10 by jakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char *arr, int *xyarr, int i, int j);

	rush(int x, int y)
{
	char	arr[6];
	int		xyarr[2];
	int		i;
	int		j;

	if (x <= 0 || y <= 0)
		return ;
	xyarr[0] = x - 1;
	xyarr[1] = y - 1;
	/*arr[0] = 'o';
	arr[1] = 'o';
	arr[2] = 'o';
	arr[3] = 'o';
	arr[4] = '-';
	arr[5] = '|';*/
	i = 0;
	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
			ft_putchar(arr, xyarr, i++, j);
		write(1, "\n", 1);
		j++;
	}
}
