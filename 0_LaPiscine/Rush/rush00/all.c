
#include <unistd.h>
#include <stdio.h>

auto	ft_putchar(char *arr, int *xyarr, int i, int j);
auto	rush(int x, int y);

int main(int argc, char *argv[])
{
	int	x;
	int	y;
	int	i;
	int	j;
	int	k;

	if (x <= 0 || y <= 0)
		return ;
	x = argv[1] - '0';
	y = argv[0] - '0';
	i = 0;


	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			k = rush(i, j);
			ft_putchar(argv[k]);
			j++;
		}
	i++;
	}
	return (0) ;
}

auto	rush(int x, int y)
{
	char	arr[6];
	
	int		xyarr[2];
	int		i;
	int		j;

	xyarr[0] = x - 1;
	xyarr[1] = y - 1;
	/*arr[0] = 'o';
	arr[1] = 'o';
	arr[2] = 'o';
	arr[3] = 'o';
	arr[4] = '-';
	arr[5] = '|';*/
	i = 0;
	j = 0;

	if (i == 0 && j == 0)
		return (0);
	else if (i == xyarr[0] && j == 0)
		return (1);
	else if (i == 0 && j == xyarr[1])
		return (2);
	else if (i == xyarr[0] && j == xyarr[1])
		return (3);
	else if (j == 0 || j == xyarr[1])
		return (4);
	else if (i == 0 || i == xyarr[0])
		return (5);
	else
		return (6);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
