/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeolee <gyeolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:56:10 by gyeolee           #+#    #+#             */
/*   Updated: 2023/07/29 13:04:07 by gyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	count_left_to_right(int **arr, int size, int *ij_arr)
{
	int	standard;
	int	cnt;
	int	j;

	standard = arr[ij_arr[0]][1];
	cnt = 1;
	j = 2;
	while (j < size + 1)
	{
		if (standard < arr[ij_arr[0]][j])
		{
			standard = arr[ij_arr[0]][j];
			cnt++;
		}
		j++;
	}
	return (cnt);
}

int	count_right_to_left(int **arr, int size, int *ij_arr)
{
	int	standard;
	int	cnt;
	int	j;

	standard = arr[ij_arr[0]][size];
	cnt = 1;
	j = size - 1;
	while (j > 0)
	{
		if (standard < arr[ij_arr[0]][j])
		{
			standard = arr[ij_arr[0]][j];
			cnt++;
		}
		j--;
	}
	return (cnt);
}

int	count_up_to_down(int **arr, int size, int *ij_arr)
{
	int	standard;
	int	cnt;
	int	i;

	standard = arr[1][ij_arr[1]];
	cnt = 1;
	i = 2;
	while (i < size + 1)
	{
		if (standard < arr[i][ij_arr[1]])
		{
			standard = arr[i][ij_arr[1]];
			cnt++;
		}
		i++;
	}
	return (cnt);
}

int	count_down_to_up(int **arr, int size, int *ij_arr)
{
	int	standard;
	int	cnt;
	int	i;

	standard = arr[size][ij_arr[1]];
	cnt = 1;
	i = size - 1;
	while (i > 0)
	{
		if (standard < arr[i][ij_arr[1]])
		{
			standard = arr[i][ij_arr[1]];
			cnt++;
		}
		i--;
	}
	return (cnt);
}
