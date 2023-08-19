/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_val.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 20:35:14 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/08/05 20:35:15 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**get_find_arr(void);

unsigned int	str_len(char *str)
{
	unsigned int	size;

	size = 0;
	while (str[size])
	{
		size++;
	}
	return (size);
}

int	str_cmp(char *s1, char *s2)
{
	int				i;
	unsigned char	s1val;
	unsigned char	s2val;

	i = 0;
	while (s1[i] || s2[i])
	{
		s1val = s1[i];
		s2val = s2[i];
		if (s1val != s2val)
		{
			return ((int)(s1val - s2val));
		}
		else
		{
			i++;
		}
	}
	return (0);
}

int	ft_strstr(char *str, char *to_find)
{
	unsigned int	i;
	unsigned int	findlen;
	unsigned int	len;

	len = str_len(str);
	findlen = str_len(to_find);
	i = 0;
	if (findlen == 0)
	{
		return (-1);
	}
	while (i + findlen <= len &&
		   !(*(str + findlen) == ' ' || *(str + findlen) == ':'))
	{
		if (str_cmp(str, to_find) == 0)
		{
			return (i);
		}
		str++;
		i++;
	}
	return (-1);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i + 1 < size && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
	{
		dest[i] = '\0';
	}
	return (str_len(src));
}

int	get_key_val(char **key, char **val, char *str)
{
	int	i;
	int	idx;
	int	start;

	key = get_find_arr();
	i = 0;
	while (i < 32)
	{
		if (ft_strstr(str, key[i]) >= 0)
			idx = ft_strstr(str, key[i]);
		while (str[idx] == ' ')
			idx++;
		if (str[idx] != ':') // : x
			return (-1);
		else
			idx++;
		while (str[idx] == ' ')
			idx++;
		if (str[idx] == '\n' || str[idx] == '\0') // val x
			return (-1);
		start = idx;
		while (str[idx] != '\n' || str[idx] != ' ')
			idx++;
		if (str[idx] == ' ')
			return (-1); // \n x
		val[i] = (char *)malloc(sizeof(char) * (idx - start));
		ft_strlcpy(val[i], str + start, idx - start);
		i++;
	}
	return (0);
}
