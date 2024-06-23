/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:09:44 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/03/17 14:19:34 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_BONUS_H
# define ERROR_BONUS_H

# include "libft.h"
# include "minirt_types_bonus.h"
# include <stdlib.h>

void	error(t_error_type type);
void	free_arr(char **arr);

#endif
