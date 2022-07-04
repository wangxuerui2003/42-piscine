/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 22:14:47 by schuah            #+#    #+#             */
/*   Updated: 2022/06/07 22:18:19 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_lst, unsigned int nbr)
{
	unsigned int	index;

	index = 0;
	while (begin_list != NULL)
	{
		if (index == nbr)
			return (begin_list);
		begin_list = begin_list->next;
		index++;
	}
	return (NULL);
}
