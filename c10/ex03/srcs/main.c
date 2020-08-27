/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 19:10:00 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/21 15:53:00 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include <libgen.h>
#include <string.h>

#include "hexdump.h"

void	ft_error(t_buff *buff)
{
	write(2, basename(buff->av[0]), ft_strlen(basename(buff->av[0])));
	write(2, ": ", 2);
	write(2, buff->av[buff->av_pos], ft_strlen(buff->av[buff->av_pos]));
	write(2, ": ", 2);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
}

int		main(int ac, char **av)
{
	t_buff buffer;

	ft_init_buff(&buffer, ac, av);
	if (ac >= 2 && ft_strncmp(av[1], "-C", 2) == 0)
	{
		buffer.av_pos = 1;
		buffer.c_mode = 1;
	}
	if (ac <= 1 || (ac == 2 && buffer.c_mode == 1))
		ft_read_0(&buffer);
	else
		ft_with_files(&buffer);
	return (0);
}
