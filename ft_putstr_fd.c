/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:37:38 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/10/07 19:37:39 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	idx;

	idx = 0;
	if (s == NULL)
		return (NULL);
	while (s[idx])
	{
		write(fd, &s[idx], 1); // why &s no?
		idx++;
	}
}

int main()
{
	char c[] = "abc";
	ft_putstr_fd(c, 1);
}