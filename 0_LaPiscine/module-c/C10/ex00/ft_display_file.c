/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:40:38 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/08/07 13:40:39 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	char		buff[1024];
	int			fd;
	ssize_t		len;

	if (argc == 1)
	{
		write(1, "File name missing\n", 18);
		return (0);
	}
	else if (argc != 2)
	{
		write(1, "Too many arguments.\n", 20);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);

	while (1)
	{
		len = read(fd, buff, 1024);
		if (len = -1)
		{
			write(1, "Cannot read file\n", 18);
			return (0);
		}
		write(1, buff, len);
	}
	close(fd);
}
