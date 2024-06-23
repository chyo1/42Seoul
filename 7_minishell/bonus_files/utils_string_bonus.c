/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_string_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:46:04 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 12:46:05 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_type_bonus.h"
#include "util_bonus.h"

char	*substitute_str_dollar(char *str)
{
	char	*ori;

	if (!str)
		return (0);
	ori = str;
	while (*str)
	{
		if (*str == '$')
			*str = SUB_DOLLAR;
		str++;
	}
	return (ori);
}

int	contain_char(const char *str, char c)
{
	while (str && *str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	is_valid_name_char(char c, int is_first)
{
	return (ft_isalpha(c) || c == '_' || (!is_first && ft_isdigit(c)));
}

int	get_vname_len(char *cmd)
{
	int	i;

	i = 0;
	while (cmd && is_valid_name_char(cmd[i], !i))
		i++;
	return (i);
}

char	*find_var(t_list *env, char *cmp)
{
	t_env	*env_element;
	size_t	cmp_len;

	cmp_len = ft_strlen(cmp);
	while (env)
	{
		env_element = env->content;
		if (ft_strncmp(env_element->name, cmp,
				max(ft_strlen(env_element->name), cmp_len)) == 0)
			return (env_element->value);
		env = env->next;
	}
	return (0);
}
