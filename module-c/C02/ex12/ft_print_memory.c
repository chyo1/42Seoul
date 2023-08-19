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

void	print_addr(long long a)
{
	char	arr[16];
	int		idx;
	int		num;

	idx = 15;
	while (idx >= 0)
	{
		num = a % 16;
		if (num < 10)
			arr[idx--] = num + '0';
		else
			arr[idx--] = (num - 10) + 'a';
		a /= 16;
	}
	write(1, arr, 16);
	write(1, ": ", 2);
}

void	get_hexadecimal(unsigned int num)
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
	write(1, hex, 2);
}

void	print_hexa(unsigned char *val, unsigned int idx, unsigned int size)
{
	int	cnt;

	cnt = 0;
	while (cnt < 16)
	{
		if (size <= idx)
		{
			while (cnt < 16)
			{
				write(1, "  ", 2);
				if (cnt % 2 == 1)
					write(1, " ", 1);
				cnt++;
			}
		}
		else
			get_hexadecimal((unsigned int)*(val + idx));
		if (cnt % 2 == 1)
			write(1, " ", 1);
		idx++;
		cnt++;
	}
}

void	print_str(unsigned char *str, unsigned int idx, unsigned int size)
{
	int	i;

	i = 0;
	while (i < 16 && idx < size)
	{
		if (32 <= *(str + idx) && *(str + idx) <= 126)
			write(1, (str + idx), 1);
		else
			write(1, ".", 1);
	i++;
	idx++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*a;

	a = (unsigned char *) addr;
	if (size == 0)
		return (addr);
	i = 0;
	while (i < size)
	{
		print_addr((long long)&addr[i]);
		print_hexa(a, i, size);
		print_str(addr, i, size);
		i += 16;
	}
	return (addr);
}
