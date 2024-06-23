/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:34:16 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/07/30 16:34:17 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*int_to_char(int num, char *base_to, unsigned int len_base_to);

int	is_space(char c)
{
	if ((9 <= c && c <= 13) || c == 32)
		return (1);
	return (0);
}

unsigned int	base_condition(char *b)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	l;

	i = 0;
	j = 0;
	l = 0;
	while (b[l])
		l++;
	if (l < 2)
		return (0);
	while (i < l)
	{
		if (b[i] == '+' || b[i] == '-' || is_space(b[i]))
			return (0);
		j = i + 1;
		while (j < l)
		{
			if (b[i] == b[j++])
				return (0);
		}
		i++;
	}
	return (l);
}

int	find_loc(char *s1, char c)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	get_num(char *str, char *base, int len_base)
{
	long long	num;
	int			minus;
	int			loc;

	minus = 1;
	num = 0;
	while (*str && is_space(*str))
		str++;
	while (*str != '\0' && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			minus *= -1;
			str++;
	}
	while (*str)
	{
		loc = find_loc(base, *str);
		if (loc >= 0)
			num = num * len_base + loc;
		else
			return ((int)minus * num);
		str++;
	}
	return ((int)minus * num);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	unsigned int	len_base_from;
	unsigned int	len_base_to;
	int				changed_nbr;

	len_base_from = base_condition(base_from);
	len_base_to = base_condition(base_to);
	if (!len_base_from || !len_base_to)
		return (0);
	changed_nbr = get_num(nbr, base_from, len_base_from);
	return (int_to_char(changed_nbr, base_to, len_base_to));
}
