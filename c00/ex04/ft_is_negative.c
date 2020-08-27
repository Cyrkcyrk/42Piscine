/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 12:16:45 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/05 12:55:35 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_is_negative(int n)
{
	char positif;
	char negatif;

	positif = 'P';
	negatif = 'N';
	if (n >= 0)
	{
		ft_putchar(positif);
	}
	else
	{
		ft_putchar(negatif);
	}
}
