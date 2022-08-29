/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:52:55 by mkovoor           #+#    #+#             */
/*   Updated: 2022/06/13 14:32:33 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_d(int nbr)
{
	char	c;
	int		length;

	length = 0;
	if (nbr == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			length += write(1, "-", 1);
		}
		c = ((nbr % 10) + '0');
		if (nbr > 9)
		{
			nbr = nbr / 10;
			length += ft_printf_d(nbr);
		}
		length += write(1, &c, 1);
		return (length);
	}
}
