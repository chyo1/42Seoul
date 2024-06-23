/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:11:35 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/03/17 15:26:08 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"

int	parse_int(char *in, int (*check)(int))
{
	int	ret;

	ret = ft_atoi(in);
	if (!check || check(ret))
		return (ret);
	error(INVALID_FORMAT_ERR);
	return (ret);
}

double	parse_double(char *in, int (*check)(double))
{
	double	ret;

	ret = ft_atod(in);
	if (!check || check(ret))
		return (ret);
	error(INVALID_FORMAT_ERR);
	return (ret);
}

int	ft_atod_real_part(char **in, int *sign)
{
	double	ret;

	if (**in == '+' || **in == '-')
	{
		*sign = ',' - **in;
		(*in)++;
	}
	if (!(**in) || **in == '.')
		error(INVALID_FORMAT_ERR);
	ret = 0;
	while (**in && ft_isdigit(**in))
	{
		ret = ret * 10 + **in - '0';
		(*in)++;
	}
	if (!**in)
		return (ret);
	if (**in != '.')
		error(INVALID_FORMAT_ERR);
	else
	{
		(*in)++;
		return (ret);
	}
	return (0);
}

double	ft_atod(char *in)
{
	double	ret;
	double	tmp;
	int		sign;

	sign = 1;
	ret = (double)ft_atod_real_part(&in, &sign);
	tmp = 10;
	while (*in && ft_isdigit(*in))
	{
		ret += (*in - '0') / tmp;
		tmp *= 10;
		in++;
	}
	if (*in)
		error(INVALID_FORMAT_ERR);
	return (ret * sign);
}

double	equal_double(double target, double check)
{
	return (check - EPSILON <= target && target <= check + EPSILON);
}
