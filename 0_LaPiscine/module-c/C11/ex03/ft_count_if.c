/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 20:25:32 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/08/04 20:25:33 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	cnt;
	int	idx;

	cnt = 0;
	idx = 0;
	while (idx < length)
	{
		if ((*f)(tab[idx]) != 0)
			cnt++;
		idx++;
	}
	return (cnt);
}
