/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:03:44 by schuah            #+#    #+#             */
/*   Updated: 2022/06/08 19:08:50 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,
		int (*cmpf)(void *, void *))
{
	t_btree	*tree;

	if (root == NULL || *root == NULL || item == NULL)
	{
		if (item != NULL && root != NULL)
			*root = btree_create_node(item);
		return ;
	}
	tree = *root;
	if ((*cmpf)(item, (*root)->item) < 0)
	{
		if (tree->left != NULL)
			btree_insert_data(&tree->left, item, cmpf);
		else
			tree->left = btree_create_node(item);
	}
	else
	{
		if (tree->right)
			btree_insert_data(&tree->right, item, cmpf);
		else
			tree->right = btree_create_node(item);
	}
}
