/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 13:43:49 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/20 23:30:54 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <libgen.h>
#include <string.h>

#include "ft_cat.h"

void	ft_error(char *path, char *exec_name)
{
	write(2, basename(exec_name), ft_strlen(basename(exec_name)));
	write(2, ": ", 2);
	write(2, path, ft_strlen(path));
	write(2, ": ", 2);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
}

void	ft_print_file(int fd, char *path, char *exec_name)
{
	int		byte_read;
	char	buffer[100];

	while ((byte_read = read(fd, buffer, 10)) > 0)
		write(1, buffer, byte_read);
	if (byte_read == -1)
	{
		ft_error(path, exec_name);
		return ;
	}
}

void	ft_open_print_file(char *path, char *exec_name)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_error(path, exec_name);
		return ;
	}
	ft_print_file(fd, path, exec_name);
	close(fd);
}

void	ft_print_all_files(int ac, char **av)
{
	int i;

	i = 0;
	while (++i < ac)
		ft_open_print_file(av[i], av[0]);
}

int		main(int ac, char **av)
{
	if (ac < 2)
	{
		ft_print_file(0, "", av[0]);
	}
	else
	{
		ft_print_all_files(ac, av);
	}
	return (0);
}
