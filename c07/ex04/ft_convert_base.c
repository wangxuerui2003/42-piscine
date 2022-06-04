/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:00:47 by wxuerui           #+#    #+#             */
/*   Updated: 2022/06/03 10:49:00 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	ft_generate_result(long nbr, char *base, char *res, int neg);
int		get_len(long nbr, int size, int neg);
char	*ft_dec_to_base(long nbr, char *base, int neg);
int		ft_atob(char *nbr, char *base);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
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

long	ft_base_to_dec(char *nbr, char *base)
{
	int		base_num;
	int		i;
	int		j;
	long	result;

	base_num = ft_strlen(base);
	i = 0;
	j = 0;
	result = 0;
	while (nbr[i])
	{
		while (nbr[i] != base[j] && base[j])
				j++;
		result *= base_num;
		result += j;
		j = 0;
		i++;
	}
	return (result);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	if (c == '\f' || c == '\v' || c == '\r')
		return (1);
	return (0);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		i;
	int		neg;
	long	dec_num;

	i = 0;
	neg = 1;
	dec_num = 0;
	if (check_valid(base_from) && check_valid(base_to) && nbr)
	{
		while (is_space(*nbr))
			nbr++;
		while (*nbr == '-' || *nbr == '+')
		{
			if (*nbr == '-')
				neg *= -1;
			nbr++;
		}
		if (ft_atob(nbr, base_from))
		{
			dec_num = ft_base_to_dec(nbr, base_from);
			return (ft_dec_to_base(dec_num, base_to, neg));
		}
	}
	return (NULL);
}
