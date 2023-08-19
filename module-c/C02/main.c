/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c02_test_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:32:36 by hyehan            #+#    #+#             */
/*   Updated: 2023/07/20 22:01:20 by hyehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int main()
{
	int *int_a;
	char *char_a = (char *)int_a;
	unsigned char *unchar_a = (unsigned char *)int_a;
	*int_a = 2147483401;
	printf("int_a의 주소 : [%p] \n", &int_a);
	printf("int_a이 바라보는 주소 : [%p] \n", int_a);
	printf("int_a이 바라보는 주소를 integer로 접근해서 읽는 값 : [%d] \n", *int_a);
	printf("char_a의 주소 : [%p] \n", &char_a);
	printf("char_a이 바라보는 주소 : [%p] \n", char_a);
	printf("int_a가 바라보는 주소를 char로 접근해서 읽는 값 : [%c] \n", *char_a);
	printf("int_a가 바라보는 주소를 char로 접근해서 정수로 표현한 값 : [%d] \n", *char_a);
	printf("unsigned char_a의 주소 : [%p] \n", &unchar_a);
	printf("unsigned char_a이 바라보는 주소 : [%p] \n", unchar_a);
	printf("int_a가 바라보는 주소를 unchar로 접근해서 읽는 값 : [%c] \n", *unchar_a);
	printf("int_a가 바라보는 주소를 unchar로 접근해서 정수로 표현한 값 : [%d] \n", *unchar_a);
	return 0;
}

// char로 받으면 맨 앞의 부호가 부호 비트로 인식, unsigned로 읽었을 때와 다른 값이 나옴.
// i