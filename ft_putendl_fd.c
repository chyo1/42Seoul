/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:40:55 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/10/07 19:40:56 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	unsigned int	idx;

	idx = 0;
	while (s[idx])
	{
		write(fd, &s[idx], 1); // why &s no?
		idx++;
	}
	write(fd, "\n", 1);
}

int	main()
{
	char c[] = "abc";
	ft_putendl_fd(c, 1);
}