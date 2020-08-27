/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:23:34 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/24 16:50:09 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "do_op.h"

void	fill_tab_op(t_op *tab)
{
	tab[0].symbole = '+';
	tab[0].ft = &op_addition;
	tab[1].symbole = '-';
	tab[1].ft = &op_substraction;
	tab[2].symbole = '*';
	tab[2].ft = &op_multiplication;
	tab[3].symbole = '/';
	tab[3].ft = &op_division;
	tab[4].symbole = '%';
	tab[4].ft = &op_modulo;
}

int		main(int ac, char **av)
{
	int		i;
	t_op	operation_tab[5];

	if (ac != 4)
		return (0);
	if (av[2][0] == '\0' || av[2][1] != '\0')
	{
		write(1, "0\n", 2);
		return (0);
	}
	fill_tab_op(operation_tab);
	i = -1;
	while (++i < 5)
	{
		if (operation_tab[i].symbole == av[2][0])
		{
			operation_tab[i].ft(ft_atoi(av[1]), ft_atoi(av[3]));
			return (0);
		}
	}
	write(1, "0\n", 2);
	return (0);
}
