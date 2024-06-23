/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:49:55 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 12:50:02 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_type.h"

char	*get_token_string(t_token *t)
{
	static const t_token_type	types[] = {OPENP_T, CLOSEP_T, PIPE_T, INREDI_T,
		OUTREDI_TRUNC_T, OUTREDI_APPEN_T, HEREDOC_T, OR_T, AND_T};
	static char *const			strs[] = {"(", ")", "|", "<", ">", ">>", "<<",
		"||", "&&", 0};
	int							i;

	if (t->type == WORD_T)
		return (t->word);
	i = -1;
	while (strs[++i])
	{
		if (types[i] == t->type)
			return (strs[i]);
	}
	return ("");
}

int	is_redirection_token(t_token *token)
{
	t_token_type	t;

	t = token->type;
	return (t == INREDI_T || t == OUTREDI_TRUNC_T || t == HEREDOC_T
		|| t == OUTREDI_APPEN_T);
}

int	is_command_token(t_token *token)
{
	t_token_type	t;

	t = token->type;
	return (t == WORD_T || is_redirection_token(token));
}

int	is_token_type(t_token *t, t_token_type type)
{
	return (t->type == type);
}
