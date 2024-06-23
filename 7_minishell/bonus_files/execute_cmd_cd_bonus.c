/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd_cd_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:14:50 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 12:14:51 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

t_env	*find_name_in_env(t_list *env, char *which)
{
	if (!env)
		return (NULL);
	while (env && ft_strcmp(((t_env *)(env->content))->name, which) != 0)
		env = env->next;
	if (env)
		return (env->content);
	return (NULL);
}

static void	update_error_pwd(t_info	*info, char *cd_cmds)
{
	char	*path;
	t_env	*oldpwd_loc;
	t_env	*pwd_loc;
	t_list	*env;

	env = info->env;
	oldpwd_loc = find_name_in_env(env, "OLDPWD");
	pwd_loc = find_name_in_env(env, "PWD");
	if (ft_strcmp(cd_cmds, ".") == 0)
		path = ft_strjoin(pwd_loc->value, "/.");
	else if (strcmp(cd_cmds, "..") == 0)
		path = ft_strjoin(pwd_loc->value, "/..");
	if (pwd_loc)
	{
		if (oldpwd_loc)
		{
			free(oldpwd_loc->value);
			oldpwd_loc->value = pwd_loc->value;
		}
		else
			free(pwd_loc->value);
		pwd_loc->value = path;
	}
	free(info->pwd);
	info->pwd = ft_strdup(path);
}

static int	print_error(t_info *info, char *path)
{
	t_list	*env;

	env = info->env;
	if (path && (ft_strcmp(path, ".") == 0 || ft_strcmp(path, "..") == 0))
	{
		write(2, "minishell: cd: ", 15);
		write(2, "error retrieving current directory:", 35);
		write(2, "getcwd: cannot access parent directories: ", 43);
		write(2, "No such file or directory\n", 26);
		update_error_pwd(info, path);
		return (1);
	}
	write(2, "minishell: cd: ", 15);
	write(2, path, ft_strlen(path));
	write(2, ": No such file or directory\n", 28);
	return (1);
}

static void	update_normal_pwd(t_info *info)
{
	char	path[PATH_MAX];
	t_list	*env;
	t_env	*oldpwd_loc;
	t_env	*pwd_loc;

	env = info->env;
	getcwd(path, PATH_MAX);
	oldpwd_loc = find_name_in_env(env, "OLDPWD");
	pwd_loc = find_name_in_env(env, "PWD");
	if (pwd_loc)
	{
		if (oldpwd_loc)
		{
			free(oldpwd_loc->value);
			oldpwd_loc->value = pwd_loc->value;
		}
		else
			free(pwd_loc->value);
		pwd_loc->value = ft_strdup(path);
	}
	free(info->pwd);
	info->pwd = ft_strdup(path);
}

int	execute_cmd_cd(t_list *cmd_info, t_info *env_list)
{
	char	*path;
	t_list	*env;
	char	chk_loc[PATH_MAX];

	env = env_list->env;
	path = NULL;
	if (cmd_info)
		path = cmd_info->content;
	if (path == NULL || ft_strcmp(path, "~") == 0)
	{
		while (ft_strcmp(((t_env *)env->content)->name, "HOME") \
		|| !getcwd(chk_loc, PATH_MAX))
			env = env->next;
		if (env && chdir(((t_env *)env->content)->value) == -1)
			return (print_error(env_list, ((t_env *)env->content)->name));
	}
	else
	{
		if (chdir(path) == -1 || !getcwd(chk_loc, PATH_MAX))
			return (print_error(env_list, path));
	}
	update_normal_pwd(env_list);
	return (0);
}
