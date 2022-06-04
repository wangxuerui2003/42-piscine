/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:30:25 by wxuerui           #+#    #+#             */
/*   Updated: 2022/06/03 10:47:20 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	ft_generate_result(long nbr, char *base, char *res, int neg);
char	*ft_dec_to_base(long nbr, char *base, int neg);
int		get_len(long nbr, int size, int neg);
int		ft_strlen(char *str);
int		in_base(char c, char *base);
int		ft_atob(char *nbr, char *base);

int	get_len(long nbr, int size, int neg)
{
	int	i;

	i = 0;
	if (neg == -1)
		i++;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= size;
		i++;
	}
	return (i);
}

char	*ft_dec_to_base(long nbr, char *base, int neg)
{
	char	*res;
	int		size;
	int		len;

	size = ft_strlen(base);
	len = get_len(nbr, size, neg);
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	ft_generate_result(nbr, base, res, neg);
	res[len] = '\0';
	return (res);
}

void	ft_generate_result(long nbr, char *base, char *res, int neg)
{
	int		i;
	int		size;

	i = 0;
	size = get_len(nbr, ft_strlen(base), neg);
	if (neg == -1)
		res[0] = '-';
	if (nbr == 0)
	{
		res[0] = base[0];
		res[1] = '\0';
	}
	while (nbr > 0)
	{
		res[(size - i - 1)] = base[nbr % ft_strlen(base)];
		i++;
		nbr /= ft_strlen(base);
	}
}

int	in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != 0)
	{
		if (c == base[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_atob(char *nbr, char *base)
{
	int	i;

	i = 0;
	if (!nbr)
		return (0);
	while (nbr[i] && in_base(nbr[i], base))
		i++;
	if (i == 0)
		return (0);
	while (i < ft_strlen(nbr))
		nbr[i] = 0;
	return (1);
}
