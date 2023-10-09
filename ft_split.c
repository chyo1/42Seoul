/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:16:20 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/10/07 17:16:21 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

unsigned int	get_word_cnt(char *str, char c)
{
	unsigned int	cnt_word;
	unsigned int	idx;

	cnt_word = 0;
	idx = 0;
	while (str[idx])
	{
		if (str[idx] != c)
		{
			cnt_word++;
			while (str[idx] && str[idx] != c)
				idx++;
		}
		else
			idx++;
	}
	return (cnt_word);
}

void	fill_word(char *src, char *ans, unsigned int start, unsigned int end)
{
	unsigned int	idx;

	idx = 0;
	while (idx < end - start)
	{
		ans[idx] = src[start + idx];
		idx++;
	}
	ans[idx] = '\0';
}

int	fill_ans(char **ans, char *str, char c)
{
	unsigned int	start;
	unsigned int	idx;
	unsigned int	ans_idx;

	idx = 0;
	ans_idx = 0;
	while (str[idx])
	{
		if (str[idx] != c)
		{
			start = idx;
			while (str[idx] && str[idx] != c)
				idx++;
			ans[ans_idx] = (char *)malloc(sizeof(char) * (idx - start + 1));
			if (ans[ans_idx] == NULL)
				return (ans_idx);
			fill_word(str, ans[ans_idx], start, idx);
			ans_idx++;
		}
		else
			idx++;
	}
	ans[ans_idx] = 0;
	return (-1);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	cnt_word;
	char			**ans;
	int				err_loc;

	cnt_word = get_word_cnt(s, c);
	ans = (char **)malloc(sizeof(char *) * (cnt_word + 1));
	if (ans == NULL)
		return (NULL);
	err_loc = fill_ans(ans, s, c);
	if (err_loc >= 0)
	{
		while (err_loc >= 0)
		{
			free(ans[err_loc]);
			err_loc--;
		}
		free(ans);
		return (NULL);
	}
	return (ans);
}
