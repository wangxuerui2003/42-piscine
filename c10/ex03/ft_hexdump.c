/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:12:17 by wxuerui           #+#    #+#             */
/*   Updated: 2022/06/07 17:37:28 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

int	main(int ac, char **av)
{
	if (ac < 2)
		stdin_loop(0);
	if (ac == 2 && !ft_strcmp(av[1], "-C"))
		c_stdin_loop(0);
	if (ac > 1 && !ft_strcmp(av[1], "-C"))
	{
		if (!c_option(ac, av, 0, 1))
			return (1);
	}
	else
	{
		if (!default_option(ac, av, 0, 0))
			return (1);
	}
	return (0);
}
