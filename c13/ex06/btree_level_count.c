/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:05:08 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/27 15:08:44 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int btree_level_count_left(t_btree *root)
{
	if (root->left == 0)
		return (1);
	return (1 + btree_level_count_left(root->left));
}

int btree_level_count_right(t_btree *root)
{
	if (root->right == 0)
		return (1);
	return (1 + btree_level_count_right(root->right));
}

int btree_level_count(t_btree *root)
{
	int right;
	int left;

	left = btree_level_count_left(root);
	right = btree_level_count_right(root);
	if (left > right)
		return (left);
	return (right);
}
