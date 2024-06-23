/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   null_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeolee <gyeolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 14:58:03 by gyeolee           #+#    #+#             */
/*   Updated: 2023/07/30 16:00:48 by gyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_free(int **arr, int **result, int size);

int	null_check(int **arr, int **result, int size)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (arr == 0 || result == 0)
		flag = 1;
	while (i < size)
	{
		if (arr[i] == 0 || result == 0)
			flag = 1;
		i++;
	}
	if (flag == 1)
	{
		write(1, "Error", 5);
		ft_free(arr, result, size);
	}
	return (flag);
}
