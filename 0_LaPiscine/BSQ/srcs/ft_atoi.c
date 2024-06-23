/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:03:13 by younghoc          #+#    #+#             */
/*   Updated: 2023/08/10 11:22:45 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_atoi.h>

int	ft_atoi(char *str, int len)
{
	int	result;
	int	i;

	i = 0;
	result = 0;
	while ('0' <= *str && *str <= '9' && i < len)
	{
		result += *str - '0';
		str++;
		if ('0' <= *str && *str <= '9' && i + 1 < len)
			result *= 10;
		i++;
	}
	if (i != len)
		return (-1);
	return (result);
}
