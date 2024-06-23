/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:39:29 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/08/02 12:39:34 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex04/ft_strs_to_tab.c"
#include "ex05/ft_show_tab.c"

int main() {
	char *arr[9] = {"The", "Quick", "Brown", "Fox", "Jumps", "Over", "The", "Lazy", "Dog"};
	struct s_stock_str *tab = ft_strs_to_tab(9, arr);
	ft_show_tab(tab);
	for (int i = 0; i < 9; ++i)
		if (tab[i].str == tab[i].copy)
			return -1;
	for (int i = 0; i < 9; ++i) {
		char *p = tab[i].copy;
		while (*p) {
			*p++ = '*';
		}
	}
	ft_show_tab(tab);
	return 0;
}
