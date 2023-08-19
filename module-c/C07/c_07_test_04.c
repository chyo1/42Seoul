#include <stdio.h>
#include "ex04/ft_convert_base.c"
#include "ex04/ft_convert_base2.c"

int main() {
	// Exercise 04
	printf("%s\n", ft_convert_base("-2147483648", "0123456789", "01"));
	printf("%s\n", ft_convert_base("2147483647", "0123456789", "01"));
	printf("%s\n", ft_convert_base("0", "0123456789", "01"));
	printf("%s\n", ft_convert_base("20230722", "0123456789", "01"));
	printf("%s\n\n", ft_convert_base("-20230722", "0123456789", "01"));

	printf("%s\n", ft_convert_base("-10000000000000000000000000000000", "01", "0123456789"));
	printf("%s\n", ft_convert_base("1111111111111111111111111111111", "01", "0123456789"));
	printf("%s\n", ft_convert_base("0", "01", "0123456789"));
	printf("%s\n", ft_convert_base("1001101001011001001000010", "01", "0123456789"));
	printf("%s\n\n", ft_convert_base("-1001101001011001001000010", "01", "0123456789"));

	printf("%s\n", ft_convert_base("-80000000", "0123456789ABCDEF", "poneyvif"));
	printf("%s\n", ft_convert_base("7FFFFFFF", "0123456789ABCDEF", "poneyvif"));
	printf("%s\n", ft_convert_base("0", "0123456789ABCDEF", "poneyvif"));
	printf("%s\n", ft_convert_base("134B242", "0123456789ABCDEF", "poneyvif"));
	printf("%s\n\n", ft_convert_base("-134B242", "0123456789ABCDEF", "poneyvif"));

	printf("%s\n", ft_convert_base("-npppppppppp", "poneyvif", "0123456789ABCDEF"));
	printf("%s\n", ft_convert_base("offffffffff", "poneyvif", "0123456789ABCDEF"));
	printf("%s\n", ft_convert_base("p", "poneyvif", "0123456789ABCDEF"));
	printf("%s\n", ft_convert_base("oovoeoopn", "poneyvif", "0123456789ABCDEF"));
	printf("%s\n\n", ft_convert_base("-oovoeoopn", "poneyvif", "0123456789ABCDEF"));

	printf("%s\n", ft_convert_base("$**$$*$**$*$$**$**$****$*", "*$", "@^"));
	printf("%s\n", ft_convert_base(" ---+--+1234ab567", "0123456789", "qwertyuiop"));
	printf("%s\n", ft_convert_base("\t\n\v\f\r +-+-1234z", "0123456789", "qwertyuiop"));
	printf("%s\n", ft_convert_base("\t\n\v\f\r +-+--1234z", "0123456789", "qwertyuiop"));
	printf("%s\n\n", ft_convert_base("\t\n\v\f\r +-+-+1234z", "0123456789", "qwertyuiop"));

	printf("%p ", ft_convert_base("", "", "0123456789"));
	printf("%p ", ft_convert_base("*", "", "0123456789"));
	printf("%p ", ft_convert_base("*", "*", "0123456789"));
	printf("%p ", ft_convert_base("*$*", "*$*", "0123456789"));
	printf("%p ", ft_convert_base("+$*", "$*+", "0123456789"));
	printf("%p ", ft_convert_base("-$*", "$*-", "0123456789"));
	printf("%p ", ft_convert_base(" $*", "$* ", "0123456789"));
	printf("%p ", ft_convert_base("\t$*", "$*\t", "0123456789"));
	printf("%p ", ft_convert_base("\n$*", "$*\n", "0123456789"));
	printf("%p ", ft_convert_base("\v$*", "$*\v", "0123456789"));
	printf("%p ", ft_convert_base("\f$*", "$*\f", "0123456789"));
	printf("%p\n", ft_convert_base("\r$*", "$*\r", "0123456789"));

	printf("%p ", ft_convert_base("", "$*", ""));
	printf("%p ", ft_convert_base("*", "$*", ""));
	printf("%p ", ft_convert_base("*", "$*", "0"));
	printf("%p ", ft_convert_base("*$*", "$*", "010"));
	printf("%p ", ft_convert_base("+$*", "$*", "01+"));
	printf("%p ", ft_convert_base("-$*", "$*", "01-"));
	printf("%p ", ft_convert_base(" $*", "$*", "01 "));
	printf("%p ", ft_convert_base("\t$*", "$*", "01\t"));
	printf("%p ", ft_convert_base("\n$*", "$*", "01\n"));
	printf("%p ", ft_convert_base("\v$*", "$*", "01\v"));
	printf("%p ", ft_convert_base("\f$*", "$*", "01\f"));
	printf("%p\n", ft_convert_base("\r$*", "$*", "01\r"));
	return 0;
}
