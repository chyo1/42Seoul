/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:44:59 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 12:45:00 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_type_bonus.h"
#include "util_bonus.h"

static void	process_quote_out(char *line, int *flag)
{
	if (*line == '\'')
		*flag = SQUOTE_IN;
	else if (*line == '\"')
		*flag = DQUOTE_IN;
	else if (*line == '*')
		*line = SUB_WILDCARD;
}

char	substitute_char(char c)
{
	static const char	*word = " \t()<>|&$";
	static const char	flags[] = {SUB_SPACE, SUB_TAB, SUB_OPENP, SUB_CLOSEP,
		SUB_LT, SUB_GT, SUB_OR, SUB_AND, SUB_DOLLAR, 0};
	size_t				i;

	i = 0;
	while (word[i])
	{
		if (word[i] == c)
			return (flags[i]);
		i++;
	}
	return (c);
}

static void	process_squote_in(char *line, int *flag)
{
	if (*line == '\'')
		*flag = QUOTE_OUT;
	else if (*line == '$')
		*line = SUB_DOLLAR;
	else if (*line == '\"')
		*line = SUB_DQUOTE;
}

static void	process_dquote_in(char *line, int *flag)
{
	if (*line == '\"')
		*flag = QUOTE_OUT;
	else if (*line == '\'')
		*line = SUB_SQUOTE;
}

int	preprocess(char *line)
{
	static const char	*word = " \t()<>|&";
	int					flag;

	if (!line)
		return (0);
	flag = QUOTE_OUT;
	while (*line)
	{
		if (flag == QUOTE_OUT)
			process_quote_out(line, &flag);
		else if (contain_char(word, *line))
			*line = substitute_char(*line);
		else if (flag == SQUOTE_IN)
			process_squote_in(line, &flag);
		else if (flag == DQUOTE_IN)
			process_dquote_in(line, &flag);
		++line;
	}
	if (flag != QUOTE_OUT)
	{
		print_eof_syntax_error(0, 0);
		return (1);
	}
	return (0);
}
