/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 22:00:12 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/14 12:19:17 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
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

	len = ft_strlen(base);
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
