/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeolee <gyeolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:54:36 by gyeolee           #+#    #+#             */
/*   Updated: 2023/07/29 14:14:13 by gyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	count_left_to_right(int **arr, int size, int *ij_arr);
int	count_right_to_left(int **arr, int size, int *ij_arr);
int	count_up_to_down(int **arr, int size, int *ij_arr);
int	count_down_to_up(int **arr, int size, int *ij_arr);

int	check_row_full(int **arr, int size, int *ij_arr)
{
	int	j;

	j = 1;
	while (j < size + 1)
	{
		if (arr[ij_arr[0]][j] == 0)
			return (0);
		j++;
	}
	return (1);
}

int	check_column_full(int **arr, int size, int *ij_arr)
{
	int	i;

	i = 1;
	while (i < size + 1)
	{
		if (arr[i][ij_arr[1]] == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_row(int **arr, int size, int *ij_arr)
{
	if (arr[ij_arr[0]][0] != count_left_to_right(arr, size, ij_arr))
		return (0);
	if (arr[ij_arr[0]][size + 1] != count_right_to_left(arr, size, ij_arr))
		return (0);
	return (1);
}

int	check_column(int **arr, int size, int *ij_arr)
{
	if (arr[0][ij_arr[1]] != count_up_to_down(arr, size, ij_arr))
		return (0);
	if (arr[size + 1][ij_arr[1]] != count_down_to_up(arr, size, ij_arr))
		return (0);
	return (1);
}

int	condition2(int **arr, int size, int *ij_arr)
{
	if (check_row_full(arr, size, ij_arr) == 1)
	{
		if (check_row(arr, size, ij_arr) == 0)
			return (0);
	}
	if (check_column_full(arr, size, ij_arr) == 1)
	{
		if (check_column(arr, size, ij_arr) == 0)
			return (0);
	}
	return (1);
}
