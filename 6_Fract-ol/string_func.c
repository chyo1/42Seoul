/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:27:48 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/01/14 13:17:27 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;
	unsigned int	i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] != (str2[i]))
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

static void	check_invalid_num(char *str)
{
	unsigned int	idx;

	idx = 0;
	if (str[idx] == '-' || str[idx] == '+' || str[idx] == '.')
	{
		// case : "+" "-" "." "+." "-."
		if (str[1] == '\0' || str[0] == '.' || str[1] == '.')
		{
			write(1, "Error : wrong input\n", 20);
			exit(1);
		}
		idx++;
	}
	while (str[idx] && '0' <= str[idx] && str[idx] <= '9')
		idx++;
	if (str[idx] == '.')
		idx++;
	while (str[idx] && '0' <= str[idx] && str[idx] <= '9')
		idx++;
	// Invalid character, empty string ""
	if (str[0] == '\0' || str[idx])
	{
		write(1, "Error : wrong input\n", 20);
		exit(1);
	}
}

static double	str_to_int(char *str, int len)
{
	double			num;
	unsigned int	idx;

	num = 0;
	idx = 0;
	if (str[idx] == '-')
		idx++;
	while (str[idx] && '0' <= str[idx] && str[idx] <= '9')
	{
		num += (str[idx] - '0') * pow(10, --len);
		idx++;
	}
	return (num);
}

static double	str_to_dec(char *str)
{
	double			dec;
	unsigned int	idx;

	dec = 0;
	idx = 0;
	while (str[idx] && '0' <= str[idx] && str[idx] <= '9')
	{
		dec += pow(0.1, idx + 1) * (str[idx] - '0');
		idx++;
	}
	return (dec);
}

double	str_to_double(char *str)
{
	int				sign;
	unsigned int	int_idx;

	check_invalid_num(str);
	sign = 0;
	int_idx = 0;
	if (str[int_idx] == '-' || str[int_idx] == '+')
	{
		if (str[int_idx] == '-')
			sign = -1;
		int_idx++;
	}
	while (str[int_idx] && str[int_idx] != '.')
		int_idx++;
	if (sign == -1)
		return (sign * (str_to_int(str, int_idx - 1) + str_to_dec(&str[int_idx + 1])));
	return (str_to_int(str, int_idx) + str_to_dec(&str[int_idx + 1]));
}
