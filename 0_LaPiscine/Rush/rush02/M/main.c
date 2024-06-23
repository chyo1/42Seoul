/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 20:34:12 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/08/05 20:34:13 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char **argv)
{
	char	**dict_key;
	char	**dict_val;
	char	*dic;

	if (argc == 2)
		defalut_dict(dict_key, dict_val);
	else if (argc == 3)
	{
		dic = fill_dict(dict_key, dict_val);
	}
	else
		return (0);
}
