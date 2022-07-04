/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:40:40 by wxuerui           #+#    #+#             */
/*   Updated: 2022/05/29 14:42:51 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "solve.c"
#include "tabulate.c"
#include "won.c"

void	print_error(int **tab, int *index)
{
	write(1, "Error\n", 6);
	free(index);
	free(tab);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;
	int	**tab;
	int	*index;

	i = 0;
	j = 0;
	index = malloc(4 * 16);
	tab = malloc(8 * 4);
	while (i < 4)
	{
		tab[i] = malloc(4 * 4);
		i++;
	}
	i = 0;
	if (argc == 2)
	{
		while (i < 32)
		{
			if (argv[1][i] >= '0' && argv[1][i] <= '9')
			{
				index[j] = argv[1][i] - '0';
				i += 2;
				j++;
			}
			else
			{
				print_error(tab, index);
				return (1);
			}
		}
		i = 0;
		while (i < 12)
		{
			if (index[i] + index[i + 4] > 5 || index[i] + index[i + 4] < 3)
			{
				print_error(tab, index);
				return (1);
			}
			i++;
			if (i == 4)
				i = 8;
		}
		tabulate(tab);
		if (solve(tab, index, 0) == -1)
		{
			print_error(tab, index);
			return (1);
		}	
		for (int k = 0; k < 4; k++)
		{
			for (int l = 0; l < 4; l++)
			{
				printf("%d ", tab[l][k]);
			}
			printf("\n");
		}
	}
	free(index);
	free(tab);
	return (0);
}
