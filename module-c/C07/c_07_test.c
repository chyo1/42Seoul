#include <stdio.h>
#include "ex00/ft_strdup.c"
#include "ex01/ft_range.c"
#include "ex02/ft_ultimate_range.c"

int main() {
	// Exercise 00
	char *p1 = "Hello World!";
	char *p2 = ft_strdup(p1);
	if (p1 == p2)
		return 0;
	printf("%s\n", p2);
	p2 = ft_strdup("");
	printf("%s\n", p2);

	// Exercise 01
	int *p3 = ft_range(-42, 42);
	for (int i = 0; i < 84; ++i)
		printf("%d ", p3[i]);
	printf("%p ", ft_range(42, 42));
	printf("%p\n\n", ft_range(4242, 42));

	// Exercise 02
	int *p4;
	int sz = ft_ultimate_range(&p4, -42, 42);
	printf("%d ", sz);
	for (int i = 0; i < 84; ++i)
		printf("%d ", p4[i]);
	printf("%d ", ft_ultimate_range(&p4, 42, 42));
	printf("%d\n", ft_ultimate_range(&p4, 4242, 42));
	return 0;
}
