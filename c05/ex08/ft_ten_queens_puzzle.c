/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 19:47:58 by wxuerui           #+#    #+#             */
/*   Updated: 2022/05/30 10:18:54 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	check_valid(int table[10], int col, int row)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (row == table[i])
			return (0);
		if (i + table[i] == col + row)
			return (0);
		if (i - table[i] == col - row)
			return (0);
		i++;
	}
	return (1);
}

void	solve(int table[10], int *solutions, int pos)
{
	int	i;
	int	try_num;

	i = 0;
	try_num = 0;
	if (pos == 10)
	{
		*solutions += 1;
		while (i < 10)
		{
			ft_putchar(table[i] + 48);
			i++;
		}
		ft_putchar('\n');
		return ;
	}
	while (try_num < 10)
	{
		if (check_valid(table, pos, try_num))
		{
			table[pos] = try_num;
			solve(table, solutions, pos + 1);
		}
		try_num++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	table[10];
	int	i;
	int	solutions;

	i = 0;
	while (i < 10)
	{
		table[i] = -1;
		i++;
	}
	solutions = 0;
	solve(table, &solutions, 0);
	return (solutions);
}
