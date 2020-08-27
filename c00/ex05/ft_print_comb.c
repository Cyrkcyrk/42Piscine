/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 12:50:42 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/05 14:04:31 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_spacer(void)
{
	ft_putchar(',');
	ft_putchar(' ');
}

void	ft_print_number(int c1, int c2, int c3)
{
	ft_putchar(c1 + '0');
	ft_putchar(c2 + '0');
	ft_putchar(c3 + '0');
	if (c1 != 7 || c2 != 8 || c3 != 9)
		ft_print_spacer();
}

void	ft_print_comb(void)
{
	int c1;
	int c2;
	int c3;

	c1 = 0;
	c2 = 1;
	c3 = 3;
	while (c1 < 8)
	{
		c2 = c1 + 1;
		while (c2 < 9)
		{
			c3 = c2 + 1;
			while (c3 < 10)
			{
				ft_print_number(c1, c2, c3);
				c3++;
			}
			c2++;
		}
		c1++;
	}
}
