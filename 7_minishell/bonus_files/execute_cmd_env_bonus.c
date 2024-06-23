/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd_env_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:41:24 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 12:46:24 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"
#include "libft.h"

int	execute_cmd_env(t_list *env)
{
	t_env	*env_element;

	while (env)
	{
		env_element = (t_env *)env->content;
		if (env_element->value)
		{
			write (1, env_element->name, ft_strlen(env_element->name));
			write (1, "=", 1);
			write (1, env_element->value, ft_strlen(env_element->value));
			write (1, "\n", 1);
		}
		env = env->next;
	}
	return (0);
}
