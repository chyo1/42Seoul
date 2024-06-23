/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:25:28 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/07/21 18:25:55 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_rev_int_tab(int *tab, int size)
{
	int	start;
	int	tmp;

	start = 0;
	size--;
	while (start < size)
	{
		tmp = tab[size];
		tab[size] = tab[start];
		tab[start] = tmp;
		start++;
		size--;
	}
}
