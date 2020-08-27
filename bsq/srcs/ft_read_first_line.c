/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_board.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 17:13:49 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/27 12:29:54 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str_node.h"
#include "ft_board.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <libgen.h>
#include <string.h>

t_str_node	*ft_create_str_node(char c)
{
	t_str_node *ret;

	if (!(ret = malloc(sizeof(t_str_node))))
		exit(1);
	ret->next = NULL;
	ret->c = c;
	return (ret);
}

int			*node_to_tab(int *ret, t_str_node *ancre)
{
	int			i;
	t_str_node	*tmp;

	i = -1;
	while (ancre)
	{
		if (ancre->c == g_empty || ancre->c == g_full)
			ret[++i] = 1;
		else if (ancre->c == g_obstacle)
			ret[++i] = 0;
		else
			return (NULL);
		tmp = ancre;
		ancre = ancre->next;
		free(tmp);
	}
	return (ret);
}

int			*read_first_line(int fd)
{
	char		c;
	int			byte_read;
	t_str_node	*ancre;
	t_str_node	*last;
	int			*ret;

	if ((byte_read = read(fd, &c, 1)) <= 0 || c == '\n')
		return (0);
	ancre = ft_create_str_node(c);
	last = ancre;
	g_col = 1;
	while ((byte_read = read(fd, &c, 1)) > 0 && c != '\n')
	{
		if (!(c == g_empty || c == g_obstacle || c == g_full))
			return (NULL);
		g_col += byte_read;
		if (!(last->next = ft_create_str_node(c)))
			return (NULL);
		last = last->next;
	}
	if (!(ret = malloc(g_col * sizeof(int))))
		exit(1);
	if (!(ret = node_to_tab(ret, ancre)))
		return (NULL);
	return (ret);
}
