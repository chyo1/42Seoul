/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:57:05 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/07/28 17:57:09 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	argv_error_condition(char c, int *cnt, int *plus, int *blank)
{
	if (c == ' ')
	{
		if (*blank)
			return (0);
		*blank = 1;
	}
	else if (c == '+')
	{
		if (*plus)
			return (0);
		*plus = 1;
	}
	else if ('1' <= c && c <= '9')
	{
		if (*blank == 0)
			return (0);
		(*cnt)++;
		*blank = 0;
		*plus = 0;
	}
	return (1);
}

int	is_argv_error(char *arr)
{
	int	i;
	int	cnt;
	int	blank;
	int	plus;

	i = 0;
	cnt = 0;
	plus = 0;
	blank = 1;
	while (arr[i] == ' ' || arr[i] == '+' || ('1' <= arr[i] && arr[i] <= '9'))
	{
		if (!argv_error_condition(arr[i], &cnt, &plus, &blank))
			return (0);
		i++;
	}
	if (cnt % 4 || arr[i] != '\0')
		return (0);
	return (cnt / 4 + 2);
}

void	put_line(int num, int cnt, int arr[][6], int max)
{
	if (cnt < max)
		arr[0][cnt % 4 + 1] = num;

	else if (cnt < max * 2)
		arr[max + 1][cnt % 4 + 1] = num;

	else if (cnt < max * 3)
		arr[cnt % 4 + 1][0] = num;

	else if (cnt < max * 4)
		arr[cnt % 4 + 1][max + 1] = num;
}

int	put_condition(char *con, int arr[][6], int max)
{
	int	idx;
	int	loc;
	int	num;
	int	cnt;

	idx = 0;
	loc = 0;
	cnt = 0;
	while (con[idx])
	{
		if ('1' <= con[idx] && con[idx] <= '9')
		{
			num = con[idx] - '0';
			if (num > max)
				return (0);
			put_line(num, cnt, arr, max);
			cnt++;
		}
		idx++;
	}
	return (1);
}


void	fill_line(int arr[][6], int result[][6], int size, int r, int c)
{
	int	i;

	i = size;
	if (r) // fill col
	{
		while (i > 0)
		{
			arr[r][i] = result[r][i] = i;
			i--;
		}
	}
	else // fill row
	{
		while (i > 0)
		{
			arr[i][c] = result[i][c] = i;
			i--;
		}
	}
}

void	fill_minmax(int arr[][6], int result[][6], int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[0][i + 1] == 1)
			arr[1][i + 1] = result[1][i + 1] = 4;
		else if (arr[0][i + 1] == size)
			fill_line(arr, result, size, 0, i + 1);
		if (arr[5][i + 1] == 1)
			arr[4][i + 1] = result[4][i + 1] = 4;
		else if (arr[5][i + 1] == size)
			fill_line(arr, result, size, 0, i + 1);
		if (arr[i + 1][0] == 1)
			arr[i + 1][1] = result[i + 1][1] = 4;
		else if (arr[i + 1][0] == size)
			fill_line(arr, result, size, i + 1, 0);
		if (arr[i + 1][5] == 4)
			arr[i + 1][4] = result[i + 1][4] = 4;
		else if (arr[i + 1][5] == size)
			fill_line(arr, result, size, i + 1, 0);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	arr[6][6]={0,};
	int	result[6][6] = {0, };
	int	size;
	//int ijarray[];

	if (argc != 2)
		return (0);

	size = is_argv_error(argv[1]);
	printf("%d\n", size);
	if (!size)
	{
		write(1, "Error", 5);
		return (0);
	}
	if (!put_condition(argv[1], arr, size - 2))
	{
		write(1, "Error", 5);
		return (0);
	}

	fill_minmax(arr, result, 4);
/* 
	DFS(arr, 4, result)
*/
	/* 
	배열 출력
	for(int i=0;i<6;i++){
		for(int j =0;j<6;j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	} 
	printf("\n");
	for(int i=0;i<6;i++){
		for(int j =0;j<6;j++)
			printf("%d ", result[i][j]);
		printf("\n");
	}  */
}

/* DFS()
{

	n = 1;
	while(n <= 4)
	{
		if (result[i][j] > 0)
			DFS()
		if (condition1(arr, size, i, j)conditoin2(arr, size, i, j))
			arr[i][j] = n;
			if (DFS() == 1)
		n++;
	}
} */