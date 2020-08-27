/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 23:13:45 by rmouduri          #+#    #+#             */
/*   Updated: 2020/08/27 11:48:58 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_board.h"

void	get_square_pos(int **tab, int *coord_i, int *coord_j)
{
	int	i;
	int	j;
	int	square;

	i = -1;
	square = -1;
	while (++i < g_row)
	{
		j = -1;
		while (++j < g_col)
			if (square < tab[i][j])
			{
				square = tab[i][j];
				*coord_i = i;
				*coord_j = j;
			}
	}
}

int		**fill_line(int **tab, int i, int j, int square)
{
	while (square > 0)
	{
		tab[i][j] = g_full;
		j--;
		square--;
	}
	return (tab);
}

int		**fill_tab(int **tab)
{
	int	pos_i;
	int	pos_j;
	int	i;
	int	square;

	get_square_pos(tab, &pos_i, &pos_j);
	square = tab[pos_i][pos_j];
	i = pos_i;
	while (pos_i - i != square)
	{
		tab = fill_line(tab, i, pos_j, square);
		i--;
	}
	return (tab);
}

int		get_nb(int left, int top, int topleft)
{
	int	nb;

	nb = left;
	if (nb > top)
		nb = top;
	if (nb > topleft)
		nb = topleft;
	return (nb + 1);
}

int		**algorithm(int **tab)
{
	int	i;
	int	j;

	i = 0;
	while (++i < g_row)
	{
		j = 0;
		while (++j < g_col)
			if (tab[i][j] != 0)
				tab[i][j] = get_nb(tab[i][j - 1], tab[i - 1][j],
								tab[i - 1][j - 1]);
	}
	return (tab);
}
