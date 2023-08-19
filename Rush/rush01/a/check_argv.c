/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:29:28 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/07/30 12:52:04 by gyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	argv_error_condition(char c, int *cnt, int *plus, int *blank)
{
	if (c == ' ')
	{
		if (*blank)
			return (0);
		*blank = 1;
	}
	else if (c == '+')
	{
		if (*plus)
			return (0);
		*plus = 1;
	}
	else if ('1' <= c && c <= '9')
	{
		if (*blank == 0)
			return (0);
		(*cnt)++;
		*blank = 0;
		*plus = 0;
	}
	return (1);
}

int	is_argv_error(char *arr)
{
	int	i;
	int	cnt;
	int	blank;
	int	plus;

	i = 0;
	cnt = 0;
	plus = 0;
	blank = 1;
	while (arr[i] == ' ' || arr[i] == '+' || ('1' <= arr[i] && arr[i] <= '9'))
	{
		if (!argv_error_condition(arr[i], &cnt, &plus, &blank))
			return (0);
		i++;
	}
	if (cnt % 4 || arr[i] != '\0')
		return (0);
	if (arr[i] == '\0' && ('1' <= arr[i - 1] && arr[i - 1] <= '9'))
		return (cnt / 4 + 2);
	return (0);
}
