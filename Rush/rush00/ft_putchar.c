/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoo <jakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:56:02 by jakoo             #+#    #+#             */
/*   Updated: 2023/07/22 17:25:12 by jakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char *arr, int *xyarr, int i, int j)
{
	char	arr[];
	char	xyarr[];


	if (i == 0 && j == 0)
		write(1, &arr[0], 1);
	else if (i == xyarr[0] && j == 0)
		write(1, &arr[1], 1);
	else if (i == 0 && j == xyarr[1])
		write(1, &arr[2], 1);
	else if (i == xyarr[0] && j == xyarr[1])
		write(1, &arr[3], 1);
	else if (j == 0 || j == xyarr[1])
		write(1, &arr[4], 1);
	else if (i == 0 || i == xyarr[0])
		write(1, &arr[5], 1);
	else
		write(1, " ", 1);
}
