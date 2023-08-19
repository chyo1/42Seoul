/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:48:35 by younghoc          #+#    #+#             */
/*   Updated: 2023/08/09 19:29:24 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <vector.h>
#include <ft_realloc.h>

t_vector	*new_vector(void)
{
	t_vector	*vector;

	vector = malloc(sizeof(t_vector));
	if (vector == NULL)
		return (NULL);
	vector->arr = malloc(INITIAL_BUFFER_SIZE);
	vector->cap = INITIAL_BUFFER_SIZE;
	vector->len = 0;
	return (vector);
}

int	vector_push(t_vector *vector, char c)
{
	if (vector->cap == vector->len)
	{
		vector->arr = ft_realloc_(vector->arr, vector->cap, vector->cap * 2);
		if (vector->arr == NULL)
			return (1);
		vector->cap *= 2;
	}
	vector->arr[vector->len++] = c;
	return (0);
}

void	free_vector(t_vector *vector)
{
	free(vector->arr);
	free(vector);
}
