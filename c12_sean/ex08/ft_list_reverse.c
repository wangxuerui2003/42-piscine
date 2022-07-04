/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 22:20:43 by schuah            #+#    #+#             */
/*   Updated: 2022/06/07 22:45:08 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*push;

	if (*begin_list != NULL)
	{
		push = ft_create_elem(data);
		push->next = *begin_list;
		*begin_list = push;
	}
	else
		*begin_list = ft_create_elem(data);
}

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*previous;
	t_list	*next;
	t_list	*current;

	previous = NULL;
	if (*begin_list != NULL)
	{
		current = *begin_list;
		while (current != NULL)
		{
			next = current->next;
			current->next = previous;
			previous = current;
			current = next;
		}
		*begin_list = previous;
	}
}
