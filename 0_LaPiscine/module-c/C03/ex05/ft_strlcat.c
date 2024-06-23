/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:36:31 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/07/24 10:36:44 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	d;
	unsigned int	s;
	unsigned int	len_d;
	unsigned int	len_s;

	s = 0;
	len_d = 0;
	len_s = 0;
	while (dest[len_d] != '\0')
		len_d++;
	while (src[len_s] != '\0')
		len_s++;
	d = len_d;
	if (size < len_d)
		return (len_s + size);
	if (size > 0)
	{
		while (d < size - 1 && src[s] != '\0')
			dest[d++] = src[s++];
		dest[d] = '\0';
	}
	return (len_d + len_s);
}
