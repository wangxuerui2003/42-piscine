/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 11:06:19 by wxuerui           #+#    #+#             */
/*   Updated: 2022/05/29 20:03:02 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	check_valid_put(int **tab, int *index, int pos, int num)
{
	int	i;
	int	row;
	int	col;

	i = -1;
	row = pos / 4;
	col = pos % 4;
	while (++i < row)
		if (tab[col][i] == num)
			return (0);
	i = -1;
	while (++i < col)
		if (tab[i][row] == num)
			return (0);
	if (col == 3)
		if (!check_row(index[row + 8], index[row + 12], tab, row))
			return (0);
	if (row == 3)
		if (!check_col(index[col], index[col + 4], tab, col))
			return (0);
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
