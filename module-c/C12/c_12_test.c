#include <stdio.h>
#include "ex00/ft_create_elem.c"
#include "ex01/ft_list_push_front.c"
#include "ex02/ft_list_size.c"
/*#include "ex03/ft_list_last.c"
#include "ex04/ft_list_push_back.c"
#include "ex05/ft_list_push_strs.c"
#include "ex06/ft_list_clear.c"
#include "ex07/ft_list_at.c"
#include "ex08/ft_list_reverse.c"
#include "ex09/ft_list_foreach.c"
#include "ex10/ft_list_foreach_if.c"
#include "ex11/ft_list_find.c"
#include "ex12/ft_list_remove_if.c"
#include "ex13/ft_list_merge.c"
#include "ex14/ft_list_sort.c"
#include "ex15/ft_list_reverse_fun.c"
#include "ex16/ft_sorted_list_insert.c"
#include "ex17/ft_sorted_list_merge.c"*/

void putstr(void *ptr) {
	printf("%s ", ptr);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned char	c1;
	unsigned char	c2;
	int				ret;
	while (*s1 && *s2 && *s1 == *s2) {
		++s1;
		++s2;
	}
	c1 = *s1;
	c2 = *s2;
	if (c1 < c2)
		ret = -1;
	else if (c1 > c2)
		ret = 1;
	else
		ret = 0;
	return (ret);
}

int main() {
	printf("Exercise 00~07, 09\n");
	// Exercise 00
	// Exercise 01
	// Exercise 02
	char *carr[10] = {"Hello", "$", "World", "!", "42", "Seoul"};
	t_list *begin_list = 0;
	for (int i = 0; i < 6; ++i) {
		printf("%d ", ft_list_size(begin_list));
		ft_list_push_front(&begin_list, carr[i]);
	}
	printf("\n");
	/*
	// Exercise 09
	ft_list_foreach(begin_list, putstr);
	printf("\n");

	// Exercise 03
	printf("%s\n", ft_list_last(begin_list)->data);	

	// Exercise 04
	begin_list = 0;
	for (int i = 0; i < 6; ++i) {
		ft_list_push_back(&begin_list, carr[i]);
	}
	ft_list_foreach(begin_list, putstr);
	printf("\n");

	// Exercise 05
	begin_list = ft_list_push_strs(3, carr);
	ft_list_foreach(begin_list, putstr);
	printf("\n");

	// Exercise 06
	ft_list_clear(begin_list, putstr);
	begin_list = 0;
	printf("\n");

	// Exercise 07
	begin_list = ft_list_push_strs(6, carr);
	for (int i = 0; i < 6; ++i) {
		printf("%s ", ft_list_at(begin_list, i)->data);
	}
	printf("\n\n");

	printf("Exercise 08\n");
	// Exercise 08
	for (int i = 6; i >= 0; --i) {
		begin_list = ft_list_push_strs(i, carr);
		ft_list_reverse(&begin_list);
		if (i > 0) {
			ft_list_foreach(begin_list, putstr);
			printf("\n");
		} else {
			printf("%p\n\n", begin_list);
		}
	}	

	printf("Exercise 10~12\n");
	// Exercise 10
	begin_list = 0;
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < i; ++j) {
			ft_list_push_front(&begin_list, carr[j]);
		}
	}
	ft_list_foreach_if(begin_list, putstr, carr[1], ft_strcmp);
	printf("\n");

	// Exercise 11
	ft_list_foreach(ft_list_find(begin_list, carr[0], ft_strcmp), putstr);
	printf("\n");

	// Exercise 12
	ft_list_push_front(&begin_list, carr[0]);
	for (int i = 0; i < 3; ++i) {
		ft_list_remove_if(&begin_list, carr[i], ft_strcmp, putstr);
		printf("\n");
		ft_list_foreach(begin_list, putstr);
		printf("\n");
	}
	printf("\n");

	printf("Exercise 13~15\n");
	// Exercise 13
	begin_list = 0;
	ft_list_merge(&begin_list, ft_list_push_strs(3, carr));
	ft_list_foreach(begin_list, putstr);
	printf("\n");
	ft_list_merge(&begin_list, ft_list_push_strs(3, carr + 3));
	ft_list_foreach(begin_list, putstr);
	printf("\n");

	// Exercise 14
	ft_list_sort(&begin_list, ft_strcmp);
	ft_list_foreach(begin_list, putstr);
	printf("\n");
	begin_list = ft_create_elem(carr[0]);
	ft_list_sort(&begin_list, ft_strcmp);
	ft_list_foreach(begin_list, putstr);
	begin_list = 0;
	ft_list_sort(&begin_list, ft_strcmp);
	printf("%p\n", begin_list);

	// Exercise 15
	for (int i = 6; i >= 0; --i) {
		begin_list = ft_list_push_strs(i, carr);
		ft_list_reverse_fun(begin_list);
		ft_list_foreach(begin_list, putstr);
		printf("\n");
	}	

	printf("Exercise 16~17\n");
	// Exercise 16
	begin_list = 0;
	for (int i = 0; i < 6; ++i) {
		ft_sorted_list_insert(&begin_list, carr[i], ft_strcmp);
	}
	ft_list_foreach(begin_list, putstr);
	printf("\n");

	// Exercise 17
	begin_list = 0;
	t_list *sub_list = 0;
	for (int i = 0; i < 6; ++i) {
		ft_sorted_list_insert(&sub_list, carr[i % 3], ft_strcmp);
	}
	ft_list_foreach(sub_list, putstr);
	printf("\n");
	ft_sorted_list_merge(&begin_list, sub_list, ft_strcmp);
	ft_list_foreach(begin_list, putstr);
	printf("\n");
	sub_list = 0;
	for (int i = 0; i < 6; ++i) {
		ft_sorted_list_insert(&sub_list, carr[i % 3], ft_strcmp);
	}
	ft_sorted_list_merge(&begin_list, sub_list, ft_strcmp);
	ft_list_foreach(begin_list, putstr);
	printf("\n");
	*/
	return 0;
}
