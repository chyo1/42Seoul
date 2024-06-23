/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:49:05 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 12:50:51 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "tokenize.h"
# include "pipex.h"
# include "minishell_type.h"
# include "expand.h"

void	process_input(t_info *info, char *in);
t_tree	*create_pipeline(t_list **cur);
t_tree	*make_tree(t_list **cur, int is_p);

#endif
