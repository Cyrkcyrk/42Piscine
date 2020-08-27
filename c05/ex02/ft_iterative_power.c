/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 00:43:45 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/11 11:04:57 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int i;
	int value;

	value = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	i = 1;
	while (i++ < power)
		value = value * nb;
	return (value);
}
