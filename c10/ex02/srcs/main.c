/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 16:19:41 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/21 15:55:46 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <libgen.h>
#include <string.h>
#include <stdlib.h>

#include "ft_tails.h"

void	ft_error(char *path, char *exec_name)
{
	write(2, basename(exec_name), ft_strlen(basename(exec_name)));
	write(2, ": ", 2);
	write(2, path, ft_strlen(path));
	write(2, ": ", 2);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
}

int		ft_error_illegal_offset(char **av)
{
	write(2, basename(av[0]), ft_strlen(basename(av[0])));
	write(2, ": illegal offset -- ", 20);
	write(2, av[2], ft_strlen(av[2]));
	write(2, "\n", 1);
	return (0);
}

void	ft_read_file(int tail, int fd)
{
	int		byte_read;
	char	buffer;
	char	*str;
	int		byte_read_total;

	byte_read_total = 0;
	if (!(str = malloc(tail * sizeof(char*))))
		return ;
	ft_empty_buffer(str, tail);
	while ((byte_read = read(fd, &buffer, 1)) > 0)
	{
		byte_read_total += byte_read;
		ft_str_lilo(str, tail, buffer);
	}
	if (byte_read == -1)
		return ;
	if (byte_read_total >= tail)
		write(1, str, tail);
	else
		write(1, (str + tail - byte_read_total), byte_read_total);
	free(str);
	close(fd);
}

void	ft_open_file(char *path, int tail, int *title, char *exec_name)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_error(path, exec_name));
	if (*title)
	{
		if (*title > 1)
			write(1, "\n", 1);
		write(1, "==> ", 4);
		write(1, path, ft_strlen(path));
		write(1, " <==\n", 5);
		*title += 1;
	}
	ft_read_file(tail, fd);
}

int		main(int ac, char **av)
{
	int tail;
	int i;
	int title;

	title = 0;
	if (ac < 3)
		return (0);
	if (ft_strncmp(av[1], "-c", 2) != 0)
		return (0);
	if (!ft_is_numeric(av[2]))
		return (ft_error_illegal_offset(av));
	tail = ft_atoi(av[2]);
	if (ac == 3)
		ft_read_file(tail, 0);
	else if (ac == 4)
		ft_open_file(av[3], tail, &title, av[0]);
	else
	{
		i = 2;
		title = 1;
		while (++i < ac)
			ft_open_file(av[i], tail, &title, av[0]);
	}
	return (0);
}
