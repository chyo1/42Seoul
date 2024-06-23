#include <stdio.h>
#include "ex05/ft_split.c"

int main() {
	char **p;
	p = ft_split("The Quick Brown Fox Jumps Over The Lazy Dog", "");
	for (int i = 0; p[i]; ++i)
		printf("\"%s\", ", p[i]);
	printf("\n");

	p = ft_split("The Quick Brown Fox Jumps Over The Lazy Dog", " ");
	for (int i = 0; p[i]; ++i)
		printf("\"%s\", ", p[i]);
	printf("\n");

	p = ft_split(" The Quick Brown Fox Jumps Over The Lazy Dog ", " ");
	for (int i = 0; p[i]; ++i)
		printf("\"%s\", ", p[i]);
	printf("\n");

	p = ft_split("   The   Quick   Brown   Fox   Jumps   Over   The   Lazy   Dog   ", " ");
	for (int i = 0; p[i]; ++i)
		printf("\"%s\", ", p[i]);
	printf("\n");

	p = ft_split("$*$The$Quick*Brown$*Fox$$Jumps**Over*$The***Lazy$$$Dog*$$$*", "$*");
	for (int i = 0; p[i]; ++i)
		printf("\"%s\", ", p[i]);
	printf("\n");

	p = ft_split("0123456789The0123456789Quick0123456789Brown0123456789Fox0123456789Jumps0123456789Over0123456789The0123456789Lazy0123456789Dog0123456789", "0123456789");
	for (int i = 0; p[i]; ++i)
		printf("\"%s\", ", p[i]);
	printf("\n");
	return 0;
}
