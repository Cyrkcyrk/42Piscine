/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 20:43:39 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/21 10:41:35 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <libgen.h>

#include "hexdump.h"

int		ft_open_next_files(t_buff *buff)
{
	char end;

	end = 1;
	if (buff->fd != -1)
		close(buff->fd);
	while (end)
	{
		if (buff->av_pos + 1 < buff->ac)
			buff->av_pos += 1;
		else
			return (0);
		buff->fd = open(buff->av[buff->av_pos], O_RDONLY);
		if (buff->fd == -1)
			ft_error(buff);
		else
			return (1);
	}
	return (0);
}

void	ft_read_file(t_buff *buff)
{
	int read_byte;

	while ((read_byte = read(buff->fd, buff->str + buff->strlen,
		16 - buff->strlen)) > 0)
	{
		buff->strlen += read_byte;
		if (buff->strlen == 16)
		{
			ft_write_line(buff);
			ft_save_buff_str(buff);
			buff->count += 16;
			buff->strlen = 0;
		}
	}
	if (read_byte == -1)
	{
		buff->bad_file_descriptor = 0;
		ft_error(buff);
		return ;
	}
}

void	ft_with_files(t_buff *buff)
{
	while (ft_open_next_files(buff))
		ft_read_file(buff);
	ft_write_line(buff);
	buff->count += buff->strlen;
	if (buff->count != 0 && buff->c_mode == 0)
	{
		ft_print_hex_len(buff->count, 7);
		write(1, "\n", 1);
	}
	else if (buff->count != 0)
	{
		ft_print_hex_len(buff->count, 8);
		write(1, "\n", 1);
	}
	else if (buff->bad_file_descriptor)
	{
		write(2, basename(buff->av[0]), ft_strlen(basename(buff->av[0])));
		write(2, ": ", 2);
		write(2, buff->av[buff->av_pos], ft_strlen(buff->av[buff->av_pos]));
		write(2, ": ", 2);
		write(2, "Bad file descriptor\n", 20);
	}
}
