/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:40:40 by wxuerui           #+#    #+#             */
/*   Updated: 2022/05/29 15:45:24 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "functions.h"

void	print_error(int **tab, int *index)
{
	write(1, "Error\n", 6);
	free(index);
	free(tab);
}

int	gen_index(int **tab, int *index, char *argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 32)
	{
		if (argv[i] >= '0' && argv[i] <= '9')
		{
			index[j] = argv[i] - '0';
			i += 2;
			j++;
		}
		else
		{
			print_error(tab, index);
			return (0);
		}
	}
	return (1);
}

int	check_input(int **tab, int *index)
{
	int	i;

	i = 0;
	while (i < 12)
	{
		if (index[i] + index[i + 4] > 5 || index[i] + index[i + 4] < 3)
		{
			print_error(tab, index);
			return (0);
		}
		i++;
		if (i == 4)
			i = 8;
	}
	return (1);
}

void	print_board(int **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 3)
		{
			putnbr(tab[i][j]);
			write(1, " ", 1);
			j++;
		}
		putnbr(tab[i][j]);
		write(1, "\n", 1);
		j = 0;
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	i;
	int	**tab;
	int	*index;

	i = -1;
	index = malloc(4 * 16);
	tab = malloc(8 * 4);
	while (++i < 4)
		tab[i] = malloc(4 * 4);
	if (argc == 2)
	{
		if (!gen_index(tab, index, argv[1]) || !check_input(tab, index))
			return (1);
		tabulate(tab);
		if (solve(tab, index, 0) == -1)
		{
			print_error(tab, index);
			return (1);
		}	
		print_board(tab);
	}
	free(index);
	free(tab);
	return (0);
}
