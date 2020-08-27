/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 19:49:38 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/15 23:54:35 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_in_col(int value, int **board, int col)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (value == board[i][col])
			return (1);
		i++;
	}
	return (0);
}

int		ft_is_col_valid_down(int **board, int *condition, int col)
{
	int max;
	int view;
	int i;

	max = 0;
	view = 0;
	i = 0;
	while (i < 4)
	{
		if (board[i][col] > max)
		{
			max = board[i][col];
			view++;
		}
		if (board[i][col] == 0)
			return (-1);
		i++;
	}
	if (condition[col] != view)
		return (0);
	return (1);
}

int		ft_is_col_valid_up(int **board, int *condition, int col)
{
	int max;
	int view;
	int i;

	i = 3;
	max = 0;
	view = 0;
	while (i >= 0)
	{
		if (board[i][col] > max)
		{
			max = board[i][col];
			view++;
		}
		if (board[i][col] == 0)
			return (-1);
		i--;
	}
	if (condition[col + 4] != view)
		return (0);
	return (1);
}

int		ft_checkcol(int **board, int *condition, int col)
{
	if (ft_is_col_valid_down(board, condition, col) &&
			ft_is_col_valid_up(board, condition, col))
		return (1);
	return (0);
}
