/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:12:17 by wxuerui           #+#    #+#             */
/*   Updated: 2022/06/06 13:27:25 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	is_op(char *op)
{
	char	*ops;
	int		i;

	ops = "+-*/%";
	i = 0;
	if (ft_strlen(op) == 1)
	{
		while (ops[i])
		{
			if (op[0] == ops[i])
				return (1);
			i++;
		}
	}
	return (0);
}

int	calc(int a, int b, int (*op)(int, int))
{
	return (op(a, b));
}

int	ft_do_op(int a, char *op, int b)
{
	static int	(*ops[5])(int, int) = {&add, &minus, &mult, &div, &mod};

	if (!is_op(op))
		return (0);
	if (op[0] == '+')
		return (calc(a, b, ops[0]));
	if (op[0] == '-')
		return (calc(a, b, ops[1]));
	if (op[0] == '*')
		return (calc(a, b, ops[2]));
	if (op[0] == '/')
		return (calc(a, b, ops[3]));
	if (op[0] == '%')
		return (calc(a, b, ops[4]));
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		if (!ft_strcmp(av[2], "/") && !ft_atoi(av[3]))
		{
			ft_putstr("Stop : division by zero\n");
			return (1);
		}
		else if (!ft_strcmp(av[2], "%") && !ft_atoi(av[3]))
		{
			ft_putstr("Stop : modulo by zero\n");
			return (1);
		}
		ft_putnbr(ft_do_op(ft_atoi(av[1]), av[2], ft_atoi(av[3])));
		ft_putstr("\n");
	}
	return (0);
}
