/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 01:28:48 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/13 16:09:29 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	int i;

	if (nb < 2 || nb % 2 == 0)
		return (0);
	i = 2;
	while (i < 46341)
	{
		if (nb % i == 0 && nb != i)
			return (0);
		i++;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	if (nb < 3)
		return (2);
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}
