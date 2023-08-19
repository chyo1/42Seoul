/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:08:35 by younghoc          #+#    #+#             */
/*   Updated: 2023/08/08 18:20:53 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_REALLOC_H
# define FT_REALLOC_H

void	ft_memcpy(void *dest, void *src, int size);
void	*ft_realloc_(void *old_ptr, int old_size, int new_size);

#endif
