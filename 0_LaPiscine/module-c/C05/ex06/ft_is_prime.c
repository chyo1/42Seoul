/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:26:57 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/07/28 15:26:58 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	long long	i;

	if (nb < 2)
		return (0);
	i = 2;
	while (i * i <= (long long)nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}
