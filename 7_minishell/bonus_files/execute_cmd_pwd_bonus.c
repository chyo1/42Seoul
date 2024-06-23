/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd_pwd_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:42:01 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 16:30:40 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	execute_cmd_pwd(t_info *info)
{
	char	*path;

	path = info->pwd;
	write(1, path, ft_strlen(path));
	write(1, "\n", 1);
	return (0);
}
