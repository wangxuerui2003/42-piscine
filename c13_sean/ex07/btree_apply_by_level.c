/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 21:35:17 by schuah            #+#    #+#             */
/*   Updated: 2022/06/08 22:21:38 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	ft_btree_level_count(t_btree *root)
{
	int		count;

	count = 0;
	if (root == 0)
		return (0);
	if (root->left)
		count = ft_max(count, ft_btree_level_count(root->left));
	if (root->right)
		count = ft_max(count, ft_btree_level_count(root->right));
	return (count + 1);
}

void	btree_apply(t_btree *root, int current_level, int *levels,
		void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int	is_first_item;

	is_first_item = 1;
	if (levels[current_level] == 1)
		is_first_item = 0;
	else
		levels[current_level] = 1;
	applyf(root->left, current_level, is_first_item);
	if (root->left)
		btree_apply(root->left, current_level + 1, levels, applyf);
	if (root->right)
		btree_apply(root->right, current_level + 1, levels, apply);
}

void	btree_apply_by_level(t_btree *root,
		void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int	count;
	int	index;
	int	*levels;

	if (root == NULL)
		return ;
	count = ft_btree_level_count(root);
	levels = malloc(sizeof(int) * count);
	if (levels == NULL)
		return (NULL);
	index = 0;
	while (index < count)
		levels[index++] = 0;
	btree_apply(root, 0, levels, applyf);
	return ;
}
