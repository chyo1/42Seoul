/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:57:05 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/07/30 15:56:17 by gyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>

int		dfs(int **arr, int size, int **result, int index);
int		is_argv_error(char *arr);
int		put_condition(char *con, int **arr, int max);
void	fill_minmax(int **arr, int **result, int size);
int		null_check(int **arr, int **result, int size);

int	**allocation(int size)
{
	int	**ptr;
	int	x;

	ptr = (int **)malloc(8 * size);
	x = 0;
	while (x < size)
	{
		ptr[x] = (int *)malloc(4 * size);
		x++;
	}
	return (ptr);
}

void	print_arr(int **arr, int size)
{
	int		i;
	int		j;
	char	c;

	i = 1;
	j = 1;
	while (i <= size)
	{
		j = 1;
		while (j <= size)
		{
			c = arr[i][j] + '0';
			write(1, &c, 1);
			if (j < size)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	init(int **arr, int **result, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			arr[i][j] = 0;
			result[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	ft_free(int **arr, int **result, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(arr[i]);
		free(result[i]);
		i++;
	}
	free(arr);
	free(result);
}

int	main(int argc, char **argv)
{
	int	**arr;
	int	**result;
	int	size;

	size = is_argv_error(argv[1]);
	arr = allocation(size);
	result = allocation(size);
	if (null_check(arr, result, size) == 1)
		return (0);
	init(arr, result, size);
	if (argc != 2 || !size || !put_condition(argv[1], arr, size - 2))
	{
		write(1, "Error", 5);
		ft_free(arr, result, size);
		return (0);
	}
	fill_minmax(arr, result, size - 2);
	if (!dfs(arr, size - 2, result, 0))
		write(1, "Error", 5);
	else
		print_arr(arr, size - 2);
	ft_free(arr, result, size);
	return (0);
}
