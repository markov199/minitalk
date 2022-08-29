/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:07:42 by mkovoor           #+#    #+#             */
/*   Updated: 2022/06/13 14:32:38 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_address(unsigned long i)
{
	char				*hexa_str;
	unsigned long		hexa;
	int					length;

	length = 0;
	hexa_str = "0123456789abcdef";
	hexa = i % 16;
	if (i > 15)
	{
		i = i / 16;
		length += ft_printf_address (i);
	}
	length += write(1, &hexa_str[hexa], 1);
	return (length);
}

int	ft_printf_p(unsigned long p)
{
	int	length;

	length = 0;
	length += write(1, "0x", 2);
	length += ft_printf_address(p);
	return (length);
}
