/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 21:26:19 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/20 21:26:53 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "hexdump.h"

void	ft_print_at_exit(t_buff *buff)
{
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
}

void	ft_read_0(t_buff *buff)
{
	int read_byte;

	while ((read_byte = read(0, buff->str + buff->strlen,
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
	if (buff->strlen == -1)
	{
		ft_error(buff);
		buff->strlen = 0;
		return ;
	}
	buff->strlen += read_byte;
	ft_print_at_exit(buff);
}
