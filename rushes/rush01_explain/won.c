/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   won.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 11:14:05 by wxuerui           #+#    #+#             */
/*   Updated: 2022/05/29 14:27:58 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	check_row(int rowleft, int rowright, int **tab, int row)
{
	int	pivot;
	int	i;
	int	j;
	int	see;

	i = 0;
	j = 0;
	see = 1;
	pivot = tab[i][row];
	while (i < 3)
	{
		if (pivot == tab[i + 1][row])
			return (0);
		if (pivot < tab[i + 1][row])
		{
			see++;
			pivot = tab[i + 1][row];
		}
		i++;
	}
	if (!(see == rowleft))
		return (0);
	pivot = tab[i][row];
	see = 1;
	while (i > 0)
	{
		if (pivot == tab[i - 1][row])
			return (0);
		if (pivot < tab[i - 1][row])
		{
			see++;
			pivot = tab[i - 1][row];
		}
		i--;
	}
	if (!(see == rowright))
		return (0);
	return (1);
}

int	check_col(int colup, int coldown, int **tab, int col)
{
	int	pivot;
	int	i;
	int	see;

	i = 0;
	see = 1;
	pivot = tab[col][i];
	while (i < 3)
	{
		if (pivot == tab[col][i + 1])
			return (0);
		if (pivot < tab[col][i + 1])
		{
			see++;
			pivot = tab[col][i + 1];
		}
		i++;
	}
	if (!(see == colup))
		return (0);
	pivot = tab[col][i];
	see = 1;
	while (i > 0)
	{
		if (pivot == tab[col][i - 1])
			return (0);
		if (pivot < tab[col][i - 1])
		{
			see++;
			pivot = tab[col][i - 1];
		}
		i--;
	}
	if (!(see == coldown))
		return (0);
	return (1);
}

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
