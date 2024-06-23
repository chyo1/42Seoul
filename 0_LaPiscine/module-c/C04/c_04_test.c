#include <stdio.h>
#include <unistd.h>
#include "ex00/ft_strlen.c"
#include "ex01/ft_putstr.c"
#include "ex02/ft_putnbr.c"
#include "ex03/ft_atoi.c"

int main() {
	// 00
	char *a = "hello wordl";
	printf("%d\n", ft_strlen(a));
	// Exercise 01
	ft_putstr("");
	ft_putstr("Hello World!\n\n");

	// Exercise 02
	ft_putnbr(-2147483648);
	write(1, "\n", 1);
	ft_putnbr(2147483647);
	write(1, "\n", 1);
	ft_putnbr(0);
	write(1, "\n", 1);
	ft_putnbr(20230722);
	write(1, "\n", 1);
	ft_putnbr(-20230722);
	write(1, "\n\n", 2);

	// Exercise 00
	printf("%d ", ft_strlen(""));
	printf("%d ", ft_strlen("Hello"));
	printf("%d\n\n", ft_strlen("Hello World!"));
	
	// Exercise 03
	printf("%d\n", ft_atoi(" ---+--+1234ab567"));
	printf("%d\n", ft_atoi("\t\n\v\f\r +-+-1234z"));
	printf("%d\n", ft_atoi("\t\n\v\f\r +-+--1234z"));
	printf("%d\n", ft_atoi("\t\n\v\f\r +-+-+1234z"));
	printf("%d\n", ft_atoi("2147483647"));
	printf("%d\n", ft_atoi("-2147483648"));
	return 0;
}
