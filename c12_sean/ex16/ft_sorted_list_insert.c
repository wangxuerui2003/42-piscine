/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:29:52 by schuah            #+#    #+#             */
/*   Updated: 2022/06/08 15:22:29 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*temp;

	temp = *begin_list;
	if (temp != NULL)
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*node1;
	t_list	*node2;
	t_list	*next;

	ft_list_push_back(begin_list, data);
	node1 = *begin_list;
	while (node1 != NULL)
	{
		node2 = *begin_list;
		while (node2->next != NULL)
		{
			if ((*cmp)(node2->data, node2->next->data) > 0)
			{
				next = node2->data;
				node2->data = node2->next->data;
				node2->next->data = next;
			}
			node2 = node2->next;
		}
		node1 = node1->next;
	}
}
