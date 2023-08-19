#include <stdio.h>
#include "ex03/ft_strjoin.c"

int main() {
	// Exercise 03
	char *arr[9] = {"The", "Quick", "Brown", "Fox", "Jumps", "Over", "The", "Lazy", "Dog"};
	printf("%s\n", ft_strjoin(9, arr, ""));
	printf("%s\n", ft_strjoin(9, arr, " "));
	printf("%s\n", ft_strjoin(9, arr, "*"));
	printf("%s\n", ft_strjoin(9, arr, "!@#$%^&*()"));
	printf("%s\n", ft_strjoin(9, arr, "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz"));
	printf("%s\n", ft_strjoin(5, arr, " "));
	printf("%s", ft_strjoin(0, arr, " "));
	return 0;
}
