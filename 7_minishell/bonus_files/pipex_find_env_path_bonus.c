/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_find_env_path_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:08:07 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 16:31:21 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	make_struct_n_pipe(t_defaults *def, t_info *info)
{
	def->path = div_env_path(info->env);
	def->env_list = info->env;
	def->env = env_list_to_matrix(info->env);
	def->cnt_child = 0;
	def->infile_fd = INIT_FD;
	def->outfile_fd = INIT_FD;
}

char	**div_env_path(t_list *env)
{
	const char	cmp[5] = "PATH";
	char		**str;
	t_env		*env_element;

	while (env)
	{
		env_element = env->content;
		if (ft_strcmp(env_element->name, cmp) == 0)
			break ;
		env = env->next;
	}
	if (!env)
		return (NULL);
	str = ft_split(env_element->value, ':');
	return (str);
}

static char	*make_cmd_path(char *cmd, char *path)
{
	char	*str;
	size_t	cmd_len;
	size_t	path_len;

	cmd_len = ft_strlen(cmd);
	path_len = ft_strlen(path);
	str = (char *)ft_calloc(cmd_len + path_len + 2, sizeof(char));
	ft_strlcpy(str, path, path_len + cmd_len + 2);
	ft_strlcat(str, "/", path_len + cmd_len + 2);
	ft_strlcat(str, cmd, path_len + cmd_len + 2);
	return (str);
}

char	*find_n_make_path(char **envp, char *cmd)
{
	char	*str;
	int		i;

	if (cmd[0] == '\0')
		print_error_n_exit(COMMAND_NOT_FOUND, cmd, 0);
	if (ft_strchr(&cmd[0], '/') != 0 && access((const char *)cmd, F_OK) == 0)
		return (cmd);
	if (ft_strchr(&cmd[0], '/') != 0)
		print_error_n_exit(NO_SUCH_FILE, cmd, 0);
	if (!envp)
		print_error_n_exit(NO_SUCH_FILE, cmd, 0);
	i = -1;
	while (envp[++i] != NULL)
	{
		str = make_cmd_path(cmd, envp[i]);
		if (access((const char *)str, F_OK) == 0)
			return (str);
		free(str);
	}
	print_error_n_exit(COMMAND_NOT_FOUND, cmd, 0);
	return (NULL);
}
