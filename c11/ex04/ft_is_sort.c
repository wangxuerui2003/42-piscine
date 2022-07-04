/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:52:02 by wxuerui           #+#    #+#             */
/*   Updated: 2022/06/06 18:51:42 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	order;

	i = 1;
	order = 0;
	if (length == 0 || length == 1)
		return (1);
	while (i < length)
	{
		if (f(tab[i - 1], tab[i]) > 0)
		{
			if (order == 1)
				return (0);
			order = -1;
		}
		else if (f(tab[i - 1], tab[i]) < 0)
		{
			if (order == -1)
				return (0);
			order = 1;
		}
		i++;
	}
	return (1);
}
