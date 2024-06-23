/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd_export.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:48:02 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 12:50:13 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_list	*env_list_cpy(t_list *env)
{
	t_list	*export_list;
	t_env	*name_value;
	t_env	*new_t_env_node;
	t_list	*new_node;

	export_list = NULL;
	while (env)
	{
		name_value = env->content;
		new_t_env_node = (t_env *)ft_calloc(1, sizeof(t_env));
		new_t_env_node->name = ft_strdup(name_value->name);
		if (name_value->value)
			new_t_env_node->value = ft_strdup(name_value->value);
		else
			new_t_env_node->value = NULL;
		new_node = ft_lstnew(new_t_env_node);
		ft_lstadd_front(&export_list, new_node);
		env = env->next;
	}
	return (export_list);
}

static void	free_export_list(t_list *export_list)
{
	t_list	*free_list;
	t_env	*env_list;

	while (export_list)
	{
		free_list = export_list;
		export_list = (export_list)->next;
		env_list = free_list->content;
		free(env_list->name);
		free(env_list->value);
		free(env_list);
		free(free_list);
	}
}

int	execute_cmd_export(t_list *args, t_info *info)
{
	t_list	*export_list;
	t_list	*free_list;
	t_env	*export_element;

	if (args && args->next)
		return (add_to_export(args->next, &(info->env)));
	export_list = env_list_cpy(info->env);
	bubble_sort(export_list, ft_cmp);
	free_list = export_list;
	while (export_list)
	{
		write (1, "declare -x ", 11);
		export_element = (t_env *)export_list->content;
		write (1, export_element->name, ft_strlen(export_element->name));
		if (export_element->value)
		{
			write (1, "=\"", 2);
			write (1, export_element->value, ft_strlen(export_element->value));
			write(1, "\"", 1);
		}
		write(1, "\n", 1);
		export_list = export_list->next;
	}
	free_export_list(free_list);
	return (0);
}
