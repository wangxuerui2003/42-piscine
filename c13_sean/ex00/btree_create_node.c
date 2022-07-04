/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:04:44 by schuah            #+#    #+#             */
/*   Updated: 2022/06/08 16:07:01 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_btree	*btree_create_node(void *item)
{
	t_btree	*branch;

	branch = malloc(sizeof(t_btree));
	if (branch == NULL)
		return (NULL);
	branch->left = NULL;
	branch->right = NULL;
	branch->item = item;
	return (branch);
}
