/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:44:53 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/08/02 17:44:59 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);


int main()
{
	char *a;
	a = ft_convert_base("-2147483648", "0123456789", "01");
	printf("%s\n", a);
	a = ft_convert_base("-2147483648", "0123456789", "0123");
	printf("%s\n", a);
	a = ft_convert_base("-2147483648", "0123456789", "0123");
	printf("%s\n", a);
	a = ft_convert_base("-2147483648", "0123456789", "01234567");
	printf("%s\n", a);
	a = ft_convert_base("-2147483648", "0123456789", "0123456789abcdef");
	printf("%s\n", a);
	printf("\n");
	a = ft_convert_base("2147483647", "0123456789", "01");
	printf("%s\n", a);
	a = ft_convert_base("2147483647", "0123456789", "0123");
	printf("%s\n", a);
	a = ft_convert_base("2147483647", "0123456789", "0123");
	printf("%s\n", a);
	a = ft_convert_base("2147483647", "0123456789", "01234567");
	printf("%s\n", a);
	a = ft_convert_base("2147483647", "0123456789", "0123456789abcdef");
	printf("%s\n", a);
	printf("\n");
	a = ft_convert_base("\\\'\?\"\\\"\'\\", "\'\\\"?!", "0123456789");
	printf("%s\n", a);
	a = ft_convert_base("rcrdmddd", "mrdoc", "0123456789");
	printf("%s\n", a);
	a = ft_convert_base("233988", "0123456789", "gtaio:luSnemf");
	printf("%s\n", a);
}
