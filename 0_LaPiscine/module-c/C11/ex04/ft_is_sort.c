/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 20:26:31 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/08/04 20:26:32 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	flag;
	int	idx;

	idx = 0;
	flag = 0;
	while (!flag && idx < length - 1)
	{
		flag = (*f)(tab[idx], tab[idx + 1]);
		idx++;
	}
	while (idx < length - 1)
	{
		if (flag > 0)
		{
			if ((*f)(tab[idx], tab[idx + 1]) < 0)
				return (0);
		}
		else
		{
			if ((*f)(tab[idx], tab[idx + 1]) > 0)
				return (0);
		}
		idx++;
	}
	return (1);
}
