/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_parse_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:49:27 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/02/05 12:50:57 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	*print_parse_syntax_error(t_list *cur, void *data,
	void *(*free_func)(void *))
{
	char	*tok_str;

	if (cur)
		tok_str = get_token_string(cur->content);
	else
		tok_str = "newline";
	ft_putstr_fd(NAME, 2);
	ft_putstr_fd("syntax error near unexpected token `", 2);
	ft_putstr_fd(tok_str, 2);
	ft_putendl_fd("'", 2);
	if (free_func)
		free_func(data);
	return (0);
}

void	*print_eof_syntax_error(void *data, void *(*free_func)(void *))
{
	ft_putstr_fd(NAME, 2);
	ft_putendl_fd("syntax error: unexpected end of file", 2);
	if (free_func)
		free_func(data);
	return (0);
}
