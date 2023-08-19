/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c05_test_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 03:00:50 by hyehan            #+#    #+#             */
/*   Updated: 2023/07/26 05:19:38 by hyehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex00/ft_iterative_factorial.c"
#include "ex01/ft_recursive_factorial.c"
#include "ex02/ft_iterative_power.c"
#include "ex03/ft_recursive_power.c"
#include "ex04/ft_fibonacci.c"
#include "ex05/ft_sqrt.c"
#include "ex06/ft_is_prime.c"
#include "ex07/ft_find_next_prime.c"
#include "ex08/ft_ten_queens_puzzle.c"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	printf("-ex00_test_case-\n\n");
	printf("input : 5\n");
	printf("--answer : 120 | your result: %d\n\n", ft_iterative_factorial(5));
	printf("input : 10\n");
	printf("--answer : 3628800 | your result : %d", ft_iterative_factorial(10));
	printf("\n\n------------------------------\n\n");

	printf("-ex01_test_case-\n\n");
	printf("input : 5\n");
	printf("--answer : 120 | your result: %d\n\n", ft_recursive_factorial(5));
	printf("input : 10\n");
	printf("--answer : 3628800 | your result : %d", ft_recursive_factorial(10));
	printf("\n\n------------------------------\n\n");

	printf("-ex02_test_case-\n\n");
	printf("input nb : 5 | power : 4\n\n");
	printf("--answer : 625 | your result : %d\n\n", ft_iterative_power(5, 4));
	printf("input nb : 3 | power : 7\n\n");
	printf("--answer : 2187 | your result : %d\n\n", ft_iterative_power(3, 7));
	printf("\n\n------------------------------\n\n");

	printf("-ex03_test_case-\n\n");
	printf("input nb : 5 | power : 4\n\n");
	printf("--answer : 625 | your result : %d\n\n", ft_iterative_power(5, 4));
	printf("input nb : 3 | power : 7\n\n");
	printf("--answer : 2187 | your result : %d\n\n", ft_iterative_power(3, 7));
	printf("input nb : 0 | power : 0\n\n");
	printf("--answer : 1 | your result : %d\n\n", ft_iterative_power(0, 0));
	printf("\n\n------------------------------\n\n");

	printf("-ex04_test_case-\n\n");
	printf("input : 5\n\n");
	printf("--answer : 5 | your result : %d\n\n", ft_fibonacci(5));
	printf("input : 13\n\n");
	printf("--answer : 233 | your result : %d\n\n", ft_fibonacci(13));
	printf("\n\n------------------------------\n\n");

	printf("-ex05_test_case-\n\n");
	printf("input : 36\n\n");
	printf("--answer : 6 | your result : %d\n\n", ft_sqrt(36));
	printf("input : 1\n\n");
	printf("--answer : 1 | your result :%d\n\n", ft_sqrt(1));
	printf("\n\n------------------------------\n\n"); 

	printf("-ex06_test_case-\n\n");
	printf("input : 36\n\n");
	printf("--answer : 0 | your result : %d\n\n", ft_is_prime(36));
	printf("input : 11\n\n");
	printf("--answer : 1 | your result :%d\n\n", ft_is_prime(11));
	printf("input : 97\n\n");
	printf("--answer : 1 | your result :%d\n\n", ft_is_prime(2147483647));
	printf("\n\n------------------------------\n\n");

	printf("-ex07_test_case-\n\n");
	printf("input : 36\n\n");
	printf("--answer : 37 | your result : %d\n\n", ft_find_next_prime(36));
	printf("input : 11\n\n");
	printf("--answer : 11 | your result :%d\n\n", ft_find_next_prime(11));
	printf("input : 54\n\n");
	printf("--answer : 59 | your result :%d\n\n", ft_find_next_prime(54));
	printf("\n\n------------------------------\n\n");

	printf("-ex08_test_case-\n\n");
	int	n = ft_ten_queens_puzzle();
	printf("\n\nanswer : 724 \n\nyour total solutions : %d\n\n", n);
	printf("\n\n------------------------------\n\n");	return 0;

}
