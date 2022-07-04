/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clun-ren <clun-ren@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 10:22:46 by clun-ren          #+#    #+#             */
/*   Updated: 2022/05/22 15:59:07 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	rush(int x, int y);

int	main(int argc, char *argv[])
{
	int	col;
	int	row;
	int	i;

	col = 0;
	row = 0;
	i = 0;
	if (argc == 3)
	{
		while (argv[1][i] != 0)
		{
			col *= 10;
			col += argv[1][i] - '0';
			i++;
		}
		i = 0;
		while (argv[2][i] != 0)
		{
			row *= 10;
			row += argv[2][i] - '0';
			i++;
		}
		rush(col, row);
	}
}
