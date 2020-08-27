/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 19:53:25 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/15 23:33:38 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_print_board(int **board)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = board[i][j] + '0';
			write(1, &c, 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int		**ft_create_board(void)
{
	int		**board;
	int		i;
	int		j;

	board = malloc(4 * sizeof(int*));
	if (board == NULL)
		return (NULL);
	i = -1;
	while (++i < 4)
	{
		board[i] = malloc(4 * sizeof(int));
		if (board[i] == NULL)
			return (NULL);
	}
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			board[i][j] = 0;
	}
	return (board);
}

void	ft_free_board(int **board)
{
	int i;

	i = -1;
	while (++i < 4)
		free(board[i]);
	free(board);
}
