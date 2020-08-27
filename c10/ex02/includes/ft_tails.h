/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tails.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 21:40:00 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/21 15:54:40 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAILS_H
# define FT_TAILS_H

int		ft_atoi(char *str);
int		ft_is_numeric(char *str);

int		ft_strlen(char *str);
char	*ft_str_lilo(char *str, int size, char next_char);
char	*ft_empty_buffer(char *buff, int size);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
#endif
