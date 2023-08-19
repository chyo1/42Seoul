#include <stdio.h>

void ft_putchar(char c);
void rush(int x, int y);

int main(int argc, char *argv[])
{
	printf("5, 3\n");
	rush(5, 3);
	printf("5, 1\n");
	rush(5, 1);
	printf("1, 1\n");
	rush(1, 1);
	printf("1, 5\n");
	rush(1, 5);
	printf("0, 1\n");
	rush(0, 1);
	printf("1, 0\n");
	rush(1, 0);
	printf("-1, 2\n");
	rush(-1, 2);
	printf("1, -2\n");
	rush(1, -2);
	return (0) ;
}
