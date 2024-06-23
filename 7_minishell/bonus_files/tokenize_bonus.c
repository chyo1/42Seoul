/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:45:18 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 12:45:19 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize_bonus.h"

static t_token	*make_token(t_token_type type, char *start, int len)
{
	t_token	*t;
	int		i;

	t = (t_token *)ft_calloc(1, sizeof(t_token));
	t->type = type;
	t->word = 0;
	if (!start)
		return (t);
	t->word = (char *)ft_calloc(len + 1, sizeof(char));
	i = -1;
	while (++i < len)
		t->word[i] = start[i];
	t->word[i] = 0;
	return (t);
}

static void	add_last(t_list **lst, t_token_type type, char *start, char *line)
{
	t_token	*t;
	t_list	*new;
	int		len;

	len = line - start;
	if (line && len == 0)
		return ;
	t = make_token(type, start, len);
	new = ft_lstnew(t);
	ft_lstadd_back(lst, new);
	return ;
}

static int	get_delim_sub(char c, char next)
{
	if (c == '|')
	{
		if (next != '|')
			return (PIPE_T);
		else
			return (OR_T);
	}
	if (c == '&' && next == '&')
		return (AND_T);
	if (c == '<')
	{
		if (next != '<')
			return (INREDI_T);
		else
			return (HEREDOC_T);
	}
	if (c == '>')
	{
		if (next != '>')
			return (OUTREDI_TRUNC_T);
		else
			return (OUTREDI_APPEN_T);
	}
	return (0);
}

static int	get_delim(char *line)
{
	char	c;
	char	next;

	c = *line;
	next = *(line + 1);
	if (c == ' ' || c == '\t')
		return (-1);
	if (c == '(')
		return (OPENP_T);
	if (c == ')')
		return (CLOSEP_T);
	return (get_delim_sub(c, next));
}

t_list	*tokenize(char *line)
{
	t_list	*ret;
	char	*start;
	int		delim_idx;

	ret = 0;
	start = line;
	while (*line)
	{
		delim_idx = get_delim(line);
		if (delim_idx)
		{
			add_last(&ret, WORD_T, start, line);
			start = line + 1;
		}
		if (delim_idx > 0)
			add_last(&ret, delim_idx, 0, 0);
		line++;
		if (delim_idx < 6)
			continue ;
		line++;
		start++;
	}
	if (start != line)
		add_last(&ret, WORD_T, start, line);
	return (ret);
}
