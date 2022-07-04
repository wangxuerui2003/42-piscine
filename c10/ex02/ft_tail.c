/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:35:00 by wxuerui           #+#    #+#             */
/*   Updated: 2022/06/08 20:41:03 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

int	main(int ac, char *av[])
{
	if (ac < 2)
		free_play();
	if (ac == 2 && ft_strcmp(av[1], "-c") == 0)
	{
		print_help_err(basename(av[0]));
		return (1);
	}
	if (!choose_mode(ac, av))
		return (1);
	return (0);
}

int	choose_mode(int ac, char **av)
{
	if (ft_strlen(av[1]) == 2 && ft_strcmp(av[1], "-c") == 0)
	{
		if (ac == 3 && ft_atoi(av[2]) != -1)
			free_play();
		if (ft_atoi(av[2]) == -1)
		{
			print_illegal_err(basename(av[0]), av[2]);
			return (1);
		}
		c_display_mode(av, ac, ft_atoi(av[2]), 2);
	}
	else if (ft_strlen(av[1]) > 2)
	{
		if (ac == 2 && ft_catoi(av[1]) != -1)
			free_play();
		if (ft_catoi(av[1]) == -1)
		{
			print_illegal_err(basename(av[0]), av[1] + 2);
			return (1);
		}
		cnum_display_mode(av, ac, ft_catoi(av[1]), 1);
	}
	else
		return (0);
	return (1);
}
