#include <unistd.h>
#include "ex04/ft_putnbr_base.c"
#include <stdio.h>
int main() {
	// Exercise 04
	ft_putnbr_base(-2147483648, "0123456789");
	write(1, "\n", 1);
	ft_putnbr_base(2147483647, "0123456789");
	write(1, "\n", 1);
	ft_putnbr_base(0, "0123456789");
	write(1, "\n", 1);
	ft_putnbr_base(20230722, "0123456789");
	write(1, "\n", 1);
	ft_putnbr_base(-20230722, "0123456789");
	write(1, "\n\n", 2);

	ft_putnbr_base(-2147483648, "01");
	write(1, "\n", 1);
	ft_putnbr_base(2147483647, "01");
	write(1, "\n", 1);
	ft_putnbr_base(0, "01");
	write(1, "\n", 1);
	ft_putnbr_base(20230722, "01");
	write(1, "\n", 1);
	ft_putnbr_base(-20230722, "01");
	write(1, "\n\n", 2);

	ft_putnbr_base(-2147483648, "0123456789ABCDEF");
	write(1, "\n", 1);
	ft_putnbr_base(2147483647, "0123456789ABCDEF");
	write(1, "\n", 1);
	ft_putnbr_base(0, "0123456789ABCDEF");
	write(1, "\n", 1);
	ft_putnbr_base(20230722, "0123456789ABCDEF");
	write(1, "\n", 1);
	ft_putnbr_base(-20230722, "0123456789ABCDEF");
	write(1, "\n\n", 2);

	ft_putnbr_base(-2147483648, "poneyvif");
	write(1, "\n", 1);
	ft_putnbr_base(2147483647, "poneyvif");
	write(1, "\n", 1);
	ft_putnbr_base(0, "poneyvif");
	write(1, "\n", 1);
	ft_putnbr_base(20230722, "poneyvif");
	write(1, "\n", 1);
	ft_putnbr_base(-20230722, "poneyvif");
	write(1, "\n\n", 2);

	ft_putnbr_base(20230722, "");
	ft_putnbr_base(20230722, "*");
	ft_putnbr_base(20230722, "*$*");
	ft_putnbr_base(20230722, "*$+");
	ft_putnbr_base(20230722, "*$-");
	ft_putnbr_base(20230722, "*$");
	write(1, "\n", 1);
	return 0;
}
