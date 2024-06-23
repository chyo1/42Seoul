/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd_pwd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:48:07 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 16:29:53 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	execute_cmd_pwd(t_info *info)
{
	char	*path;

	path = info->pwd;
	write(1, path, ft_strlen(path));
	write(1, "\n", 1);
	return (0);
}
