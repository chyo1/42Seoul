/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_val.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 12:09:51 by jeongbel          #+#    #+#             */
/*   Updated: 2023/08/06 13:57:32 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_cmp(char *s1, char *s2);

int	find_val(char **key, char *find)
{
	int		i;

	i = 0;
	while (i < 32)
	{
		if (str_cmp(key[i], find) == 0)
			return (i);
		i++;
	}
	return (-1);
}
