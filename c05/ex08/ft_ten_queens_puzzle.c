/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 12:13:10 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/17 20:42:48 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_is_case_ok(int *board, int col, int row)
{
	int i;

	i = 1;
	while (col--)
	{
		if (board[col] == row)
			return (0);
		if (board[col] == row - i)
			return (0);
		if (board[col] == row + i)
			return (0);
		i++;
	}
	return (1);
}

void	ft_print_solution(int *board)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = board[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int		ft_search_solutions(int *board, int col, int *counter)
{
	int i;

	if (col == 10)
	{
		*counter += 1;
		ft_print_solution(board);
		return (1);
	}
	i = 0;
	while (i < 10)
	{
		if (ft_is_case_ok(board, col, i))
		{
			board[col] = i;
			ft_search_solutions(board, col + 1, counter);
		}
		i++;
	}
	board[col] = -1;
	return (0);
}

int		ft_ten_queens_puzzle(void)
{
	int board[10];
	int i;
	int counter;

	i = -1;
	while (++i < 10)
		board[i] = -1;
	counter = 0;
	ft_search_solutions(board, 0, &counter);
	return (counter);
}
