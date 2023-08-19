/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:07:09 by younghoc          #+#    #+#             */
/*   Updated: 2023/08/08 18:22:34 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# define INITIAL_BUFFER_SIZE 32

typedef struct s_vector
{
	char			*arr;
	unsigned int	cap;
	unsigned int	len;
}t_vector;

t_vector	*new_vector(void);
int			vector_push(t_vector *vector, char c);
void		free_vector(t_vector *vector);

#endif
