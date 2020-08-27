/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_dict.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 17:13:24 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/23 20:21:57 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_DICT_H
# define FT_PARSE_DICT_H

# include "structs.h"

void	ft_free_dict(t_key *tab);
t_key	*ft_parse_dict(char *path);

#endif
