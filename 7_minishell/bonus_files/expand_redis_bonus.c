/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_redis_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:42:41 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 12:42:43 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util_bonus.h"
#include "expand_bonus.h"

static int	check_redi_error(t_redi *redi, t_list *t, char *ori)
{
	if (!t || t->next)
	{
		free(redi->file);
		ft_lstclear(&t, free);
		redi->type = ERROR_T;
		redi->file = ori;
		restore_asterisk(redi->file);
		return (1);
	}
	return (0);
}

static void	expand_redi(t_info *info, t_redi *redi)
{
	char	*ori;
	t_list	*t;

	ori = ft_strdup(redi->file);
	while (contain_char(redi->file, '$'))
		redi->file = expand_dollar(info, redi->file);
	preprocess(redi->file);
	redi->file = remove_quote(redi->file);
	t = ft_split_str(redi->file, " \t");
	if (check_redi_error(redi, t, ori))
		return ;
	ft_lstiter(t, postprocess);
	if (contain_char(t->content, SUB_WILDCARD))
		expand_wildcard(&t);
	remove_cond(&t, is_null, free);
	if (check_redi_error(redi, t, ori))
		return ;
	free(redi->file);
	redi->file = t->content;
	free(t);
	free(ori);
}

int	expand_redis(t_info *info, t_cmd *cmd)
{
	t_list	*cur;

	cur = (t_list *)cmd->redi;
	while (cur)
	{
		expand_redi(info, cur->content);
		cur = cur->next;
	}
	return (0);
}
