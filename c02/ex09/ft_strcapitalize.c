/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:21:34 by wxuerui           #+#    #+#             */
/*   Updated: 2022/05/24 18:15:48 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_lowercase(char *str)
{
	if (!(*str >= 'a' && *str <= 'z'))
		return (0);
	return (1);
}

int	is_alpha(char *str)
{
	if (!(*str >= 'A' && *str <= 'Z') && !(*str >= 'a' && *str <= 'z'))
		return (0);
	return (1);
}

int	is_numeric(char *str)
{
	if (!(*str >= '0' && *str <= '9'))
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (i == 0 || !(is_alpha(str + i - 1) || is_numeric(str + i - 1)))
		{
			if (is_lowercase(str + i))
				str[i] -= 32;
		}
		else if (is_alpha(str + i))
		{
			if (!is_lowercase(str + i))
				str[i] += 32;
		}
		i++;
	}
	return (str);
}
