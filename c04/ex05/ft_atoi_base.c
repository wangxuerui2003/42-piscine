/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:00:24 by wxuerui           #+#    #+#             */
/*   Updated: 2022/05/30 20:15:04 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

int	check_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (i < ft_strlen(base))
	{
		j = i;
		while (++j < ft_strlen(base))
			if (base[i] == base[j])
				return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

void	ft_changenbr_base(char *nbr, char *base, int *result)
{
	int	base_num;
	int	i;
	int	j;

	base_num = ft_strlen(base);
	i = 0;
	j = 0;
	while (nbr[i])
	{
		while (nbr[i] != base[j] && base[j])
				j++;
		*result *= base_num;
		*result += j;
		j = 0;
		i++;
	}	
}

int	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	if (c == '\f' || c == '\v' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		neg;
	int		result;

	i = 0;
	neg = 1;
	result = 0;
	if (check_valid(base))
	{
		while (is_space(str[i]))
			i++;
		while (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				neg *= -1;
			i++;
		}
	}
	ft_changenbr_base(str + i, base, &result);
	return (neg * result);
}
