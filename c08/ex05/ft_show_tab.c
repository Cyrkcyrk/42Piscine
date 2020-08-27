/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 12:08:11 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/26 20:46:51 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_show_tab(struct s_stock_str *par)
{
	int i;

	i = -1;
	while (par[++i].str != 0)
	{
		ft_putnbr(par[i].str);
		ft_putchar('\n');
		ft_putstr(par[i].size);
		ft_putchar('\n');
		ft_putstr(par[i].copy);
		ft_putchar('\n');
	}
}
