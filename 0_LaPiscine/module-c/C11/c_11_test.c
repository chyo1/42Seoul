#include <stdio.h>
#include "ex00/ft_foreach.c"
#include "ex01/ft_map.c"
#include "ex02/ft_any.c"
#include "ex03/ft_count_if.c"
#include "ex04/ft_is_sort.c"
#include "ex06/ft_sort_string_tab.c"
#include "ex07/ft_advanced_sort_string_tab.c"/**/

void putnbr(int x) {
	printf("%d ", x);
}

int square(int x) {
	return x * x;
}

int is_empty(char *str) {
	return *str == '\0';
}

int always_true(char *str) {
	str = 0;
	return 1;
}

int always_false(char *str) {
	str = 0;
	return 0;
}

int int_cmp(int a, int b) {
	if (a < b)
		return -1;
	else if (a > b)
		return 1;
	else
		return 0;
}

int	ft_strlen(char *str) {
	int len = 0;
	while (*str++)
		++len;
	return len;
}

int	ft_strcmp_by_len(char *s1, char *s2) {
	int len1 = ft_strlen(s1);
	int len2 = ft_strlen(s2);
	int ret;
	if (len1 < len2)
		ret = -1;
	else if (len1 > len2)
		ret = 1;
	else
		ret = 0;
	return ret;
}

int	ft_strcmp_by_len_reverse(char *s1, char *s2) {
	int len1 = ft_strlen(s1);
	int len2 = ft_strlen(s2);
	int ret;
	if (len1 > len2)
		ret = -1;
	else if (len1 < len2)
		ret = 1;
	else
		ret = 0;
	return ret;
}

int main() {
	// Exercise 00
	int arr[5] = {1, 2, 3, 4, 5};
	ft_foreach(arr, 5, putnbr);
	printf("\n");
	
	// Exercise 01
	int *res = ft_map(arr, 5, square);
	ft_foreach(res, 5, putnbr);
	printf("\n");

	// Exercise 02
	char *carr[5] = {"Hello", "", "World", "!"};
	printf("%d ", ft_any(carr, is_empty));
	printf("%d\n", ft_any(carr, always_false));

	// Exercise 03
	printf("%d ", ft_count_if(carr, 3, is_empty));
	printf("%d\n", ft_count_if(carr, 2, always_true));

	// Exercise 04
	printf("%d ", ft_is_sort(arr, 5, int_cmp));
	arr[2] = 42;
	printf("%d ", ft_is_sort(arr, 5, int_cmp));
	arr[0] = 2;
	arr[1] = 2;
	arr[2] = 2;
	arr[3] = 2;
	arr[4] = 2;
	printf("%d ", ft_is_sort(arr, 5, int_cmp));
	arr[2] = 2;
	printf("%d\n", ft_is_sort(arr, 5, int_cmp));

	// Exercise 06
	carr[0] = "Hello";
	carr[1] = "Hi";
	carr[2] = "Helloo";
	carr[3] = "He";
	ft_sort_string_tab(carr);
	for (int i = 0; i < 4; ++i)
		printf("%s ", carr[i]);
	printf("\n");
	
	// Exercise 07
	ft_advanced_sort_string_tab(carr, ft_strcmp_by_len);
	for (int i = 0; i < 4; ++i)
		printf("%s ", carr[i]);
	printf("\n");
	ft_advanced_sort_string_tab(carr, ft_strcmp_by_len_reverse);
	for (int i = 0; i < 4; ++i)
		printf("%s ", carr[i]);
	printf("\n");/**/
	return 0;
}
