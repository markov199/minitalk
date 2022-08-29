/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:30:45 by mkovoor           #+#    #+#             */
/*   Updated: 2022/06/13 14:32:43 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_s(char *str)
{
	int	length;

	length = 0;
	if (str == NULL)
		length += write (1, "(null)", 6);
	else
		while (*str)
			length += write(1, str++, 1);
	return (length);
}
