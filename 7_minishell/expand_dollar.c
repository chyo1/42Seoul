/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:48:24 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 12:50:27 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_type.h"
#include "util.h"

static void	find_env_value_sub(t_info *info, t_var *var, char *cmd)
{
	var->n = ft_substr(cmd, var->start + 1, var->len);
	var->v = find_var(info->env, var->n);
	if (var->v && ft_strlen(var->v) != 0)
		var->v = ft_strdup(var->v);
	free(var->n);
}

static int	find_env_value(t_info *info, t_var *var, char *cmd)
{
	while (cmd[var->start])
	{
		if (cmd[var->start] == '$')
		{
			var->len = get_vname_len(cmd + var->start + 1);
			if (var->len == 0)
			{
				if (cmd[var->start + 1] != '?')
				{
					cmd[var->start] = SUB_DOLLAR;
					var->v = cmd;
					return (1);
				}
				var->v = ft_itoa(info->ret);
				var->len = 1;
			}
			else
				find_env_value_sub(info, var, cmd);
			break ;
		}
		var->start++;
	}
	if (var->v && ft_strlen(var->v) == 0)
		var->v = 0;
	return (0);
}

static char	*join_three(char *h, char *m, char *t)
{
	char	*tmp;

	tmp = ft_strjoin(h, m);
	free(h);
	h = ft_strjoin(tmp, t);
	free(tmp);
	free(t);
	free(m);
	return (h);
}

static char	*free_two_str(char *a, char *b)
{
	if (a)
		free(a);
	if (b)
		free(b);
	return (0);
}

char	*expand_dollar(t_info *info, char *cmd)
{
	t_var	var;
	char	*head;
	char	*tail;
	char	*tmp;

	var.start = 0;
	var.v = 0;
	var.len = 0;
	if (find_env_value(info, &var, cmd))
		return (var.v);
	substitute_str_dollar(var.v);
	head = ft_substr(cmd, 0, var.start);
	tail = ft_substr(cmd, var.start + var.len + 1, ft_strlen(cmd));
	free(cmd);
	if (var.v)
		return (join_three(head, var.v, tail));
	else if (ft_strlen(head) != 0 || ft_strlen(tail) != 0)
	{
		tmp = ft_strjoin(head, tail);
		free_two_str(head, tail);
		return (tmp);
	}
	else
		return (free_two_str(head, tail));
}
