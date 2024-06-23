/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:45:28 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 12:45:29 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_BONUS_H
# define UTIL_BONUS_H

# include "libft.h"
# include "minishell_type_bonus.h"

int		preprocess(char *line);
void	postprocess(void *p);
void	restore_asterisk(char *str);

int		is_valid_name_char(char c, int is_first);
int		contain_char(const char *str, char c);
int		get_vname_len(char *cmd);
char	*find_var(t_list *env, char *cmp);
size_t	max(size_t a, size_t b);
char	*remove_quote(char *str);
t_list	*ft_split_str(char *str, char *charset);
int		is_null(void *p);
void	remove_cond(t_list **lst, int (*to_delete)(void *),
			void (*del)(void *));

char	*substitute_str_dollar(char *str);
char	substitute_char(char c);

t_cnode	*make_new_cnode(char c);
void	write_list(t_list *env, int out_fd, t_list *wlist);
char	*make_word(t_list *lst);
int		write_heredoc(t_info *info, int fd, char *eof);
int		exit_heredoc(t_info *info, int status);

void	*print_eof_syntax_error(void *data, void *(*free_func)(void *));
void	*print_parse_syntax_error(t_list *cur, void *data,
			void *(*free_func)(void *));

void	*free_cmd(void *content);
void	*free_cmds(void *content);
void	free_token(void *c);
void	free_tokens(t_list *tokens);
void	*free_tree(void *content);
void	free_redi(void *c);

char	*get_token_string(t_token *t);
int		is_redirection_token(t_token *token);
int		is_command_token(t_token *token);
int		is_token_type(t_token *t, t_token_type type);

t_tree	*create_tree_node(t_token_type type, t_list *cmds);

#endif
