/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_buff.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 22:43:18 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/20 23:57:49 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_BUFF_H
# define S_BUFF_H

typedef struct	s_buff
{
	char	str[16];
	char	prev_str[16];
	int		pos;
	int		strlen;
	int		prev_strlen;
	int		count;
	char	**av;
	int		ac;
	int		av_pos;
	int		fd;
	char	c_mode;
	char	prev_stars;
	char	bad_file_descriptor;
}				t_buff;

#endif
