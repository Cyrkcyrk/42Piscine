/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 13:51:12 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/27 14:18:13 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
	if (*root == NULL)
	{
		*root = btree_create_node(item);
		return ;
	}
	if ((*cmpf)(item, (*root)->item) > 0)
		btree_insert_data(&((*root)->right));
	else
		btree_insert_data(&((*root)->left));
}
