/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 00:29:39 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/11 19:07:57 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int i;
	int value;

	i = 1;
	value = 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (i++ < nb)
		value = value * i;
	return (value);
}
