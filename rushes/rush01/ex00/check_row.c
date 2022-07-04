/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_row.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:51:49 by wxuerui           #+#    #+#             */
/*   Updated: 2022/05/29 15:58:10 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_rowleft(int rowleft, int **tab, int row)
{
	int	pivot;
	int	i;
	int	see;

	i = 0;
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
	return (1);
}

int	check_rowright(int rowright, int **tab, int row)
{
	int	pivot;
	int	i;
	int	j;
	int	see;

	i = 3;
	j = 0;
	see = 1;
	pivot = tab[i][row];
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

int	check_row(int rowleft, int rowright, int **tab, int row)
{
	if (!check_rowleft(rowleft, tab, row))
		return (0);
	if (!check_rowright(rowright, tab, row))
		return (0);
	return (1);
}
