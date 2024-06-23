/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd_unset.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:48:10 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 13:29:48 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_env_element(t_env *env_element, t_list *now_env_list)
{
	free(env_element->name);
	free(env_element->value);
	free(env_element);
	free(now_env_list);
}

static void	find_n_del_node(t_list **env_list, char *unset_str)
{
	t_env	*env_element;
	t_list	*pre_env_list;
	t_list	*now_env_list;

	pre_env_list = *env_list;
	now_env_list = *env_list;
	while (now_env_list)
	{
		env_element = now_env_list->content;
		if (ft_strcmp(env_element->name, unset_str) == 0)
		{
			if (pre_env_list == now_env_list)
			{
				if (now_env_list->next == NULL)
					*env_list = NULL;
				else
					*env_list = now_env_list->next;
			}
			else
				pre_env_list->next = now_env_list->next;
			return (free_env_element(env_element, now_env_list));
		}
		pre_env_list = now_env_list;
		now_env_list = (now_env_list)->next;
	}
}

static int	check_invalid_unset(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (is_valid_name_char(str[idx], !idx) == FALSE)
			return (1);
		idx++;
	}
	return (0);
}

int	execute_cmd_unset(t_list **env_list, t_list *args)
{
	int		return_value;

	return_value = 0;
	while (args)
	{
		if (check_invalid_unset(args->content))
		{
			write(2, "minishell: ", 11);
			write(2, "unset: `", 8);
			write(2, args->content, ft_strlen(args->content));
			write(2, "': not a valid identifier\n", 26);
			return_value = 1;
		}
		find_n_del_node(env_list, args->content);
		args = args->next;
	}
	return (return_value);
}
