/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeolee <gyeolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:09:08 by gyeolee           #+#    #+#             */
/*   Updated: 2023/07/30 12:52:15 by gyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	condition1(int **arr, int size, int *ij_arr)
{
	int	row;
	int	column;

	row = 1;
	while (row < size + 1)
	{
		if (row != ij_arr[0])
		{
			if (arr[ij_arr[0]][ij_arr[1]] == arr[row][ij_arr[1]])
				return (0);
		}
		row++;
	}
	column = 1;
	while (column < size + 1)
	{
		if (column != ij_arr[1])
		{
			if (arr[ij_arr[0]][ij_arr[1]] == arr[ij_arr[0]][column])
				return (0);
		}
		column++;
	}
	return (1);
}
