/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:49:07 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 16:30:34 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/stat.h> 
# include "minishell_type.h"
# include "util.h"
# include "signal.h"

# define CHECK_FILE_FLAG 3

// pipex_main.c
int		execute_pipeline(t_list	*cmds, t_info *info);

// make_file_name.c
char	*make_file_name(char *name);

// ft_split.c
char	**pipex_split(char const *s, char c);

// find_env_path.c
void	make_struct_n_pipe(t_defaults *def, t_info *info);
char	**div_env_path(t_list *env);
char	*find_n_make_path(char **envp, char *cmd);

// close_pipes_n_fd_fin_program.c
int		print_error_n_exit(int which, char *file_name, pid_t pid);

// do_child.c
int		do_child(t_defaults *def, t_list *cmds, t_info *info);
void	read_n_write_pipes(t_defaults *def, t_list *cmd_list);

// pipex_redirection.c
int		check_redirection(t_defaults *def, t_cmd *cmds, pid_t pid);
void	check_redirect_n_dup_fd(t_defaults *def, \
		t_cmd *cmds, t_list *cmd_list, pid_t pid);

// matrix_list_change.c
t_list	*matrix_to_list(char **mat, void *(*change)(char *, int *));
void	*env_to_list(char *env, int *old_pwd_flag);
char	**list_to_matrix(t_list *lst);
char	**env_list_to_matrix(t_list *lst);

// do_builtin_func.c
int		check_builtin_func(t_cmd *cmds);
int		do_builtin_func(t_defaults *def, t_cmd *cmds, t_info *info, pid_t pid);

// execute_cmd_cd.c
int		execute_cmd_cd(t_list *info, t_info *env_list);
t_env	*find_name_in_env(t_list *env, char *which);

// execute_cmd_echo.c
int		execute_cmd_echo(t_list *cmds);

// execute_cmd_env.c
int		execute_cmd_env(t_list *env);

// execute_cmd_export.c
int		execute_cmd_export(t_list *args, t_info *env);

// execute_cmd_export_add.c
int		add_to_export(t_list *args, t_list **env);

// sorting.c
void	bubble_sort(t_list *lst, int (*f)(void *, void *));
int		ft_cmp(void *now, void *next);
int		do_strcmp(void *s1, void *s2);

// execute_cmd_pwd.c
int		execute_cmd_pwd(t_info *info);

// execute_cmd_exit.c
int		execute_cmd_exit(t_list *args, pid_t is_child);

// execute_cmd_unset.c
int		execute_cmd_unset(t_list **env_list, t_list *args);

#endif
