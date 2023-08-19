/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:36:26 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/07/27 18:38:44 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_sqrt(int nb)
{
	unsigned int	i;
	unsigned int	cmp;

	if (nb <= 0)
		return (0);
	cmp = (unsigned int)nb;
	i = 1;
	while (i * i <= cmp)
	{
		if (i * i == cmp)
			return (i);
		i++;
	}
	return (0);
}
