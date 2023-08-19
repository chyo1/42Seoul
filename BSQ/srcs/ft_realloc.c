/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:00:41 by younghoc          #+#    #+#             */
/*   Updated: 2023/08/09 19:28:05 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <ft_realloc.h>

void	ft_memcpy(void *dest, void *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
}

void	*ft_realloc_(void *old_ptr, int old_size, int new_size)
{
	void	*new_ptr;

	if (old_size >= new_size)
		return (old_ptr);
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);
	ft_memcpy(new_ptr, old_ptr, old_size);
	free(old_ptr);
	return (new_ptr);
}
