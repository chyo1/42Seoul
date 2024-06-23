/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_list_change.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:48:47 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 16:30:00 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_list	*matrix_to_list(char **mat, void *(*change)(char *, int *))
{
	t_list			*env;
	t_list			*element;
	unsigned int	idx;
	char			*old_pwd;
	int				old_pwd_flag;

	old_pwd_flag = 0;
	old_pwd = "OLDPWD";
	idx = 0;
	env = 0;
	while (mat[idx])
	{
		element = ft_lstnew(change(mat[idx], &old_pwd_flag));
		ft_lstadd_back(&env, element);
		idx++;
	}
	if (old_pwd_flag == 0)
	{
		element = ft_lstnew(change(old_pwd, &old_pwd_flag));
		ft_lstadd_back(&env, element);
	}
	return (env);
}

void	*env_to_list(char *env, int *old_pwd_flag)
{
	char	**mat;
	t_env	*env_element;

	env_element = malloc(sizeof(t_env));
	if (!env_element)
		exit(1);
	mat = pipex_split(env, '=');
	env_element->name = mat[0];
	if (ft_strcmp(env_element->name, "OLDPWD") == 0)
		*old_pwd_flag = 1;
	env_element->value = mat[1];
	free(mat);
	return (env_element);
}

char	**list_to_matrix(t_list *lst)
{
	char	**matrix;
	int		size;
	int		idx;

	size = ft_lstsize(lst);
	matrix = (char **)malloc(sizeof(char *) * (size + 1));
	if (!matrix)
		exit (1);
	idx = 0;
	while (idx < size)
	{
		matrix[idx] = ft_strdup((char *)lst->content);
		idx++;
		lst = lst->next;
	}
	matrix[size] = NULL;
	return (matrix);
}

static int	cnt_env(t_list *lst)
{
	int		cnt;
	t_env	*env;

	cnt = 0;
	while (lst)
	{
		env = lst->content;
		if (env->value)
			cnt++;
		lst = lst->next;
	}
	return (cnt);
}

char	**env_list_to_matrix(t_list *lst)
{
	char	**mat;
	int		idx;

	mat = (char **)ft_calloc(cnt_env(lst) + 1, sizeof(char *));
	mat[cnt_env(lst)] = NULL;
	idx = 0;
	while (lst)
	{
		if (!((t_env *)lst->content)->value)
		{
			lst = lst->next;
			continue ;
		}
		mat[idx] = ft_calloc(ft_strlen(((t_env *)lst->content)->name) + \
		ft_strlen(((t_env *)lst->content)->value) + 2, sizeof(char));
		ft_strlcat(mat[idx], ((t_env *)lst->content)->name, \
		ft_strlen(((t_env *)lst->content)->name) + 1);
		ft_strlcat(mat[idx], "=", ft_strlen(((t_env *)lst->content)->name) + 2);
		ft_strlcat(mat[idx], ((t_env *)lst->content)->value, \
		ft_strlen(mat[idx]) + ft_strlen(((t_env *)lst->content)->value) + 2);
		idx++;
		lst = lst->next;
	}
	return (mat);
}
