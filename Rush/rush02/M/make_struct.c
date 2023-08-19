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

#include <unistd.h>
#include <fcntl.h>

void	get_key_val(char **key, char **val, char *str);

int	get_len(void)
{
	int		fd;
	char	buff;
	int		cnt;

	cnt = 0;
	fd = open("numbers.dict", O_RDONLY);
	if (fd < 0)
		return ;
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
	char	buff;

	len = get_len();

	str = malloc(sizeof(char) * len);

	fd = open("numbers.dict", O_RDONLY);
	if (fd < 0)
		return ;
	read(fd, buff, len);
	close(fd);
	str[len - 1] = '\0';

	if(get_key_val(key, val, str) == -1)
		return (NULL);
	return (str);
}
