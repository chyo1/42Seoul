/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:01:51 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/08/01 19:01:52 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "ft_stock_str.h"

void	print(char *a, int end)
{
	while (end > 0)
		write(1, &a[--end], 1);
}

void	print_size(int nb)
{
	int		idx;
	char	a[12];

	idx = 0;
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	while (nb > 0)
	{
		a[idx++] = (nb % 10) + '0';
		nb /= 10;
	}
	print(a, idx);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	idx;
	int	str_len;

	idx = 0;
	while (par[idx].str != NULL)
	{
		str_len = par[idx].size;
		write(1, par[idx].str, str_len);
		write(1, "\n", 1);
		print_size(par[idx].size);
		write(1, "\n", 1);
		write(1, par[idx].copy, str_len);
		write(1, "\n", 1);
		idx++;
	}
}
