/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:31:07 by wxuerui           #+#    #+#             */
/*   Updated: 2022/05/22 11:04:22 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_greater(int n, const int *arr)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (i < n - 1)
		{
			if (arr[i] < arr[i + 1])
			{
				i++;
			}
			else
			{
				return (0);
			}
		}	
		else
		{
			break ;
		}
	}
	return (1);
}

int	adding(int *arr, int i)
{
	while (i >= 0)
	{
		if (arr[i] == 9)
		{
			arr[i] -= 9;
			i--;
		}
		else
		{
			arr[i]++;
			return (42);
		}
	}
	return (42);
}

int	check_last(int n, const int *arr)
{
	int	i;

	i = 0;
	if (arr[0] == 10 - n)
	{
		while (i < n - 1)
		{
			if (arr[i] + 1 == arr[i + 1])
			{
				i++;
			}
			else
			{
				return (0);
			}
		}
		return (1);
	}
	return (0);
}

int	print(int n, const int *arr)
{
	int		i;
	char	c;

	i = 0;
	while (i < n)
	{
		c = arr[i] + 48;
		write(1, &c, 1);
		i++;
	}
	if (check_last(n, arr))
	{
		return (0);
	}
	write(1, ", ", 2);
	return (1);
}

void	ft_print_combn(int n)
{
	int	arr[10];
	int	i;

	if (n > 0 && n < 10)
	{
		if (n == 1)
		{
			write(1, "0, 1, 2, 3, 4, 5, 6, 7, 8, 9", 28);
			return ;
		}
		i = 0;
		while (i < 10)
		{
			arr[i] = i;
			i++;
		}
		i = n - 1;
		while (arr[0] <= 10 - n)
		{
			if (check_greater(n, arr))
				(print(n, arr));
			adding(arr, i);
		}
	}
}
