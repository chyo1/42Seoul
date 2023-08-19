#include <stdio.h>
#include <string.h>
#include "ex00/ft_ft.c"
#include "ex01/ft_ultimate_ft.c"
#include "ex02/ft_swap.c"
#include "ex03/ft_div_mod.c"
#include "ex04/ft_ultimate_div_mod.c"
#include "ex05/ft_putstr.c"
#include "ex06/ft_strlen.c"
#include "ex07/ft_rev_int_tab.c"
#include "ex08/ft_sort_int_tab.c"

int	main()
{
	int	np = 0;
	int	num = 0;
	int	arr[10] = {2, 1, 4, 7, 4, 8, 3, 6, 4, 7};
	int	*twop = &np;
	int	**trip = &twop;
	int	***forp = &trip;
	int	****fivp = &forp;
	int	*****sixp = &fivp;
	int	******sevp = &sixp;
	int	*******eitp = &sevp;
	int	********ninp = &eitp;
	int	*********ultp = &ninp;

	printf("[ EX 00 ]\n");
	ft_ft(&np);
	if (np == 42)
		printf("[   o   ]\n");
	else
		printf("[   X   ]\n");
	
	printf("\n[ EX 01 ]\n");
	ft_ultimate_ft(ultp);
	if (np == 42)
		printf("[   o   ]\n");
	else
		printf("[   X   ]\n");

	printf("\n[ EX 02 ]\n");
	np = 501;
	num = 42;
	ft_swap(&np, &num);
	if (np == 42 && num == 501)
		printf("[   o   ]\n");
	else
		printf("[   X   ]\n");

	printf("\n[ EX 03 ]\n");
	ft_div_mod(12, 4, &np, &num);
	if (np == 3 && num == 0)
		printf("[   o   ]\n");
	else
		printf("[   X   ]\n");

	printf("\n[ EX 04 ]\n");
	np = 46;
	num = 3;
	ft_ultimate_div_mod(&np, &num);
	if (np == 15 && num == 1)
		printf("[   o   ]\n");
	else
		printf("[   X   ]\n");

	printf("\n[ EX 05 ]\n");
	printf("윗줄 : 스트링\n아래줄 : 함수 출력\nHello world!\n");
	ft_putstr("Hello world!");

	printf("\n\n[ EX 06 ]\n");
	np = strlen("This is the Way");
	num = ft_strlen("This is the way");
	if (np == num)
		printf("[   o   ]\n");
	else
		printf("[   X   ]\n");

	printf("\n[ EX 07 ]\n");
	ft_rev_int_tab(arr, 10);
	if (arr[0] == 7 && arr[1] == 4 && arr[2] == 6 && arr[3] == 3 && arr[4] == 8 && arr[5] == 4 && arr[6] == 7 && arr[7] == 4 && arr[8] == 1 && arr[9] == 2)
		printf("[   o   ]\n");
	else
		printf("[   X   ]\n");
	for(int i=0;i<10;i++) printf("%d ", arr[i]);
	
	printf("\n[ EX 08 ]\n");
	ft_sort_int_tab(arr, 10);
	if (arr[0] == 1 && arr[1] == 2 && arr[2] == 3 && arr[3] == 4 && arr[4] == 4 && arr[5] == 4 && arr[6] == 6 && arr[7] == 7 && arr[8] == 7 && arr[9] == 8)
		printf("[   o   ]\n");
	else
		printf("[   X   ]\n");
	for(int i=0;i<10;i++) printf("%d ", arr[i]);
}
