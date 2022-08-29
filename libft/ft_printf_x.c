/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:40:54 by mkovoor           #+#    #+#             */
/*   Updated: 2022/06/13 14:32:55 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_x(unsigned int i, const char ch)
{
	char			*hexa_str;
	unsigned int	hexa;
	int				length;

	length = 0;
	if (ch == 'x')
		hexa_str = "0123456789abcdef";
	else
		hexa_str = "0123456789ABCDEF";
	hexa = i % 16;
	if (i >= 16)
	{
		i = i / 16;
		length += ft_printf_x (i, ch);
	}
	length += write(1, &hexa_str[hexa], 1);
	return (length);
}
