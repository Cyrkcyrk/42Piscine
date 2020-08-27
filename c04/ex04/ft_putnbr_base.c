/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 20:58:27 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/25 11:31:52 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_is_base_valid_and_length(char *str)
{
	int i;
	int j;

	i = 0;
	while (str && str[i])
	{
		j = 1;
		while (str[i + j] != '-' && str[i + j] != '+' &&
				str[i + j] != str[i] && str[i + j] != '\0')
			j++;
		if (str[i + j] != '\0')
		{
			return (0);
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		len;
	long	nb;

	nb = nbr;
	len = ft_is_base_valid_and_length(base);
	if (len)
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb *= -1;
		}
		if (nb / len > 0)
			ft_putnbr_base(nb / len, base);
		ft_putchar(base[nb % len]);
	}
}


int main (int ac, char** av)
{
	
}
