/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:28:49 by wxuerui           #+#    #+#             */
/*   Updated: 2022/06/08 21:47:18 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

void	ft_puttitle(char *filename)
{
	ft_putstr("==> ");
	ft_putstr(basename(filename));
	ft_putstr(" <==\n");
}

int	ft_atoi(char *nbr)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (nbr[i])
	{
		if (!(nbr[i] >= '0' && nbr[i] <= '9'))
			return (-1);
		num *= 10;
		num += nbr[i] - '0';
		i++;
	}
	return (num);
}

void	print_help_err(char *exe)
{
	ft_putstr(exe);
	ft_putstr(": option requires an argument -- c\nusage: ft_tail");
	ft_putstr(" [-F | -f | -r] [-q] [-b # | -c # | -n #] [file ...]\n");
}

void	print_illegal_err(char *exe, char *file)
{
	ft_putstr(exe);
	ft_putstr(": illegal offset -- ");
	ft_putstr(basename(file));
	ft_putstr("\n");
}

int	ft_catoi(char *nbr)
{
	int	i;
	int	num;

	i = 2;
	num = 0;
	if (ft_strlen(nbr) <= 2)
		return (-1);
	while (nbr[i])
	{
		if (nbr[i] == ' ' || nbr[i] == '\n' || nbr[i] == '\t')
		{
			i++;
			continue ;
		}
		if (!(nbr[i] >= '0' && nbr[i] <= '9'))
			return (-1);
		num *= 10;
		num += nbr[i] - '0';
		i++;
	}
	return (num);
}
