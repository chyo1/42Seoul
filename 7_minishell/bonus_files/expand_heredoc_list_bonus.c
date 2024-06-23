/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_heredoc_list_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:42:35 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 12:42:38 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_type_bonus.h"
#include "util_bonus.h"
#include "pipex_bonus.h"

static void	do_dollar_end(t_h_arg *args, int out_fd)
{
	if (args->c == '$')
	{
		args->flag = DOLLAR_START;
		args->is_first = 1;
	}
	else
		write(out_fd, &args->c, 1);
}

static int	do_dollar_start(t_info *info, t_h_arg *args, t_list **lst)
{
	if (is_valid_name_char(args->c, args->is_first))
	{
		args->is_first = 0;
		ft_lstadd_back(lst, ft_lstnew(make_new_cnode(args->c)));
	}
	else
	{
		if (args->c == '?' && args->is_first)
		{
			ft_putnbr_fd(info->ret, args->out_fd);
			args->size = read(args->in_fd, &args->c, 1);
		}
		else if (args->is_first)
			write(args->out_fd, "$", 1);
		else
			write_list(info->env, args->out_fd, *lst);
		args->flag = DOLLAR_END;
		ft_lstclear(lst, free);
		return (1);
	}
	return (0);
}

static void	expand_env_heredoc(t_info *info, ssize_t in_fd, ssize_t out_fd)
{
	t_h_arg	args;
	t_list	*lst;

	lst = 0;
	args.flag = DOLLAR_END;
	args.size = read(in_fd, &args.c, 1);
	args.in_fd = in_fd;
	args.out_fd = out_fd;
	while (args.size > 0)
	{
		if (args.flag == DOLLAR_END)
			do_dollar_end(&args, out_fd);
		else if (do_dollar_start(info, &args, &lst))
			continue ;
		args.size = read(in_fd, &args.c, 1);
	}
	if (args.size == -1)
		exit(1);
}

static void	expand_heredoc(t_info *info, t_redi *redi, char *name)
{
	int		in_fd;
	int		out_fd;

	in_fd = open(redi->file, O_RDONLY);
	out_fd = open(name, O_WRONLY | O_CREAT, 0644);
	if (in_fd == -1 || out_fd == -1)
		exit(1);
	expand_env_heredoc(info, in_fd, out_fd);
	close(in_fd);
	close(out_fd);
	unlink(redi->file);
	free(redi->file);
	redi->file = name;
}

void	expand_heredoc_list(t_info *info, t_cmd *cmd)
{
	t_list	*lst;
	t_redi	*redi;
	char	*name;

	lst = cmd->redi;
	while (lst)
	{
		redi = lst->content;
		if (redi->type == HEREDOC_EX_T)
		{
			name = make_file_name(HEREDOC_NAME);
			expand_heredoc(info, redi, name);
			redi->type = HEREDOC_NOEX_T;
		}
		lst = lst->next;
	}
}
