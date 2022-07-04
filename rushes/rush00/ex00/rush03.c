/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clun-ren <clun-ren@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 10:25:45 by clun-ren          #+#    #+#             */
/*   Updated: 2022/05/21 18:59:53 by lpang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_middle(int col, char letter)
{
	while (col-- > 0)
		ft_putchar(letter);
}

void	rush(int x, int y)
{
	int	i;

	i = 0;
	while (i < y && x > 0)
	{
		if (i == 0 || i == y - 1)
		{
			ft_putchar('A');
			print_middle(x - 2, 'B');
			if (x > 1)
				ft_putchar('C');
		}
		else
		{
			ft_putchar('B');
			print_middle(x - 2, ' ');
			if (x > 1)
				ft_putchar('B');
		}
		++i;
		ft_putchar('\n');
	}
}
