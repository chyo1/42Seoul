/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:49:41 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 12:51:04 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	*free_cmd(void *content)
{
	t_cmd	*cmd;

	cmd = content;
	if (!cmd)
		return (0);
	ft_lstclear(&cmd->args, free);
	ft_lstclear(&cmd->redi, free_redi);
	free(cmd);
	return (0);
}

void	*free_cmds(void *content)
{
	t_list	*cmds;
	t_list	*next;

	cmds = content;
	while (cmds)
	{
		next = cmds->next;
		free_cmd((t_cmd *)cmds->content);
		free(cmds);
		cmds = next;
	}
	return (0);
}

void	free_token(void *c)
{
	t_token	*t;

	if (!c)
		return ;
	t = (t_token *)c;
	free(t->word);
	free(t);
}

void	free_tokens(t_list *tokens)
{
	t_token	*t;
	t_list	*next;

	while (tokens)
	{
		next = tokens->next;
		t = (t_token *)tokens->content;
		free(t->word);
		free(t);
		free(tokens);
		tokens = next;
	}
}

void	*free_tree(void *content)
{
	t_tree	*t;

	t = content;
	if (!t)
		return (0);
	if (t->left)
	{
		free_tree(t->left);
		t->left = 0;
	}
	if (t->right)
	{
		free_tree(t->right);
		t->right = 0;
	}
	free_cmds(t->cmds);
	free(t);
	return (0);
}
