/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:42:21 by mkovoor           #+#    #+#             */
/*   Updated: 2022/02/14 14:07:07 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_getdigits(int x)
{
	int	i;

	i = 0;
	if (x < 0)
	{
		i++;
		x = x * -1;
	}
	while (x >= 10)
	{
		i++;
		x = x / 10;
	}
	i++;
	return (i);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		j;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	j = ft_getdigits(n);
	i = j;
	s = malloc (sizeof(char) * j + 1);
	if (!s)
		return (0);
	if (n < 0)
	{
		n *= -1;
		s[0] = '-';
	}
	while (n > 0)
	{
		s[--j] = ((n % 10) + '0');
		n = n / 10;
	}
	s[i] = '\0';
	return (s);
}
