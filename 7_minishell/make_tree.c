/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:48:45 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 12:50:39 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include "parse.h"

void	*make_condition_node(t_tree **parent, t_token *t, t_list **cur)
{
	t_tree	*new;
	t_tree	*p;

	p = *parent;
	if (p && (p->type == WORD_T || p->right) && (*cur)->next)
	{
		new = create_tree_node(t->type, 0);
		new->left = p;
		*cur = (*cur)->next;
		*parent = new;
		return (new);
	}
	if (p && !(*cur)->next)
		return (print_eof_syntax_error(p, free_tree));
	return (print_parse_syntax_error(*cur, p, free_tree));
}

void	*make_command_node(t_tree **parent, t_list **cur)
{
	t_tree	*new;
	t_tree	*p;

	p = *parent;
	if (p && (p->type == WORD_T || p->right))
		return (print_parse_syntax_error(*cur, p, free_tree));
	new = create_pipeline(cur);
	if (!new)
		return (free_tree(p));
	if (p)
		p->right = new;
	else
		*parent = new;
	return (new);
}

void	*make_p_node(t_tree **parent, t_list **cur)
{
	t_tree	*new;
	t_tree	*p;

	p = *parent;
	if (p && (p->type != WORD_T && p->right))
		return (print_parse_syntax_error(*cur, p, free_tree));
	if (!(*cur)->next)
		return (print_eof_syntax_error(p, free_tree));
	*cur = (*cur)->next;
	new = make_tree(cur, 1);
	if (!new)
		return (free_tree(p));
	if (!*cur || (new->type != WORD_T && !new->right))
	{
		free_tree(new);
		return (print_parse_syntax_error(*cur, p, free_tree));
	}
	if (p)
		p->right = new;
	else
		*parent = new;
	*cur = (*cur)->next;
	return (new);
}

int	make_tree_sub(t_token *t, t_tree **p, t_list **cur)
{
	if (t->type == OR_T || t->type == AND_T)
	{
		if (!make_condition_node(p, t, cur))
			return (1);
	}
	else if (t->type == OPENP_T)
	{
		if (!make_p_node(p, cur))
			return (1);
	}
	else if (t->type == WORD_T || is_redirection_token(t))
	{
		if (!make_command_node(p, cur))
			return (1);
	}
	return (0);
}

t_tree	*make_tree(t_list **cur, int is_p)
{
	t_tree	*p;
	t_token	*t;

	p = 0;
	while (*cur)
	{
		t = (t_token *)((*cur)->content);
		if (t->type == OR_T || t->type == AND_T || t->type == OPENP_T
			|| t->type == WORD_T || is_redirection_token(t))
		{
			if (make_tree_sub(t, &p, cur))
				return (0);
		}
		else if (t->type == CLOSEP_T)
		{
			if (is_p && p)
				break ;
			else
				return (print_parse_syntax_error(*cur, p, free_tree));
		}
		else
			return (print_parse_syntax_error(*cur, p, free_tree));
	}
	return (p);
}
