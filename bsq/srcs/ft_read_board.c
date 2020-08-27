/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_board.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 17:13:49 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/27 12:30:40 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <libgen.h>
#include <string.h>
#include "ft_board.h"

char	g_empty;
char	g_obstacle;
char	g_full;
int		g_row;
int		g_col;

int		read_board_data(int fd)
{
	int		byte_read;
	char	c[4];

	g_row = 0;
	while ((byte_read = read(fd, c, 1)) > 0 && c[0] >= '0' && c[0] <= '9')
		g_row = g_row * 10 + (c[0] - '0');
	if (byte_read <= 0)
		return (0);
	g_empty = c[0];
	if ((byte_read = read(fd, c, 3)) != 3 || c[2] != '\n' || c[0] == c[1] ||
			c[0] == g_empty || c[1] == g_empty)
		return (0);
	g_obstacle = c[0];
	g_full = c[1];
	return (g_row);
}

int		*read_line(int fd)
{
	char	c;
	int		*ret;
	int		byte_read;
	int		total;

	if (!(ret = malloc(g_row * sizeof(int))))
		exit(1);
	total = 0;
	while ((byte_read = read(fd, &c, 1)) > 0 && c != '\n')
	{
		if (c == g_empty || c == g_full)
			ret[total] = 1;
		else if (c == g_obstacle)
			ret[total] = 0;
		else
			return (NULL);
		total++;
	}
	if (byte_read == -1)
		return (NULL);
	if (c != '\n' || total != g_col)
		return (NULL);
	return (ret);
}

void	*ft_free_board_crash(int **board)
{
	int i;

	i = -1;
	while (++i < g_row && board[i] != NULL)
		free(board[i]);
	free(board);
	return (NULL);
}

int		**ft_read_board(char *path)
{
	int fd;
	int **board;
	int i;

	if (path == NULL)
		fd = 0;
	else if ((fd = open(path, O_RDONLY)) == -1)
		return (NULL);
	if (read_board_data(fd) <= 0)
		return (NULL);
	if (!(board = malloc(g_row * sizeof(int *))))
		exit(1);
	if (!(board[0] = read_first_line(fd)))
		return (ft_free_board_crash(board));
	i = 0;
	while (++i < g_row)
		if (!(board[i] = read_line(fd)))
			return (ft_free_board_crash(board));
	return (board);
}
