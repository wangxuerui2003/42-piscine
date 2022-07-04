/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:59:25 by schuah            #+#    #+#             */
/*   Updated: 2022/06/07 14:29:26 by schuah           ###   ########.fr       */
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
