/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 18:32:24 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/09 15:01:09 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_number(int *c)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (c[i] > -1)
			ft_putchar(c[i] + '0');
		i++;
	}
}

int		ft_is_end(int *tab, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (tab[8 - i] != 9 - i)
			return (0);
		i++;
	}
	return (1);
}

void	ft_update_col(int *tab, int col)
{
	if (tab[col - 1] > -1 && tab[col - 1] + 1 > col && col > 0)
	{
		ft_update_col(tab, col - 1);
		tab[col - 1] = tab[col - 2];
	}
	tab[col - 1]++;
}

void	ft_print_combn(int n)
{
	int c[9];
	int i;

	if (n > 0 && n < 10)
	{
		i = -1;
		while (i++ < 8)
		{
			if (i < n)
				c[8 - i] = n - i - 1;
			else
				c[8 - i] = -1;
		}
		while (!ft_is_end(c, n))
		{
			ft_print_number(c);
			ft_putchar(',');
			ft_putchar(' ');
			ft_update_col(c, 9);
		}
		ft_print_number(c);
	}
}
