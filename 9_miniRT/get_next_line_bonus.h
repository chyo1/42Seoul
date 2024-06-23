/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:10:01 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/03/17 14:17:34 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif

# define FALSE 0
# define TRUE 1

# include <stdlib.h>
# include <unistd.h>
# include "error_bonus.h"

typedef struct s_list_g
{
	char			*str;
	int				fd;
	ssize_t			len;
	ssize_t			size;
	ssize_t			loc;
	struct s_list_g	*next;
}	t_list_g;

typedef struct s_node
{
	long long		val;
	int				start;
	int				end;
	struct s_node	*pre;
	struct s_node	*next;
}	t_node;

// bonus_get_next_line.c
char		*get_next_line(int fd);
int			cpy_buff(t_list_g *node, char *buff, ssize_t cnt);
int			find_endl(t_list_g *node, ssize_t cnt);
char		*get_ans(t_list_g **root, t_list_g *node);

// bonus_get_next_line_utils.c
t_list_g	*find_or_make_lst(t_list_g **root, int fd);
int			init_node(t_list_g *node, int fd);
void		lstadd_back(t_list_g **lst, t_list_g *new_node);
char		*list_free_and_connect(t_list_g **lst, int fd, int type);

#endif
