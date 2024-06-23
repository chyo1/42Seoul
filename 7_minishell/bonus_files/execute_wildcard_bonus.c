/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_wildcard_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:42:12 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 12:42:16 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "expand_bonus.h"

static void	change_wildcard_char(char *str, t_list **file_list)
{
	unsigned int	len;
	unsigned int	idx;
	t_list			*node;

	len = ft_strlen(str);
	idx = 0;
	while (idx < len)
	{
		if (str[idx] == SUB_WILDCARD)
			str[idx] = '*';
		idx++;
	}
	node = ft_lstnew(ft_strdup(str));
	ft_lstadd_back(file_list, node);
}

static char	*save_file_name(char *option, char *file_name)
{
	int		i;
	int		len;
	int		cnt[2];
	char	*ret_str;
	int		dot_flag;

	i = 0;
	cnt[0] = 0;
	cnt[1] = 0;
	dot_flag = FALSE;
	if (ft_strncmp(option, "./", 2) == 0)
		cnt[0] = push_front_dot_slash(option, &i, &dot_flag);
	if (option[ft_strlen(option) - 1 - cnt[1]] == '/')
		cnt[1] = 1;
	ret_str = ft_calloc(ft_strlen(file_name) + cnt[0] + cnt[1] + 1, 1);
	i = -1;
	while (++i < cnt[0])
		ret_str[i] = option[i];
	len = ft_strlcat(ret_str, file_name, ft_strlen(file_name) + cnt[0] + 1);
	i = -1;
	ret_str[ft_strlen(ret_str)] = '/';
	ret_str[ft_strlen(file_name) + cnt[0] + cnt[1]] = '\0';
	return (ret_str);
}

t_list	*execute_wildcard(char *option)
{
	DIR				*dir_info;
	struct dirent	*dd;
	t_list			*file_list;
	char			*file_to_list;

	file_list = NULL;
	dir_info = opendir(".");
	if (!dir_info)
		exit (1);
	dd = readdir(dir_info);
	while (dd != NULL)
	{
		if (check_wildcard_option(dd->d_name, option, dd->d_type) == TRUE)
		{
			file_to_list = save_file_name(option, dd->d_name);
			ft_lstadd_back(&file_list, ft_lstnew(file_to_list));
		}
		dd = readdir(dir_info);
	}
	closedir(dir_info);
	if (file_list == NULL)
		change_wildcard_char(option, &file_list);
	else
		bubble_sort(file_list, do_strcmp);
	return (file_list);
}
