/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 21:38:01 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/15 23:55:04 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

/*
** board
*/
void	ft_print_board(int **board);
int		**ft_create_board();
void	ft_free_board(int **board);
/*
** col
*/
int		ft_is_in_col(int value, int **board, int col);
int		ft_checkcol(int **board, int *condition, int col);
/*
** row
*/
int		ft_is_in_row(int value, int **board, int row);
int		ft_checkrow(int **board, int *condition, int row);
/*
** args
*/
int		is_numeric(char c);
int		ft_strlen(char *str);
int		is_correct_format(char *str);
void	num_str_to_int(char *str, int *tab);
#endif
