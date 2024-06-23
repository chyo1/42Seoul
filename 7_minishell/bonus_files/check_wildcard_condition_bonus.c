/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wildcard_condition_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:39:01 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 16:29:42 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	push_front_dot_slash(char *option, int *i, int *dot_flag)
{
	int	cnt;

	cnt = 2;
	*i = 2;
	while (option[*i] && (option[*i] == '/' || option[*i] == '.'))
	{
		if (option[*i] == '.' && option[(*i) + 1] != '/')
			break ;
		if (option[*i] == '.' && *dot_flag == TRUE)
			return (FALSE);
		if (option[*i] == '.')
			*dot_flag = TRUE;
		else if (option[*i] == '/')
			*dot_flag = FALSE;
		(*i)++;
		cnt++;
	}
	return (cnt);
}

int	push_back_dot_slash(char *option, char *file_name, int *i, int *j)
{
	while (file_name[*j] || option[*i])
	{
		if (option[*i] == SUB_WILDCARD)
		{
			while (option[*i] && option[*i + 1] == SUB_WILDCARD)
				(*i)++;
			while (file_name[*j] && file_name[*j] != option[*i + 1])
				(*j)++;
			(*i)++;
		}
		else if (option[*i] == file_name[*j] && ++(*i) && ++(*j))
			;
		else if (option[*i] == '/')
		{
			while (option[*i] && option[*i] == '/')
				(*i)++;
			if (option[*i] == '\0')
				return (CHECK_FILE_FLAG);
		}
		else
			return (FALSE);
	}
	return (TRUE);
}

int	check_wildcard_back(char *file_name, char *option, int *i, int *j)
{
	int		file_len;
	int		opt_len;
	int		ret_val;
	char	*new_option;

	file_len = ft_strlen(file_name) - 1;
	opt_len = ft_strlen(option) - 1;
	if (option[opt_len] != SUB_WILDCARD && option[opt_len] != '/')
	{
		while (option[opt_len] == file_name[file_len])
		{
			opt_len--;
			file_len--;
		}
		if (option[opt_len] != SUB_WILDCARD)
			return (FALSE);
	}
	new_option = ft_calloc(opt_len + 2, sizeof(char));
	ft_strlcpy(new_option, option, opt_len + 2);
	ret_val = push_back_dot_slash(new_option, file_name, i, j);
	free(new_option);
	return (ret_val);
}

int	check_wildcard_option(char *file_name, char *option, unsigned char type)
{
	int		i;
	int		j;
	int		dot_flag;
	int		ret_type;

	i = 0;
	j = 0;
	dot_flag = FALSE;
	if (option[0] != '.' && file_name[0] == '.')
		return (FALSE);
	if (ft_strncmp(option, "./", 2) == 0)
	{
		push_front_dot_slash(option, &i, &dot_flag);
		if (option[i] != '.' && file_name[j] == '.')
			return (FALSE);
	}
	ret_type = check_wildcard_back(file_name, option, &i, &j);
	if (ret_type == FALSE || (ret_type == CHECK_FILE_FLAG && type != TYPE_DIR))
		return (FALSE);
	if (file_name[j])
		return (FALSE);
	return (TRUE);
}
