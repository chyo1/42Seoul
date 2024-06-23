/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:42:21 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 12:42:22 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_BONUS_H
# define EXPAND_BONUS_H

# include "minishell_type_bonus.h"

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "libft.h"
# include "pipex_bonus.h"

int		expand_list(t_info *info, t_list *cmds);
t_list	*execute_wildcard(char *option);
int		push_front_dot_slash(char *option, int *i, int *dot_flag);
int		push_back_dot_slash(char *option, char *file_name, int *i, int *j);
int		check_wildcard_option(char *file_name, char *option,
			unsigned char type);
int		open_heredoc_tree(t_info *info, t_tree *t);
void	expand_heredoc_list(t_info *info, t_cmd *cmd);
void	delete_heredoc_tree(t_tree *root);

char	*expand_dollar(t_info *info, char *cmd);
void	expand_wildcard(t_list **lst);
int		expand_redis(t_info *info, t_cmd *cmd);

#endif
