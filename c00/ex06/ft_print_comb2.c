/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 14:30:57 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/05 14:45:45 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int buffer;

	if (nb == -2147483647)
		write(1, "-2147483647", 11);
	else
	{
		if (nb < 0)
		{
			nb = -nb;
			ft_putchar('-');
		}
		buffer = nb % 10;
		if (nb / 10 != 0)
			ft_putnbr(nb / 10);
		ft_putchar(buffer + '0');
	}
}

void	ft_show_numbers(int nb1, int nb2)
{
	if (nb1 < 10)
		ft_putchar('0');
	ft_putnbr(nb1);
	ft_putchar(' ');
	if (nb2 < 10)
		ft_putchar('0');
	ft_putnbr(nb2);
	if (nb1 != 98 || nb2 != 99)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int nb1;
	int nb2;

	nb1 = 0;
	nb2 = 0;
	while (nb1 < 99)
	{
		nb2 = nb1 + 1;
		while (nb2 < 100)
		{
			ft_show_numbers(nb1, nb2);
			nb2++;
		}
		nb1++;
	}
}
