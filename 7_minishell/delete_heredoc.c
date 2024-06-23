/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:47:41 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 12:47:42 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_type.h"

static void	unlink_heredoc_list(t_list *cmds)
{
	t_cmd	*cmd;
	t_list	*lst;
	t_redi	*redi;

	while (cmds)
	{
		cmd = cmds->content;
		lst = cmd->redi;
		while (lst)
		{
			redi = lst->content;
			if (redi->type == HEREDOC_EX_T || redi->type == HEREDOC_NOEX_T)
				unlink(redi->file);
			lst = lst->next;
		}
		cmds = cmds->next;
	}
}

void	delete_heredoc_tree(t_tree *t)
{
	if (!t)
		return ;
	if (t->type == WORD_T)
	{
		unlink_heredoc_list(t->cmds);
		return ;
	}
	if (t->left)
		delete_heredoc_tree(t->left);
	if (t->right)
		delete_heredoc_tree(t->right);
}
