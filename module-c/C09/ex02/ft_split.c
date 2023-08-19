/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:34:26 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/07/30 16:34:27 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

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

unsigned int	get_word_cnt(char *str, char *charset)
{
	unsigned int	cnt_word;
	unsigned int	idx;

	cnt_word = 0;
	idx = 0;
	while (str[idx])
	{
		if (find_loc(charset, str[idx]) == -1)
		{
			cnt_word++;
			while (str[idx] && (find_loc(charset, str[idx]) == -1))
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

void	fill_ans(char **ans, char *str, char *charset)
{
	unsigned int	start;
	unsigned int	idx;
	unsigned int	ans_idx;

	idx = 0;
	ans_idx = 0;
	while (str[idx])
	{
		if (find_loc(charset, str[idx]) == -1)
		{
			start = idx;
			while (str[idx] && (find_loc(charset, str[idx]) == -1))
				idx++;
			ans[ans_idx] = (char *)malloc(sizeof(char) * (idx - start + 1));
			fill_word(str, ans[ans_idx], start, idx);
			ans_idx++;
		}
		else
			idx++;
	}
	ans[ans_idx] = 0;
}

char	**ft_split(char *str, char *charset)
{
	unsigned int	cnt_word;
	char			**ans;

	cnt_word = get_word_cnt(str, charset);
	ans = (char **)malloc(sizeof(char *) * (cnt_word + 1));
	fill_ans(ans, str, charset);
	return (ans);
}
