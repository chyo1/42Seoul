/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_condition.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:30:47 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/07/30 13:19:46 by gyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	put_condition_line(int num, int cnt, int **arr, int max)
{
	if (cnt < max)
		arr[0][cnt % max + 1] = num;
	else if (cnt < max * 2)
		arr[max + 1][cnt % max + 1] = num;
	else if (cnt < max * 3)
		arr[cnt % max + 1][0] = num;
	else if (cnt < max * 4)
		arr[cnt % max + 1][max + 1] = num;
}

int	put_condition(char *con, int **arr, int max)
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
			put_condition_line(num, cnt, arr, max);
			cnt++;
		}
		idx++;
	}
	return (1);
}

void	fill_line(int **result, int size, int r, int c)
{
	int	i;

	i = size;
	if (r)
	{
		while (i > 0)
		{
			result[r][i] = i;
			i--;
		}
	}
	else
	{
		while (i > 0)
		{
			result[i][c] = i;
			i--;
		}
	}
}

void	fill_line2(int **result, int size, int r, int c)
{
	int	i;

	i = size;
	if (r)
	{
		while (i > 0)
		{
			result[r][size - i + 1] = i;
			i--;
		}
	}
	else
	{
		while (i > 0)
		{
			result[size - i + 1][c] = i;
			i--;
		}
	}
}

void	fill_minmax(int **arr, int **result, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[0][i + 1] == 1)
			result[1][i + 1] = size;
		else if (arr[0][i + 1] == size)
			fill_line(result, size, 0, i + 1);
		if (arr[size + 1][i + 1] == 1)
			result[size][i + 1] = size;
		else if (arr[size + 1][i + 1] == size)
			fill_line2(result, size, 0, i + 1);
		if (arr[i + 1][0] == 1)
			result[i + 1][1] = size;
		else if (arr[i + 1][0] == size)
			fill_line(result, size, i + 1, 0);
		if (arr[i + 1][size + 1] == 1)
			result[i + 1][size] = size;
		else if (arr[i + 1][size + 1] == size)
			fill_line2(result, size, i + 1, 0);
		i++;
	}
}
