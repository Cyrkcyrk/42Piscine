/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_buff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 22:46:07 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/20 23:58:19 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_buff.h"

void	ft_init_buff(t_buff *buff, int ac, char **av)
{
	buff->pos = 0;
	buff->strlen = 0;
	buff->prev_strlen = 0;
	buff->count = 0;
	buff->av = av;
	buff->ac = ac;
	buff->av_pos = 0;
	buff->fd = -1;
	buff->c_mode = 0;
	buff->prev_stars = 0;
	buff->bad_file_descriptor = 1;
}

void	ft_save_buff_str(t_buff *buff)
{
	int i;

	i = -1;
	while (++i < buff->strlen)
		buff->prev_str[i] = buff->str[i];
	buff->prev_strlen = buff->strlen;
}
