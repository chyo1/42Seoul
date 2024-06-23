/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:49:46 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 12:51:08 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_type.h"
#include "util.h"
#include "signal.h"
#include <readline/readline.h>

int	exit_heredoc(t_info *info, int status)
{
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == 1)
		{
			info->ret = 1;
			return (1);
		}
		info->prompt_indent++;
		return (0);
	}
	return (0);
}

int	write_heredoc(t_info *info, int fd, char *eof)
{
	char	*in;

	in = readline(HEREDOC_PROMPT);
	while (in && ft_strcmp(eof, in))
	{
		info->prompt_indent = 0;
		if (write(fd, in, ft_strlen(in)) == -1 || write(fd, "\n", 1) == -1)
			exit(1);
		free(in);
		in = readline(HEREDOC_PROMPT);
	}
	if (!in)
	{
		printf("\033[1B\033[1A\033[%dC", info->prompt_indent * 2 + 2);
		return (1);
	}
	free(in);
	close(fd);
	return (0);
}

char	*make_word(t_list *lst)
{
	size_t	len;
	char	*ret;
	size_t	i;

	len = ft_lstsize(lst);
	ret = ft_calloc(len + 1, sizeof(char));
	i = 0;
	while (lst)
	{
		ret[i++] = ((t_cnode *)lst->content)->c;
		lst = lst->next;
	}
	return (ret);
}

void	write_list(t_list *env, int out_fd, t_list *wlist)
{
	char	*word;
	char	*value;

	word = make_word(wlist);
	value = find_var(env, word);
	if (value)
		write(out_fd, value, ft_strlen(value));
	free(word);
}

t_cnode	*make_new_cnode(char c)
{
	t_cnode	*node;

	node = (t_cnode *)ft_calloc(1, sizeof(t_cnode));
	node->c = c;
	return (node);
}
