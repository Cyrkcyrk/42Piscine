/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 22:00:12 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/10 22:00:29 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_is_base_valid_and_length(char *str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = 1;
		while (str[i + j] != '-' && str[i + j] != '+' && str[i + j] != '\t' &&
				str[i + j] != '\n' && str[i + j] != '\v' && str[i + j] != '\f'
				&& str[i + j] != '\r' && str[i + j] != ' ' &&
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

int			ft_is_char_in_base(char c, char *base)
{
	int i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (1);
		i++;
	}
	return (0);
}

long		ft_power_of_base(char c, int pow, char *base, int len)
{
	int		i;
	long	power;

	power = 1;
	i = 0;
	while (i++ < pow)
		power = power * len;
	i = 0;
	while (c != base[i])
		i++;
	return (i * power);
}

int			ft_atoi_base(char *str, char *base)
{
	int		i;
	int		j;
	int		neg;
	long	value;
	int		len;

	if ((len = ft_is_base_valid_and_length(base)) == 0)
		return (0);
	neg = 1;
	value = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	while ((*str == '+' || *str == '-') && str++ - 1)
		if (*(str - 1) == '-')
			neg = -neg;
	i = 0;
	j = 0;
	while (ft_is_char_in_base(str[i], base))
		i++;
	while (j++ < i)
		value = value + ft_power_of_base(str[i - j], j - 1, base, len);
	if (neg * value > 2147483647 || neg * value < -2147483648)
		return (0);
	return (int)(neg * value);
}

#include <stdio.h>

int main(int ac, char** av)
{
	int i;
	char tab[][3] = {"42", "6f", "6e", "6a", "6f", "75", "72", "20", "6c", "65", "73", "20", "61", "6d", "69", "6e", "63", "68", "65", "73", "09", "0a", "09", "63", "20", "20", "65", "73", "74", "20", "66", "6f", "75", "09", "74", "6f", "75", "74", "09", "63", "65", "20", "71", "75", "20", "6f", "6e", "20", "70", "65", "75", "74", "20", "66", "61", "69", "72", "65", "20", "61", "76", "65", "63", "09", "0a", "09", "70", "72", "69", "6e", "74", "5f", "6d", "65", "6d", "6f", "72", "79", "0a", "0a", "0a", "09", "6c", "6f", "6c", "2e", "6c", "6f", "6c", "0a", "20", "00"};
	
	i = -1;
	while (i++ < 92)
		printf("%c", ft_atoi_base(tab[i], "0123456789abcdef"));
	return 0;
}
