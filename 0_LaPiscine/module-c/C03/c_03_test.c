#include "ex00/ft_strcmp.c"
#include "ex01/ft_strncmp.c"
#include "ex02/ft_strcat.c"
#include "ex03/ft_strncat.c"
#include "ex04/ft_strstr.c"
#include "ex05/ft_strlcat.c"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("-ex00_test_case-\n\n");
	char *test1 = "Hello";
	char *test2 = "Hell";
	char *test3 = "Hello42";
	char *test4 = "Hexlo";
	char *test5 = "Hello";
	printf("s1 : Hello | s2 : Hell  ->   strcmp : %d | ft_strcmp : %d\n", strcmp(test1, test2), ft_strcmp(test1, test2));
	printf("s1 : Hello | s2 : Hello42  ->   strcmp : %d | ft_strcmp : %d\n", strcmp(test1, test3), ft_strcmp(test1, test3));
	printf("s1 : Hello | s2 : Hexlo  ->   strcmp : %d | ft_strcmp : %d\n", strcmp(test1, test4), ft_strcmp(test1, test4));
	printf("s1 : Hello | s2 : Hello  ->   strcmp : %d | ft_strcmp : %d\n", strcmp(test1, test5), ft_strcmp(test1, test5));
	printf("\n\n------------------------------\n\n");

	printf("-ex01_test_case-\n\n");
	printf("s1 : Hello | s2 : Hell | n : 2 ->   strncmp : %d | ft_strncmp : %d\n", strncmp(test1, test2, 2), ft_strncmp(test1, test2, 2));
	printf("s1 : Hello | s2 : Hello42 | n : 7 ->   strncmp : %d | ft_strncmp : %d\n", strncmp(test1, test3, 7), ft_strncmp(test1, test3, 7));
	printf("s1 : Hello | s2 : Hexlo | n : 4 ->   strncmp : %d | ft_strncmp : %d\n", strncmp(test1, test4, 4), ft_strncmp(test1, test4, 4));
	printf("s1 : Hello | s2 : Hello | n : 6 ->   strncmp : %d | ft_strncmp : %d\n", strncmp(test1, test5, 6), ft_strncmp(test1, test5, 6));
	printf("\n\n------------------------------\n\n");

	printf("-ex02_test_case-\n\n");
	char dest1[30] = "How are you?";
	char src1[] = "I'm fine";
	printf("--strcat--\nbefore dest : %s | src : %s\n", dest1, src1);
	strcat(dest1, src1);
	printf("after dest: %s\n\n", dest1);
	char dest2[30] = "How are you?";
	char src2[] = "I'm fine";
	printf("--ft_strcat--\nbefore dest : %s | src : %s\n", dest2, src2);
	ft_strcat(dest2, src2);
	printf("after dest : %s", dest2);
	printf("\n\n------------------------------\n\n");

	printf("-ex03_test_case-\n\n");
	char dest3[30] = "How are you?";
	printf("--strncat--\nbefore dest : %s | src : %s | n : 6\n", dest3, src1);
	strncat(dest3, src1, 6);
	printf("after dest: %s\n\n", dest3);
	char dest4[30] = "How are you?";
	printf("--ft_strncat--\nbefore dest : %s | src : %s | n : 6\n", dest4, src2);
	ft_strncat(dest4, src2, 6);
	printf("after dest : %s", dest4);
	printf("\n\n------------------------------\n\n");

	printf("-ex04_test_case-\n\n");
	char test6[] = "Hello42";
	char test7[] = "";
	char test8[] = "That's not true";
	char to_find[] = "llo";
	printf("you use this to_find : llo\n\n");
	printf("--strstr--\nstr : Hello42 | result : %s\n", strstr(test6, to_find));
	printf("str : {empty} | result : %s\n", strstr(test7, to_find));
	printf("str : That's not true | result : %s\n\n", strstr(test8, to_find));
	printf("--ft_strstr--\nstr : Hello42 | result : %s\n", ft_strstr(test6, to_find));
	printf("str : {empty} | result : %s\n", ft_strstr(test7, to_find));
	printf("str : That's not true | result : %s\n\n", ft_strstr(test8, to_find));
	printf("\n\n------------------------------\n\n");

	printf("-ex05_test_case-\n\n");
	char dest5[30] = "123";
	char dest6[30] = "123";
	char dest7[30] = "123";
	char *src3 = "456789";
	printf("--strlcat--\nbefore dest : %s | src : %s | size : 2\n", dest5, src3);
	int stlc_return = strlcat(dest5, src3, 2);
	printf("after dest: %s | return : %d\n\n", dest5, stlc_return);
	printf("--strlcat--\nbefore dest : %s | src : %s | size : 15\n", dest6, src3);
	stlc_return = strlcat(dest6, src3, 15);
	printf("after dest: %s | return : %d\n\n", dest6, stlc_return);
	printf("--strlcat--\nbefore dest : %s | src : %s | size : 9\n", dest7, src3);
	stlc_return = strlcat(dest7, src3, 9);
	printf("after dest: %s | return : %d\n\n", dest7, stlc_return);
	
	char dest8[30] = "123";
	char dest9[30] = "123";
	char dest10[30] = "123";
	printf("--ft_strlcat--\nbefore dest : %s | src : %s | size : 2\n", dest8, src3);
	stlc_return = ft_strlcat(dest8, src3, 2);
	printf("after dest: %s | return : %d\n\n", dest8, stlc_return);
	printf("--ft_strlcat--\nbefore dest : %s | src : %s | size : 15\n", dest9, src3);
	stlc_return = ft_strlcat(dest9, src3, 15);
	printf("after dest: %s | return : %d\n\n", dest9, stlc_return);
	printf("--ft_strlcat--\nbefore dest : %s | src : %s | size : 9\n", dest10, src3);
	stlc_return = ft_strlcat(dest10, src3, 9);
	printf("after dest: %s | return : %d\n\n", dest10, stlc_return);

	printf("\n\n------------------------------\n\n");

	return 0;
}