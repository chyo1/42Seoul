/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:05:19 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/07/27 18:06:45 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_iterative_factorial(int nb)
{
	int	f;

	if (nb < 0)
		return (0);
	f = 1;
	while (nb > 0)
		f *= nb--;
	return (f);
}
