/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:06:43 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/01/14 12:39:29 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	fractol_color(int now, int which_color)
{
	unsigned int	color[4];

	color[0] = 0; // a 투명도
	if (which_color == RED)
	{
		color[1] = (sin((double)now) + 1) * 127; // r 빨강
		color[2] = 120; // g 초록
		color[3] = 120; // b 파랑
	}
	else if (which_color == PURPLE)
	{
		color[1] = 150; // r 빨강
		color[2] = (sin((double)now) + 1) * 127; // g 초록
		color[3] = 150; // b 파랑
	}
	return (color[0] << 24 | color[1] << 16 | color[2] << 8 | color[3]);
}
