/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 19:40:30 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/12 19:52:59 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int		neg;
	int		value;

	neg = 1;
	value = 0;
	while (*str && (*str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r' || *str == ' '))
		str++;
	while (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			neg = -neg;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		value = value * 10 + (*str - '0');
		str++;
	}
	value *= neg;
	if (value > 2147483647 || value < -2147483648)
	{
		return (0);
	}
	return (value);
}
