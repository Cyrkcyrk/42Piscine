/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 22:36:29 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/21 15:54:22 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_str_lilo(char *str, int size, char next_char)
{
	int i;

	i = -1;
	while (++i < size - 1)
		str[i] = str[i + 1];
	str[size - 1] = next_char;
	return (str);
}

char	*ft_empty_buffer(char *buff, int size)
{
	int i;

	i = -1;
	while (++i < size)
		buff[i] = '\0';
	return (buff);
}

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return (1);
		i++;
	}
	return (0);
}
