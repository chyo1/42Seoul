/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:37:02 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/08/02 10:37:06 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_point.h"
#include <stdio.h>
void set_point(t_point *point)
{
point->x = 42;
point->y = 21;
}

int main(void)
{
t_point point;
set_point(&point);
printf("%d %d", point.x, point.y);
return (0);
}