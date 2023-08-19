#include <stdio.h>
#include "ex05/ft_atoi_base.c"

int main() {
	// Exercise 05
	printf("%d\n", ft_atoi_base("-2147483648", "0123456789"));
	printf("%d\n", ft_atoi_base("2147483647", "0123456789"));
	printf("%d\n", ft_atoi_base("0", "0123456789"));
	printf("%d\n", ft_atoi_base("20230722", "0123456789"));
	printf("%d\n\n", ft_atoi_base("-20230722", "0123456789"));

	printf("%d\n", ft_atoi_base("-10000000000000000000000000000000", "01"));
	printf("%d\n", ft_atoi_base("1111111111111111111111111111111", "01"));
	printf("%d\n", ft_atoi_base("0", "01"));
	printf("%d\n", ft_atoi_base("1001101001011001001000010", "01"));
	printf("%d\n\n", ft_atoi_base("-1001101001011001001000010", "01"));

	printf("%d\n", ft_atoi_base("-80000000", "0123456789ABCDEF"));
	printf("%d\n", ft_atoi_base("7FFFFFFF", "0123456789ABCDEF"));
	printf("%d\n", ft_atoi_base("0", "0123456789ABCDEF"));
	printf("%d\n", ft_atoi_base("134B242", "0123456789ABCDEF"));
	printf("%d\n\n", ft_atoi_base("-134B242", "0123456789ABCDEF"));

	printf("%d\n", ft_atoi_base("-npppppppppp", "poneyvif"));
	printf("%d\n", ft_atoi_base("offffffffff", "poneyvif"));
	printf("%d\n", ft_atoi_base("p", "poneyvif"));
	printf("%d\n", ft_atoi_base("oovoeoopn", "poneyvif"));
	printf("%d\n\n", ft_atoi_base("-oovoeoopn", "poneyvif"));

	printf("%d\n", ft_atoi_base("$**$$*$**$*$$**$**$****$*", "*$"));
	printf("%d\n", ft_atoi_base(" ---+--+1234ab567", "0123456789"));
	printf("%d\n", ft_atoi_base("\t\n\v\f\r +-+-1234z", "0123456789"));
	printf("%d\n", ft_atoi_base("\t\n\v\f\r +-+--1234z", "0123456789"));
	printf("%d\n\n", ft_atoi_base("\t\n\v\f\r +-+-+1234z", "0123456789"));

	printf("%d ", ft_atoi_base("", ""));
	printf("%d ", ft_atoi_base("*", ""));
	printf("%d ", ft_atoi_base("*$*", "*$*"));
	printf("%d ", ft_atoi_base("+$*", "$*+"));
	printf("%d ", ft_atoi_base("-$*", "$*-"));
	printf("%d ", ft_atoi_base(" $*", "$* "));
	printf("%d ", ft_atoi_base("\t$*", "$*\t"));
	printf("%d ", ft_atoi_base("\n$*", "$*\n"));
	printf("%d ", ft_atoi_base("\v$*", "$*\v"));
	printf("%d ", ft_atoi_base("\f$*", "$*\f"));
	printf("%d\n", ft_atoi_base("\r$*", "$*\r"));
	return 0;
}
