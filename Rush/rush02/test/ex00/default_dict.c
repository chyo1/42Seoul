/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_dict.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 15:08:40 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/08/05 15:08:52 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	fill_0_to_19_key(char **key)
{
	key[0] = "0";
	key[1] = "1";
	key[2] = "2";
	key[3] = "3";
	key[4] = "4";
	key[5] = "5";
	key[6] = "6";
	key[7] = "7";
	key[8] = "8";
	key[9] = "9";
	key[10] = "10";
	key[11] = "11";
	key[12] = "12";
	key[13] = "13";
	key[14] = "14";
	key[15] = "15";
	key[16] = "16";
	key[17] = "17";
	key[18] = "18";
	key[19] = "19";
}

void	fill_20_to_bil_key(char **key)
{
	key[20] = "20";
	key[21] = "30";
	key[22] = "40";
	key[23] = "50";
	key[24] = "60";
	key[25] = "70";
	key[26] = "80";
	key[27] = "90";
	key[28] = "100";
	key[29] = "1000";
	key[30] = "1000000";
	key[31] = "1000000000";
}

void	fill_0_to_19_val(char **val)
{
	val[0] = "zero";
	val[1] = "one";
	val[2] = "two";
	val[3] = "three";
	val[4] = "four";
	val[5] = "five";
	val[6] = "six";
	val[7] = "seven";
	val[8] = "eight";
	val[9] = "nine";
	val[10] = "ten";
	val[11] = "eleven";
	val[12] = "twelve";
	val[13] = "thirteen";
	val[14] = "fourteen";
	val[15] = "fifteen";
	val[16] = "sixteen";
	val[17] = "seventeen";
	val[18] = "eighteen";
	val[19] = "nineteen";
}

void	fill_20_to_bil_val(char **val)
{
	val[20] = "twenty";
	val[21] = "thirty";
	val[22] = "forty";
	val[23] = "fifty";
	val[24] = "sixty";
	val[25] = "seventy";
	val[26] = "eighty";
	val[27] = "ninety";
	val[28] = "hundred";
	val[29] = "thousand";
	val[30] = "million";
	val[31] = "billion";
}

void	default_dict(char **key, char **val)
{
	int		i;
	char	**keyarr;
	char	**valarr;

	i = 0;
	keyarr = (char **)malloc(sizeof(char *) * 32);
	valarr = (char **)malloc(sizeof(char *) * 32);
	while (i < 32)
	{
		keyarr[i] = (char *)malloc(sizeof(char) * 11);
		valarr[i] = (char *)malloc(sizeof(char) * 11);
		i++;
	}
	fill_0_to_19_key(keyarr);
	fill_20_to_bil_key(keyarr);
	fill_0_to_19_val(valarr);
	fill_20_to_bil_val(valarr);
	key = keyarr;
	val = valarr;
}
