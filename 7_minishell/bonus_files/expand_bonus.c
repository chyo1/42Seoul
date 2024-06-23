/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:42:18 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 12:42:19 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand_bonus.h"

static t_list	*expand_cmd(t_info *info, t_list *cmd)
{
	t_list	*t;

	while (contain_char(cmd->content, '$'))
		cmd->content = expand_dollar(info, cmd->content);
	preprocess(cmd->content);
	cmd->content = remove_quote(cmd->content);
	t = ft_split_str(cmd->content, " \t");
	ft_lstiter(t, postprocess);
	expand_wildcard(&t);
	return (t);
}

static void	expand_cmds_sub(t_cmd *cmd, t_list *tmp, t_list **cur,
		t_list **prev)
{
	if (*prev)
		(*prev)->next = tmp;
	else
		cmd->args = tmp;
	*prev = ft_lstlast(tmp);
	tmp = *cur;
	(*prev)->next = (*cur)->next;
	*cur = (*cur)->next;
	tmp->next = 0;
	ft_lstclear(&tmp, free);
}

static int	expand_cmds(t_info *info, t_cmd *cmd)
{
	t_list	*cur;
	t_list	*prev;
	t_list	*tmp;

	if (!info)
		return (0);
	cur = (t_list *)cmd->args;
	prev = 0;
	while (cur)
	{
		tmp = expand_cmd(info, cur);
		if (!tmp)
		{
			prev = cur;
			cur = cur->next;
			continue ;
		}
		expand_cmds_sub(cmd, tmp, &cur, &prev);
	}
	remove_cond(&cmd->args, is_null, free);
	return (0);
}

int	expand_list(t_info *info, t_list *cmds)
{
	while (cmds)
	{
		if (expand_cmds(info, cmds->content)
			|| expand_redis(info, cmds->content))
			return (1);
		cmds = cmds->next;
	}
	return (0);
}
