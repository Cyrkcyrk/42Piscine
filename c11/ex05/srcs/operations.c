/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 13:49:15 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/24 14:04:11 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "do_op.h"

void	op_addition(int d1, int d2)
{
	ft_putnbr(d1 + d2);
	write(1, "\n", 1);
}

void	op_substraction(int d1, int d2)
{
	ft_putnbr(d1 - d2);
	write(1, "\n", 1);
}

void	op_multiplication(int d1, int d2)
{
	ft_putnbr(d1 * d2);
	write(1, "\n", 1);
}

void	op_division(int d1, int d2)
{
	if (d2 == 0)
		write(1, "Stop : division by zero\n", 24);
	else
	{
		ft_putnbr(d1 / d2);
		write(1, "\n", 1);
	}
}

void	op_modulo(int d1, int d2)
{
	if (d2 == 0)
		write(1, "Stop : modulo by zero\n", 22);
	else
	{
		ft_putnbr(d1 % d2);
		write(1, "\n", 1);
	}
}
