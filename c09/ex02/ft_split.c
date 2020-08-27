/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 15:16:45 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/14 16:20:23 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_charset(char c, char *charset)
{
	int i;

	i = -1;
	while (charset[++i] != '\0')
		if (c == charset[i])
			return (1);
	return (0);
}

int		ft_count_word(char *str, char *seps)
{
	int i;
	int	count;

	count = 0;
	i = 0;
	while (str[++i])
		if (ft_is_charset(str[i], seps) && !ft_is_charset(str[i - 1], seps))
			count++;
	if (!ft_is_charset(str[i - 1], seps))
		count++;
	return (count);
}

char	*ft_create_word(char *str, char *charset, int *len)
{
	int		i;
	char	*ret;
	int		wordlen;

	wordlen = 0;
	while (str[wordlen] != '\0' && !(ft_is_charset(str[wordlen], charset)))
		wordlen += 1;
	*len = wordlen;
	if (wordlen == 0)
		return ("");
	ret = malloc((wordlen + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	ret[wordlen] = '\0';
	i = -1;
	while (++i < wordlen)
		ret[i] = str[i];
	return (ret);
}

char	**ft_fill_tab(char *str, char *charset, char **ret)
{
	int		word;
	int		len;

	word = 0;
	while (*str != '\0')
	{
		ret[word] = ft_create_word(str, charset, &len);
		if (ret[word] == NULL)
			return (NULL);
		if (len > 0)
			word++;
		str += len;
		if (*str != '\0')
			str++;
	}
	return (ret);
}

char	**ft_split(char *str, char *charset)
{
	int		wordcount;
	char	**ret;
	int		len_str;

	len_str = 0;
	while (str[len_str])
		len_str++;
	if (len_str == 0)
	{
		ret = malloc(sizeof(char*));
		ret[0] = NULL;
		return (ret);
	}
	wordcount = ft_count_word(str, charset);
	ret = malloc((wordcount + 1) * sizeof(char*));
	if (ret == NULL)
		return (NULL);
	ret = ft_fill_tab(str, charset, ret);
	if (ret == NULL)
		return (NULL);
	ret[wordcount] = NULL;
	return (ret);
}
