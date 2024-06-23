/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_find_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 20:44:10 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/08/05 20:44:11 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	fill_0_to_19_key(char **key);
void	fill_20_to_bil_key(char **key);

char	**get_find_arr(void)
{
	char	**num;
	int		i;

	i = 0;
	num = (char **)malloc(sizeof(char *) * 32);
	while (i < 32)
		num[i++] = (char *)malloc(sizeof(char) * 11);
	fill_0_to_19_key(num);
	fill_20_to_bil_key(num);
	return (num);
}
