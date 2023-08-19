/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:18:03 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/08/07 18:18:04 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int		**make_map(char **perl_map, unsigned int w, unsigned int h);
void	find_max_size(char **perl_map, int **map, int w, int h);
void	print_map(char **map, int w, int h);

int	main(void)
{
	char	**perl_map;
	int		**map;
	int		w = 5;
	int		h = 5;

	perl_map = malloc(sizeof(char *) * 5);
	for(int i = 0; i < 5; i++)
		perl_map[i] = malloc(sizeof(char) * 5);
	
	for(int i = 0; i < 5; i++){
		for(int j=0;j<5;j++)
			perl_map[i][j]='.';
	}
	perl_map[4][3] = 'o';
	perl_map[1][1] = 'o';

	map = make_map(perl_map, w, h);
	find_max_size(perl_map, map, w, h);
	print_map(perl_map, w, h);
	return (0);
}
