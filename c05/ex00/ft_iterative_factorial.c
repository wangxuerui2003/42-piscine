/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 08:52:29 by wxuerui           #+#    #+#             */
/*   Updated: 2022/05/26 08:59:24 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;

	result = 1;
	if (nb >= 0)
	{
		if (nb == 0)
			return (result);
		result *= nb;
		while (nb > 1)
		{
			result *= nb -1;
			nb--;
		}
		return (result);
	}
	return (0);
}
