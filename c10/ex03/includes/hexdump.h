/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdumb.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 22:39:14 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/20 21:28:36 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEXDUMP_H
# define HEXDUMP_H
# include "s_buff.h"
# include "ft_str.h"

/*
**	convert_base.c
*/
char	*ft_putnbr_base(int nb, char *base_to);
/*
**	write_line.c
*/
void	ft_print_hex_len(int nb, int len);
void	ft_write_line(t_buff *buff);
/*
**	s_buff.c
*/
void	ft_init_buff(t_buff *buff, int ac, char **av);
void	ft_save_buff_str(t_buff *buff);
/*
**	file.c
*/
int		ft_open_next_files(t_buff *buff);
void	ft_read_file(t_buff *buff);
void	ft_with_files(t_buff *buff);
/*
**	read0.c
*/
void	ft_read_0(t_buff *buff);
/*
**	main.c
*/
void	ft_error(t_buff *buff);

#endif
