/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:24:26 by schuah            #+#    #+#             */
/*   Updated: 2022/06/07 20:26:49 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*elem1;
	t_list	*elem2;
	int		index;

	index = 1;
	if (size <= 0)
		return (0);
	elem1 = ft_create_elem(strs[0]);
	while (index < size)
	{
		elem2 = ft_create_elem(strs[index]);
		elem2->next = elem1;
		elem1 = elem2;
	}
	return (elem1);
}
