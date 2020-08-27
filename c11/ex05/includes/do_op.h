/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 13:53:24 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/24 16:48:01 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

typedef struct	s_operation
{
	char	symbole;
	void	(*ft)(int, int);
}				t_op;

void			op_addition(int d1, int d2);
void			op_substraction(int d1, int d2);
void			op_multiplication(int d1, int d2);
void			op_division(int d1, int d2);
void			op_modulo(int d1, int d2);

int				ft_atoi(char *str);
void			ft_putnbr(int nb);

void			fill_tab_op(t_op *tab);

#endif
