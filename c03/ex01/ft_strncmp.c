/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:43:24 by wxuerui           #+#    #+#             */
/*   Updated: 2022/05/26 11:19:16 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	c;
	unsigned int	cmp;

	c = 0;
	cmp = 0;
	while (!cmp && (c < n) && (s1[c] != '\0') && (s2[c] != '\0'))
	{
		cmp = s1[c] - s2[c];
		c++;
	}
	if (!cmp && c < n && (s1[c] == '\0' || s2[c] == '\0'))
		cmp = s1[c] - s2[c];
	return (cmp);
}
