/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_val.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 20:35:14 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/08/05 20:35:15 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**get_find_arr(void);

int	str_cmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s2[i] == '\0')
			return (i);
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return (-1);
		i++;
	}
	return (i);
}

int	ft_strstr(char *str, char *to_find)
{
	unsigned int	s;
	int				val;

	s = 0;
	if (*to_find == '\0')
		return (-1);
	while (str[s] != '\0')
	{
		val = str_cmp(&str[s], to_find);
		if (val > 0)
			return (val + s);
		s++;
	}
	return (-1);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_len;

	i = 0;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (size != 0)
	{
		while (i + 1 < size && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_len);
}

int	get_key_val(char **key, char **val, char *str)
{
	int	i;
	int	idx;
	int	start;

	key = get_find_arr();
	i = 31;
	while (i >= 0)
	{
		idx = ft_strstr(str, key[i]); // 예외처리 x
		if (idx < 0) // can't find key -> dict_error
			return (-1);
		while (str[idx] == ' ')
			idx++;
		if (str[idx] != ':') // : x
			return (-1);
		else
			idx++;
		while (str[idx] == ' ')
			idx++;
		if (str[idx] == '\n' || str[idx] == '\0') // val x
			return (-1);
		start = idx;
		while (str[idx] != '\n' || str[idx] != ' ')
			idx++;
		if (str[idx] == ' ')
			return (-1); // \n x
		val[idx] = malloc(sizeof(char) * (idx - start));
		ft_strlcpy(val[i], str + start, idx - start);
		i--;
	}
}
