/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 14:08:20 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/09 14:55:05 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	buffer;
	long	tmp;

	tmp = (long)nb;
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (tmp < 0)
		{
			tmp = -tmp;
			ft_putchar('-');
		}
		buffer = tmp % 10;
		if (tmp / 10 != 0)
			ft_putnbr(tmp / 10);
		ft_putchar(buffer + '0');
	}
}
