/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:59:24 by schuah            #+#    #+#             */
/*   Updated: 2022/06/08 21:32:39 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	bigger(int nb1, int nb2)
{
	if (nb1 > nb2)
		return (nb1);
	return (nb2);
}

int	btree_level_count(t_btree *root)
{
	int	count;

	count = 0;
	if (root == 0)
		return (0);
	if (root->left != NULL)
		count = bigger(count, btree_level_count(root->left));
	if (root->right != NULL)
		count = bigger(count, btree_level_count(root->right));
	return (count + 1);
}
