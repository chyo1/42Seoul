/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:43:18 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/02 12:31:40 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	pipex_get_word_cnt(const char *str, char c)
{
	unsigned int	idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] == c)
			return (2);
		idx++;
	}
	return (1);
}

char	**pipex_split(char const *s, char c)
{
	char	**ans;
	int		idx;

	ans = (char **)malloc(sizeof(char *) * (3));
	if (ans == NULL)
		print_error_n_exit(MALLOC_ERROR, NULL, 1);
	if (pipex_get_word_cnt(s, c) == 1)
	{
		ans[0] = ft_strdup(s);
		ans[1] = NULL;
	}
	else
	{
		idx = 0;
		while (s[idx] && s[idx] != c)
			idx++;
		ans[0] = ft_calloc(idx + 1, sizeof(char));
		idx = -1;
		while (s[++idx] != c)
			ans[0][idx] = s[idx];
		ans[0][idx] = '\0';
		ans[1] = ft_strdup(&s[idx + 1]);
	}
	ans[2] = 0;
	return (ans);
}
