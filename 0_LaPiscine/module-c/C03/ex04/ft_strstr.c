/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:43:14 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/07/25 15:13:05 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_cmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s2[i] == '\0')
			return (0);
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	s;
	int				val;

	s = 0;
	if (*to_find == '\0')
		return (str);
	while (str[s] != '\0')
	{
		val = str_cmp(&str[s], to_find);
		if (val == 0)
			return (str + s);
		s++;
	}
	return (0);
}
