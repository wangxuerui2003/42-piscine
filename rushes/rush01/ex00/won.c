/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   won.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 11:14:05 by wxuerui           #+#    #+#             */
/*   Updated: 2022/05/29 16:06:56 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	won(int *index, int **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		if (!check_col(index[i], index[i + 4], tab, i))
			return (0);
		i++;
	}
	while (j < 4)
	{
		if (!check_row(index[j + 8], index[j + 12], tab, j))
			return (0);
		j++;
	}
	return (1);
}
