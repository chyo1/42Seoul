/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:43:14 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/07/22 13:43:18 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	is_printable(unsigned char c)
{
	if (32 <= c && c <= 126)
		return (-1);
	return (c);
}

void	print_hex(int num)
{
	int		d[2];
	char	hex[2];

	d[0] = num / 16;
	d[1] = num % 16;
	if (d[0] < 10)
		hex[0] = d[0] + '0';
	else
		hex[0] = (d[0] - 10) + 'a';
	if (d[1] < 10)
		hex[1] = d[1] + '0';
	else
		hex[1] = (d[1] - 10) + 'a';
	write(1, "\\", 1);
	write(1, hex, 2);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned int	i;
	int				result;

	i = 0;
	while (str[i] != '\0')
	{
		result = is_printable((unsigned char) str[i]);
		if (result == -1)
			write(1, str + i, 1);
		else
			print_hex(result);
		i++;
	}
}
