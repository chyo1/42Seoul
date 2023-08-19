/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:34:06 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/07/30 16:34:07 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	get_strs_len(int size, char **strs)
{
	int	cnt;
	int	len;
	int	i;

	cnt = 0;
	len = 0;
	while (cnt < size)
	{
		i = 0;
		while (strs[cnt][i])
		{
			len++;
			i++;
		}
		cnt++;
	}
	return (len);
}

int	get_sep_len(char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
		i++;
	return (i);
}

void	put(char *copy, char *src, int *idx)
{
	while (*src)
	{
		*(copy + *idx) = *src;
		(*idx)++;
		src++;
	}
}

char	*put_word(int size, char *copy, char **strs, char *sep)
{
	int		idx;
	int		i;
	char	*ret;

	ret = copy;
	idx = 0;
	i = 0;
	while (idx < size)
	{
		put(copy, strs[idx], &i);
		if (idx != size - 1)
			put(copy, sep, &i);
		idx++;
	}
	copy[i] = '\0';
	return (ret);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len_strs;
	int		len_sep;
	char	*ans;

	if (size == 0)
	{
		ans = (char *)malloc((sizeof(char) * 1));
		ans[0] = '\0';
		return (ans);
	}
	len_strs = get_strs_len(size, strs);
	len_sep = get_sep_len(sep);
	ans = (char *)malloc(sizeof(char) * (len_strs + (size - 1) * len_sep + 1));
	if (ans == NULL)
		return (NULL);
	return (put_word(size, ans, strs, sep));
}
