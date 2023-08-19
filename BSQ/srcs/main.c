/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:15:57 by younghoc          #+#    #+#             */
/*   Updated: 2023/08/09 19:28:49 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#include <input.h>
#include <find_square.h>
#include <print.h>

int	solution(int fd)
{
	t_map	map;

	if (parse_map(fd, &map))
		return (1);
	make_map(&map);
	if (map.w == 1)
		find_max_size_at_vertical(map);
	else if (map.h == 1)
		find_max_size_at_horizon(map);
	else
	{
		find_max_size_at_vertical(map);
		find_max_size_at_horizon(map);
		find_max_size(map);
	}
	print_map(map);
	free_map(map);
	return (0);
}

void	main_stdin(void)
{
	int	fd;

	fd = 0;
	if (solution(fd))
	{
		ft_puterr("map error\n");
	}
}

void	main_argv(int argc, char *argv[])
{
	int	i;
	int	fd;

	i = 0;
	while (++i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
		{
			ft_puterr("map error\n");
			continue ;
		}
		if (solution(fd))
			ft_puterr("map error\n");
		if (close(fd) == -1)
			ft_puterr("map error\n");
		if (i != argc - 1)
			ft_putstr("\n");
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		main_stdin();
		return (0);
	}
	main_argv(argc, argv);
	return (0);
}
