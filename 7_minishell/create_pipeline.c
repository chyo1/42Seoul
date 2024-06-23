/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipeline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:47:38 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 12:47:39 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

static t_redi	*create_redi(t_list **cur, t_token_type type)
{
	t_redi	*ret;
	t_token	*t;

	*cur = (*cur)->next;
	if (!*cur)
		return (print_parse_syntax_error(*cur, 0, 0));
	t = (t_token *)(*cur)->content;
	if (t->type != WORD_T)
		return (print_parse_syntax_error(*cur, 0, 0));
	ret = (t_redi *)ft_calloc(1, sizeof(t_redi));
	ret->type = type;
	ret->file = ft_strdup(t->word);
	return (ret);
}

static t_cmd	*create_cmd(t_list **cur)
{
	t_token	*t;
	t_cmd	*c;
	t_redi	*redi;

	c = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
	while (*cur)
	{
		t = (t_token *)((*cur)->content);
		if (t->type == WORD_T)
			ft_lstadd_back(&c->args, ft_lstnew(ft_strdup(t->word)));
		else if (is_redirection_token(t))
		{
			redi = create_redi(cur, t->type);
			if (!redi)
				return (free_cmd(c));
			ft_lstadd_back(&c->redi, ft_lstnew(redi));
		}
		else
			break ;
		*cur = (*cur)->next;
	}
	return (c);
}

static int	add_cmd(t_list **cur, t_list **cmds)
{
	t_cmd	*cmd;

	cmd = create_cmd(cur);
	if (!cmd)
	{
		free_cmds(*cmds);
		return (1);
	}
	ft_lstadd_back(cmds, ft_lstnew(cmd));
	return (0);
}

static int	create_pipeline_sub(t_token *t, t_list **cur, t_list **cmds)
{
	if (is_command_token(t))
	{
		if (add_cmd(cur, cmds))
			return (1);
	}
	else if (t->type == PIPE_T)
	{
		*cur = (*cur)->next;
		if (!(*cur) || !is_command_token((*cur)->content))
		{
			print_parse_syntax_error(*cur, *cmds, free_cmds);
			return (1);
		}
	}
	return (0);
}

t_tree	*create_pipeline(t_list **cur)
{
	t_token	*t;
	t_list	*cmds;
	t_tree	*ret;

	cmds = 0;
	while (*cur)
	{
		t = (t_token *)((*cur)->content);
		if (is_command_token(t) || t->type == PIPE_T)
		{
			if (create_pipeline_sub(t, cur, &cmds))
				return (0);
		}
		else if (t->type == OR_T || t->type == AND_T || t->type == CLOSEP_T)
			break ;
		else
			return (print_parse_syntax_error(*cur, cmds, free_cmds));
	}
	ret = create_tree_node(WORD_T, cmds);
	return (ret);
}
