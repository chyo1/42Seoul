/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_heredoc_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:43:33 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 12:43:34 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_type_bonus.h"
#include "util_bonus.h"
#include "signal_bonus.h"
#include "pipex_bonus.h"

void	heredoc_signal_handler(int signum)
{
	signum++;
	rl_replace_line("", 0);
	printf("\n");
	rl_on_new_line();
	rl_redisplay();
	exit(1);
}

static void	heredoc_child(t_info *info, t_redi *redi, char *name)
{
	ssize_t	fd;

	rl_catch_signals = 1;
	signal(SIGINT, heredoc_signal_handler);
	fd = open(name, O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
		exit(1);
	write_heredoc(info, fd, redi->file);
	exit(0);
}

static int	open_heredoc(t_info *info, t_redi *redi, char *name)
{
	pid_t	pid;
	int		status;

	if (contain_char(redi->file, '\'') || contain_char(redi->file, '\"'))
	{
		redi->type = HEREDOC_NOEX_T;
		redi->file = remove_quote(redi->file);
	}
	postprocess(redi->file);
	restore_asterisk(redi->file);
	parent_signal_ignore();
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
		heredoc_child(info, redi, name);
	waitpid(pid, &status, 0);
	parent_signal_handler();
	free(redi->file);
	redi->file = name;
	if (redi->type == HEREDOC_T)
		redi->type = HEREDOC_EX_T;
	return (exit_heredoc(info, status));
}

static int	open_heredoc_list(t_info *info, t_list *cmds)
{
	t_cmd	*cmd;
	t_list	*lst;
	t_redi	*redi;
	char	*name;

	while (cmds)
	{
		cmd = cmds->content;
		lst = cmd->redi;
		while (lst)
		{
			redi = lst->content;
			if (redi->type == HEREDOC_T)
			{
				name = make_file_name(HEREDOC_NAME);
				if (open_heredoc(info, redi, name))
					return (1);
			}
			lst = lst->next;
		}
		cmds = cmds->next;
	}
	return (0);
}

int	open_heredoc_tree(t_info *info, t_tree *t)
{
	if (!t)
		return (1);
	if (t->type == WORD_T)
		return (open_heredoc_list(info, t->cmds));
	if (t->left && open_heredoc_tree(info, t->left))
		return (1);
	if (t->right && open_heredoc_tree(info, t->right))
		return (1);
	return (0);
}
