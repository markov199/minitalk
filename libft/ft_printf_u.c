/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:17:07 by mkovoor           #+#    #+#             */
/*   Updated: 2022/06/13 14:32:47 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_u(unsigned int nbr)
{
	char	c;
	int		length;

	length = 0;
	if (nbr < 0)
		nbr = 4294967296 - nbr;
	c = (nbr % 10) + '0';
	if (nbr > 9)
	{
		nbr = nbr / 10;
		length += ft_printf_u(nbr);
	}
	length += write(1, &c, 1);
	return (length);
}
