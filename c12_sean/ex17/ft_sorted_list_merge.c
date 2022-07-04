/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:37:25 by schuah            #+#    #+#             */
/*   Updated: 2022/06/08 15:22:58 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*list1;

	list1 = *begin_list1;
	while (list1->next != NULL)
		list1 = list1->next;
	list1->next = begin_list2;
}

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

void	ft_sorted_list_merge(t_list **begin_list1,
		t_list *begin_list2, int (*cmp)())
{
	ft_list_merge(begin_list1, begin_list2);
	ft_list_sort(begin_list1, cmp);
}
