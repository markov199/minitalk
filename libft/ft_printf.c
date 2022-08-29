/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:31:05 by mkovoor           #+#    #+#             */
/*   Updated: 2022/06/13 14:58:34 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_parse(va_list arg, char c, int length)
{
	if (c == 'c')
		length += ft_printf_char (va_arg(arg, int));
	else if (c == 's')
		length += ft_printf_s (va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		length += ft_printf_d (va_arg(arg, int));
	else if (c == 'p')
		length += ft_printf_p (va_arg(arg, unsigned long));
	else if (c == 'x' || c == 'X')
		length += ft_printf_x (va_arg(arg, unsigned int), c);
	else if (c == 'u')
		length += ft_printf_u (va_arg(arg, unsigned int));
	else
		length += ft_printf_char (c);
	return (length);
}

int	ft_printf(const char *str, ...)
{
	va_list	pargs;
	int		length;

	length = 0;
	va_start (pargs, str);
	while (*str)
	{
		if (*str == '%')
			length = ft_parse (pargs, *(++str), length);
		else
			length += write(1, str, 1);
		str++;
	}
	va_end (pargs);
	return (length);
}
