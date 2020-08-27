/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 15:26:56 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/26 15:41:05 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

void btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	(*applyf)(root->item);
	if (root->left != 0)
		btree_apply_prefix(root->left, applyf);
	if (root->right != 0)
		btree_apply_prefix(root->right, applyf);
}
