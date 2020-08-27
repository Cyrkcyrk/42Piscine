/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ck_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 12:24:05 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/23 22:25:52 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "ck_dict.h"

int		dict_len_file(char *path)
{
	int		fd;
	int		byte_read;
	int		total;
	char	buff[100];

	if ((fd = open(path, O_RDONLY)) == -1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	total = 0;
	while ((byte_read = read(fd, buff, 100)) > 0)
	{
		total += byte_read;
	}
	close(fd);
	if (byte_read == -1)
		return (0);
	return (total);
}

char	*dict_to_str(char *path)
{
	int		fd;
	int		byte_read;
	char	*ret;
	int		pos;
	int		len;

	if ((len = dict_len_file(path)) == 0)
		return (NULL);
	if ((fd = open(path, O_RDONLY)) == -1)
		return (NULL);
	if (!(ret = malloc((len + 1) * sizeof(char))))
	{
		close(fd);
		return (NULL);
	}
	pos = 0;
	while ((byte_read = read(fd, ret + pos, 100)) > 0)
		pos += byte_read;
	close(fd);
	if (byte_read == -1)
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}

char	**parse_dict_file(char *path)
{
	char	*dict_str;
	char	**dict_line;

	if ((dict_str = dict_to_str(path)) == NULL)
		return (NULL);
	if ((dict_line = ft_split(dict_str, "\n")) == NULL)
	{
		free(dict_str);
		return (NULL);
	}
	free(dict_str);
	return (dict_line);
}
