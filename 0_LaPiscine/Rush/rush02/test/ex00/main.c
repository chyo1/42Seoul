/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 20:34:12 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/08/06 12:09:14 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	str_len(char *str);
void			default_dict(char **key, char **val);
char			*fill_dict(char **key, char **val);
int 			find_val(char **key, char *find);

int	main(int argc, char **argv)
{
	char	**dict_key;
	char	**dict_val;
	char	*dic;

	dict_key = 0;
	dict_val = 0;
	if (argc == 2)
	{
		default_dict(dict_key, dict_val);
		write(1, dict_val[find_val(dict_key, argv[1])], str_len(dict_val[find_val(dict_key, argv[1])]));
	}
	else if (argc == 3)
	{
		dic = fill_dict(dict_key, dict_val);
	}
	else
		return (0);
}
