/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DFS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeolee <gyeolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 13:21:41 by gyeolee           #+#    #+#             */
/*   Updated: 2023/07/30 12:53:07 by gyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	condition1(int **arr, int size, int *ij_arr);
int	condition2(int **arr, int size, int *ij_arr);

int	put_ij_arr(int ij_arr[], int index, int size)
{
	ij_arr[0] = index / size + 1;
	ij_arr[1] = index % size + 1;
	return (1);
}

int	l(int **arr, int s)
{
	int	ij[2];

	ij[0] = s;
	ij[1] = s;
	if (condition1(arr, s, ij) && condition2(arr, s, ij))
		return (1);
	return (0);
}

int	dfs(int **arr, int size, int **result, int index)
{
	int	n;
	int	ij_arr[2];

	if (put_ij_arr(ij_arr, index, size) && (ij_arr[0] > size) && l(arr, size))
		return (1);
	n = 0;
	while (++n <= size)
	{
		if (result[ij_arr[0]][ij_arr[1]] > 0)
		{
			arr[ij_arr[0]][ij_arr[1]] = result[ij_arr[0]][ij_arr[1]];
			if (dfs(arr, size, result, index + 1) == 1)
				return (1);
			else
				return (0);
		}
		arr[ij_arr[0]][ij_arr[1]] = n;
		if (condition1(arr, size, ij_arr) && condition2(arr, size, ij_arr))
		{
			if (dfs(arr, size, result, index + 1) == 1)
				return (1);
		}
	}
	arr[ij_arr[0]][ij_arr[1]] = 0;
	return (0);
}
