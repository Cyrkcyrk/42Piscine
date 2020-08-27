/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_node.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 18:30:33 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/25 18:34:58 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STR_NODE_H
# define FT_STR_NODE_H

typedef struct	s_str_node
{
	struct s_str_node	*next;
	char				c;
}				t_str_node;

#endif
