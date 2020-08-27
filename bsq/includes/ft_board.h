/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_board.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 02:04:54 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/27 12:26:46 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOARD_H
# define FT_BOARD_H

extern char	g_empty;
extern char	g_obstacle;
extern char	g_full;
extern int	g_row;
extern int	g_col;

int			read_board_data(int fd);
int			get_line_len(int *fd, char *path);
int			*read_line(int fd);
int			**ft_read_board(char *path);

int			**algorithm(int **tab);
int			**fill_tab(int **tab);

void		free_char_tab(char **tab);
void		free_int_tab(int **tab);

int			*read_first_line(int fd);

int			ft_strlen(char *str);

#endif
