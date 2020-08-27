/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 19:44:58 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/15 23:55:20 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_in_row(int value, int **board, int row)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (value == board[row][i])
			return (1);
		i++;
	}
	return (0);
}

int		ft_is_row_valid_right(int **board, int *condition, int row)
{
	int max;
	int view;
	int i;

	max = 0;
	view = 0;
	i = 0;
	while (i < 4)
	{
		if (board[row][i] > max)
		{
			max = board[row][i];
			view++;
		}
		if (board[row][i] == 0)
			return (-1);
		i++;
	}
	if (condition[row + 8] != view)
		return (0);
	return (1);
}

int		ft_is_row_valid_left(int **board, int *condition, int row)
{
	int max;
	int view;
	int i;

	i = 3;
	max = 0;
	view = 0;
	while (i >= 0)
	{
		if (board[row][i] > max)
		{
			max = board[row][i];
			view++;
		}
		if (board[row][i] == 0)
			return (-1);
		i--;
	}
	if (condition[row + 12] != view)
		return (0);
	return (1);
}

int		ft_checkrow(int **board, int *condition, int row)
{
	if (ft_is_row_valid_right(board, condition, row) &&
			ft_is_row_valid_left(board, condition, row))
		return (1);
	return (0);
}
