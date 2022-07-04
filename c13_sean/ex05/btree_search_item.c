/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:15:03 by schuah            #+#    #+#             */
/*   Updated: 2022/06/08 19:23:30 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	int	diff;

	if (root == NULL)
		return (NULL);
	diff = (*cmpf)(data_ref, root);
	if (diff == 0)
		return (root->item);
	else if (diff < 0)
		btree_serach_item(root->left, data_ref, cmpf);
	else if (diff > 0)
		btree_search_item(root->right, data_ref, cmpf);
	return (NULL);
}
