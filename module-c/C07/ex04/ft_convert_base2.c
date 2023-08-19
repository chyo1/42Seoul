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
#include <stdlib.h>

int	atoi_and_get_len(int nbr, char *save, char *base, unsigned int div)
{
	int			idx;
	long long	num;

	idx = 0;
	num = (long long)nbr;
	if (num < 0)
	{
		save[idx++] = '-';
		num = -num;
	}
	else if (num == 0)
	{
		save[idx++] = base[0];
		save[idx++] = '\0';
		return (idx);
	}
	while (num > 0)
	{
		save[idx++] = base[num % div];
		num /= div;
	}
	save[idx++] = '\0';
	return (idx);
}

void	copy(char *src, char *str, unsigned int len)
{
	unsigned int	i;

	i = 0;
	if (src[0] == '-')
	{
		str[i++] = src[0];
		while (i < len - 1)
		{
			str[i] = src[len - 1 - i];
			i++;
		}
	}
	else
	{
		while (i < len - 1)
		{
			str[i] = src[len - (i + 2)];
			i++;
		}
	}
	str[len - 1] = '\0';
}

char	*int_to_char(int num, char *base_to, unsigned int len_base_to)
{
	char			change[34];
	unsigned int	len;
	char			*ans;

	len = atoi_and_get_len(num, change, base_to, len_base_to);
	ans = (char *)malloc(sizeof(char) * len);
	if (ans == NULL)
		return (NULL);
	copy(change, ans, len);
	return (ans);
}
