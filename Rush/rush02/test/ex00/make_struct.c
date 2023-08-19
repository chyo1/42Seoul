/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:26:25 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/08/05 16:26:26 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	get_key_val(char **key, char **val, char *str);

int	get_len(void)
{
	int		fd;
	char	*buff;
	int		cnt;

	buff = 0;
	cnt = 0;
	fd = open("numbers.dict", O_RDONLY);
	if (fd < 0)
		return (-1);
	while (read(fd, buff, 1) > 0)
		cnt++;
	close(fd);
	return (cnt + 1);
}

char	*fill_dict(char **key, char **val)
{
	char	*str;
	int		len;
	int		fd;
	char	*buff;

	buff = 0;
	len = get_len();
	str = (char *)malloc(sizeof(char) * len);
	fd = open("numbers.dict", O_RDONLY);
	if (fd < 0)
		return (0);
	read(fd, buff, len);
	close(fd);
	str[len - 1] = '\0';

	if (get_key_val(key, val, str) == -1)
		return (NULL);
	return (str);
}
