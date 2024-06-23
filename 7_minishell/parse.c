/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:49:03 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 15:51:00 by semjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_tree	*create_tree_node(t_token_type type, t_list *cmds)
{
	t_tree	*ret;

	ret = (t_tree *)ft_calloc(1, sizeof(t_tree));
	ret->type = type;
	ret->cmds = cmds;
	return (ret);
}

static int	execute_tree(t_tree *cur, t_info *info)
{
	int	ret;

	if (!cur)
		return (1);
	if (cur->type == WORD_T)
	{
		expand_list(info, cur->cmds);
		expand_heredoc_list(info, cur->cmds->content);
		return (execute_pipeline(cur->cmds, info));
	}
	ret = execute_tree(cur->left, info);
	if (cur->type == OR_T)
	{
		if (ret != 0)
			return (execute_tree(cur->right, info));
	}
	else if (cur->type == AND_T)
	{
		if (ret == 0)
			return (execute_tree(cur->right, info));
	}
	else
		return (0);
	return (ret);
}

static t_tree	*make_parsetree(t_info *info, t_list *tok)
{
	t_tree	*root;

	if (!tok)
		return (0);
	root = make_tree(&tok, 0);
	if (!root)
	{
		info->ret = 2;
		return (0);
	}
	if (open_heredoc_tree(info, root))
	{
		delete_heredoc_tree(root);
		free_tree(root);
		return (0);
	}
	return (root);
}

static t_list	*tokenize_input(t_info *info, char *in)
{
	t_list	*tokens;

	if (!info)
		info = 0;
	if (preprocess(in))
	{
		info->ret = 2;
		return (0);
	}
	tokens = tokenize(in);
	if (!tokens)
		return (0);
	return (tokens);
}

void	process_input(t_info *info, char *in)
{
	t_tree	*root;
	t_list	*tokens;
	int		ret;

	if (g_is_ctrl_c)
	{
		info->ret = 1;
		g_is_ctrl_c = 0;
	}
	ret = 1;
	root = 0;
	tokens = tokenize_input(info, in);
	root = make_parsetree(info, tokens);
	if (!root)
	{
		ft_lstclear(&tokens, free_token);
		return ;
	}
	ret = execute_tree(root, info);
	ft_lstclear(&tokens, free_token);
	delete_heredoc_tree(root);
	free_tree(root);
	return ;
}
