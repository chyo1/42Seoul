int	put_condition(char *con, int arr[][6], int max)
{
	int	idx;
	int	arr_idx[4];
	int	num;

	idx = 0;
	while (idx < 4)
		arr_idx[idx++] = 1;
	idx = 0;
	while (con[idx])
	{
		if ('1' <= con[idx] && con[idx] <= '9')
		{
			num = con[idx] - '0';
			if (num > max - 2)
				return (0);
			if (arr_idx[0] < max - 1)
				arr[0][arr_idx[0]++] = num;
			else if (arr_idx[1] < max - 1)
				arr[max - 1][arr_idx[1]++] = num;
			else if (arr_idx[2] < max - 1)
				arr[arr_idx[2]++][0] = num;
			else if (arr_idx[3] < max - 1)
				arr[arr_idx[3]++][max - 1] = num;
		}
		idx++;
	}
	return (1);
}
