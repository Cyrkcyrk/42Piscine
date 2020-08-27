/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 12:31:46 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/10 22:25:33 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] - 'A' + 'a';
		}
		i++;
	}
	return (str);
}

int		ft_is_alphanum(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

char	ft_capitalize(char c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 'a' + 'A';
	return (c);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	str = ft_strlowcase(str);
	if (ft_is_alphanum(str[0]))
		str[0] = ft_capitalize(str[0]);
	i = 1;
	while (str[i] != '\0')
	{
		if (!ft_is_alphanum(str[i - 1]))
			str[i] = ft_capitalize(str[i]);
		i++;
	}
	return (str);
}
