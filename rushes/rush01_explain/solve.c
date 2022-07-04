/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 11:06:19 by wxuerui           #+#    #+#             */
/*   Updated: 2022/05/29 14:45:31 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdlib.h>
#include <stdio.h>

int	check_valid_put(int **tab, int *index, int pos, int num)
{
	int	i;

	i = -1;
	while (++i < pos / 4)
		if (tab[pos % 4][i] == num)
			return (0);
	i = -1;
	while (++i < pos % 4)
		if (tab[i][pos / 4] == num)
			return (0);	
	if (pos % 4 == 3)
	{
		if (!check_row(index[(pos / 4) + 8], index[(pos / 4) + 12], tab, pos / 4))
			return (0);
	}
	if (pos / 4 == 3)
	{
		if (!check_col(index[pos % 4], index[(pos % 4) + 4], tab, pos % 4))
			return (0);
	}
	return (1);
}

int	solve(int **tab, int *index, int pos)
{
	int	i;
	int	row;
	int	col;

	if (won(index, tab))
		return (1);
	i = 1;
	row = pos / 4;
	col = pos % 4;
	while (i < 5)
	{
		tab[col][row] = i;
		if (won(index, tab))
			return (1);
		if (check_valid_put(tab, index, pos, i) && pos < 15)
		{
			if (solve(tab, index, pos + 1))
				return (1);
		}
		i++;
	}
	if (col == 0 && row == 0)
		return (-1);
	tab[col][row] = 0;
	return (0);
}
