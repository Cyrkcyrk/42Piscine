/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 21:58:23 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/21 11:08:28 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_read_file(int file)
{
	char	buffer[10];
	int		byte_read;

	while ((byte_read = read(file, buffer, 10)))
	{
		write(1, buffer, byte_read);
	}
}

int		main(int ac, char **av)
{
	int file;

	if (ac < 2)
	{
		write(2, "File name missing.\n", 19);
		return (0);
	}
	if (ac > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (0);
	}
	file = open(av[1], O_RDONLY);
	if (file == -1)
	{
		write(2, "Cannot read file.\n", 18);
		return (0);
	}
	ft_read_file(file);
	close(file);
	return (0);
}
