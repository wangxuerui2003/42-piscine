/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_col.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:00:23 by wxuerui           #+#    #+#             */
/*   Updated: 2022/05/29 16:06:00 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_colup(int colup, int **tab, int col)
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
	return (1);
}

int	check_coldown(int coldown, int **tab, int col)
{
	int	pivot;
	int	i;
	int	see;

	i = 3;
	see = 1;
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

int	check_col(int colup, int coldown, int **tab, int col)
{
	if (!check_colup(colup, tab, col))
		return (0);
	if (!check_coldown(coldown, tab, col))
		return (0);
	return (1);
}
