/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:04:52 by schuah            #+#    #+#             */
/*   Updated: 2022/06/08 15:19:39 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_swap(t_list *list)
{
	void	*temp;

	temp = list->data;
	list->data = list->next->data;
	list->next->data = temp;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*index;
	t_list	*node2;

	index = *begin_list;
	while (index != NULL)
	{
		node2 = *begin_list;
		while (node2->next != NULL)
		{
			if ((*cmp)(node2->data, node2->next->data) > 0)
				ft_swap(node2);
			node2 = node2->next;
		}
		index = index->next;
	}
}
