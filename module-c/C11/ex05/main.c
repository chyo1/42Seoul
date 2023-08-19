/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 20:26:31 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/08/04 20:26:32 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	plus(int a, int b);
int	minus(int a, int b);
int	mul(int a, int b);
int	div(int a, int b);
int	mod(int a, int b);

int	ft_atoi(char *str)
{
	long long	num;
	int			minus;

	minus = 1;
	num = 0;
	while (*str != '\0' && ((9 <= *str && *str <= 13) || *str == 32))
		str++;
	while (*str != '\0' && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	while (*str)
	{
		if ('0' <= *str && *str <= '9')
			num = num * 10 + (*str - '0');
		else
			return ((int) minus * num);
		str++;
	}
	return ((int) minus * num);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	get_ans(int n1, int n2, char *op)
{
	int	(*f[5])(int, int);

	f[0] = plus;
	f[1] = minus;
	f[2] = mul;
	f[3] = div;
	f[4] = mod;
	if (!ft_strcmp(op, "+"))
		(*f[0])(n1, n2);
	else if (!ft_strcmp(op, "-"))
		(*f[1])(n1, n2);
	else if (!ft_strcmp(op, "*"))
		(*f[2])(n1, n2);
	else if (!ft_strcmp(op, "/"))
		(*f[3])(n1, n2);
	else if (!ft_strcmp(op, "%"))
		(*f[4])(n1, n2);
	else
		write(1, "0\n", 2);
}

int	main(int argc, char **argv)
{
	int		value1;
	int		value2;
	char	*operateur;

	if (argc != 4)
		return (0);
	value1 = ft_atoi(argv[1]);
	operateur = argv[2];
	value2 = ft_atoi(argv[3]);
	get_ans(value1, value2, operateur);
}
