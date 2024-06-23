/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:43:39 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 12:43:40 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_BONUS_H
# define PARSE_BONUS_H

# include "tokenize_bonus.h"
# include "pipex_bonus.h"
# include "minishell_type_bonus.h"
# include "expand_bonus.h"

void	process_input(t_info *info, char *in);
t_tree	*create_pipeline(t_list **cur);
t_tree	*make_tree(t_list **cur, int is_p);

#endif
