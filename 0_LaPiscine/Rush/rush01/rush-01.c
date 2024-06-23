/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:48:22 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/07/28 16:48:24 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int is_error(char *arr)
{
	int	idx;
	int	cnt;

	idx = 0;
	cnt = 0;
	while(arr[idx])
	{
		if (!('1' <= arr[idx] && arr[idx] <= '9'))
			return (0);
		else
		{
			if (arr[idx + 1] != ' ' || arr[idx + 1] != '\0')
				return (0);
		}
		idx += 2;
		cnt++;
	}
	if ((cnt + 1) % 4)
		return (0);
	return ((cnt + 1) / 4 + 2);
}

int put_condition(int **arr, char *rc, int size)
{
	int	i;
	int	j;
	int	idx;

	i = 1;
	idx = 0;
	while (i++ < size)
		arr[0][i] = rc[idx++ * 2];
	i = 1;
	while (i++ < size)
		arr[size][i] = rc[idx++ * 2];
	i = 1;
	while (i++ < size)
		arr[i][0] = rc[idx++ * 2];
	i = 1;
	while (i++ < size)
		arr[i][size] = rc[idx++ * 2];

}

int	main(int argc, char **argv)
{
	int **pArr;
	int	size;
	int	i;

	i = 0;

	size = is_error(argv[1]);
	if(!size)
		write(1, "Error", 5);

	pArr = (int **)malloc(sizeof(int*) * size);
	while (i < size)
		pArr[i++] = (int*)malloc(sizeof(int) * size);
	put_condition(pArr, argv[1], size - 1);
}
