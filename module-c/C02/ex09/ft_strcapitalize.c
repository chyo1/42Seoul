/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:43:14 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/07/22 13:43:18 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	is_alpha(char c)
{
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
		return (1);
	return (0);
}

char	*ft_strlow(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ('A' <= str[i] && str[i] <= 'Z')
			str[i] = str[i] - 'A' + 'a';
		i++;
	}
	return (str);
}

int	is_digit(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	fir;
	int	i;

	ft_strlow(str);
	fir = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (is_alpha(str[i]) == 0 && is_digit(str[i]) == 0)
			fir = 1;
		else
		{
			if (fir == 1 && is_alpha(str[i]))
					str[i] = str[i] - 'a' + 'A';
			fir = 0;
		}
		i++;
	}
	return (str);
}
