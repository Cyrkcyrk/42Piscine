/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 22:18:15 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/20 20:51:48 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "hexdump.h"

void	ft_print_hex_len(int nb, int len)
{
	char	*pos_hex;
	int		i;
	int		len_str;

	pos_hex = ft_putnbr_base(nb, "0123456789abcdef");
	len_str = ft_strlen(pos_hex);
	i = len - len_str;
	while (i-- > 0)
		write(1, "0", 1);
	write(1, pos_hex, len_str);
}

void	ft_print_text(t_buff *buff)
{
	int i;

	i = -1;
	write(1, " |", 2);
	while (++i < buff->strlen)
	{
		if (buff->str[i] >= ' ' && buff->str[i] <= '~')
			write(1, &(buff->str[i]), 1);
		else
			write(1, ".", 1);
	}
	write(1, "|\n", 2);
}

void	ft_write_line_cmode(t_buff *buff)
{
	int i;

	ft_print_hex_len(buff->count, 8);
	write(1, "  ", 2);
	i = -1;
	while (++i < 16)
	{
		if (i < buff->strlen)
		{
			ft_print_hex_len((unsigned char)buff->str[i], 2);
			write(1, " ", 1);
		}
		else
			write(1, "   ", 3);
		if (i == 7)
			write(1, " ", 1);
	}
	ft_print_text(buff);
}

void	ft_write_line_normal(t_buff *buff)
{
	int i;

	ft_print_hex_len(buff->count, 7);
	i = -1;
	while (++i < 16)
	{
		if (i < buff->strlen)
		{
			write(1, " ", 1);
			ft_print_hex_len((unsigned char)buff->str[i], 2);
		}
		else
			write(1, "   ", 3);
	}
	write(1, "\n", 1);
}

void	ft_write_line(t_buff *buff)
{
	if (buff->strlen != 0 && buff->strlen == buff->prev_strlen &&
		ft_strncmp(buff->str, buff->prev_str, buff->strlen) == 0)
	{
		if (buff->prev_stars == 0)
		{
			buff->prev_stars = 1;
			write(1, "*\n", 2);
		}
	}
	else if (buff->strlen != 0)
	{
		buff->prev_stars = 0;
		if (buff->c_mode == 1)
			ft_write_line_cmode(buff);
		else
			ft_write_line_normal(buff);
	}
}
