/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:46:58 by mkovoor           #+#    #+#             */
/*   Updated: 2022/02/01 10:39:36 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (*(src + i) && i < dstsize)
		{
			*(dst + i) = *(src + i);
			i++;
		}
		if (i == dstsize)
			i--;
		*(dst + i) = '\0';
	}
	return (ft_strlen(src));
}
