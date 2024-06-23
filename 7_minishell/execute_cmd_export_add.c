/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd_export_add.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:48:04 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 12:50:15 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "util.h"

static int	find_equal_sign_location(char *content)
{
	unsigned int	idx;

	idx = 0;
	while (content[idx])
	{
		if (idx != 0 && content[idx] == '=')
			break ;
		if (is_valid_name_char(content[idx], !idx) == FALSE)
		{
			write(2, "minishell: ", 11);
			write(2, "export: `", 8);
			write(2, content, ft_strlen(content));
			write(2, "': not a valid identifier\n", 26);
			return (-1);
		}
		idx++;
	}
	return (idx);
}

char	*make_new_name_or_value(char *content, int idx, char which)
{
	char	*new_name;
	char	*new_value;

	if (content[idx] == '\0')
	{
		if (which == 'n')
			new_name = ft_strdup(content);
		else if (which == 'v')
			new_value = NULL;
	}
	else
	{
		if (which == 'n')
		{
			new_name = (char *)ft_calloc(idx, sizeof(char));
			ft_strlcpy(new_name, content, idx + 1);
		}
		else if (which == 'v')
			new_value = ft_strdup(&content[idx + 1]);
	}
	if (which == 'n')
		return (new_name);
	return (new_value);
}

int	find_n_replace_node(t_list *export_list, char *new_name, char *new_value)
{
	t_env	*env_node;

	while (export_list)
	{
		env_node = export_list->content;
		if (ft_strcmp(env_node->name, new_name) == 0)
		{
			free(new_name);
			if (new_value)
			{
				free(env_node->value);
				env_node->value = new_value;
			}
			return (TRUE);
		}
		export_list = export_list->next;
	}
	return (FALSE);
}

static void	add_new_node_to_list(t_list *args, t_list **env, int idx)
{
	char	*new_name;
	char	*new_value;
	t_env	*new_t_env_node;
	t_list	*new_node;

	new_name = make_new_name_or_value(args->content, idx, 'n');
	new_value = make_new_name_or_value(args->content, idx, 'v');
	if (find_n_replace_node(*env, new_name, new_value) == FALSE)
	{
		new_t_env_node = (t_env *)ft_calloc(1, sizeof(t_env));
		new_t_env_node->name = new_name;
		new_t_env_node->value = new_value;
		new_node = ft_lstnew(new_t_env_node);
		ft_lstadd_back(env, new_node);
	}
}

int	add_to_export(t_list *args, t_list **env)
{
	int		idx;
	int		return_value;

	return_value = 0;
	while (args)
	{
		idx = find_equal_sign_location(args->content);
		if (idx == -1)
			return_value = 1;
		else
			add_new_node_to_list(args, env, idx);
		args = args->next;
	}
	return (return_value);
}
