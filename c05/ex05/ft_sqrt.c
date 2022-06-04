/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 09:27:25 by wxuerui           #+#    #+#             */
/*   Updated: 2022/06/01 15:45:17 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	sqrt;

	sqrt = 1;
	if (nb <= 0)
		return (0);
	if (nb > 2147395600)
		return (0);
	while ((sqrt * sqrt) < nb)
		sqrt++;
	if ((sqrt * sqrt) == nb)
		return (sqrt);
	else
		return (0);
}
