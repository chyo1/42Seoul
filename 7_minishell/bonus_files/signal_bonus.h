/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:45:11 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 12:45:12 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_BONUS_H
# define SIGNAL_BONUS_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include "minishell_type_bonus.h"

void	signal_handler(int signum);
void	child_signal_handler(void);
void	parent_signal_handler(void);
void	parent_signal_ignore(void);
#endif
