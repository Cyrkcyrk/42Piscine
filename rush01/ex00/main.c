/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 19:54:57 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/16 17:36:21 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <stdlib.h>
#include <unistd.h>

int		ft_is_valid(int **board, int *args, int pos)
{
	int x;
	int y;
	int i;

	if (pos == 16)
		return (1);
	x = pos / 4;
	y = pos % 4;
	if (board[x][y] != 0)
		return (ft_is_valid(board, args, pos + 1));
	i = 0;
	while (++i < 5)
	{
		if (!ft_is_in_col(i, board, y) && !ft_is_in_row(i, board, x))
		{
			board[x][y] = i;
			if (ft_checkcol(board, args, y) && ft_checkrow(board, args, x))
			{
				if (ft_is_valid(board, args, pos + 1) == 1)
					return (1);
			}
		}
	}
	board[x][y] = 0;
	return (0);
}

int		main(int ac, char **av)
{
	int *conditions;
	int **board;

	if (ac != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!is_correct_format(av[1]))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	conditions = malloc(16 * sizeof(int));
	num_str_to_int(av[1], conditions);
	board = ft_create_board();
	if (board == NULL)
		return (0);
	if (ft_is_valid(board, conditions, 0))
		ft_print_board(board);
	else
		write(1, "Error\n", 6);
	ft_free_board(board);
	free(conditions);
	return (0);
}
