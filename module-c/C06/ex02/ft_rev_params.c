/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:46:43 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/07/29 21:46:44 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	get_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	main(int argc, char **argv)
{
	int	len;
	int	i;

	i = argc - 1;
	while (i > 0)
	{
		len = get_strlen(argv[i]);
		write(1, argv[i], len);
		write(1, "\n", 1);
		i--;
	}
	return (0);
}
