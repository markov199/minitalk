/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:32:04 by mkovoor           #+#    #+#             */
/*   Updated: 2022/02/10 13:01:26 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{	
	char	*mmv_dst;
	char	*mmv_src;

	if ((!dst && !src) || len < 1)
		return (dst);
	mmv_dst = (char *) dst;
	mmv_src = (char *) src;
	if ((mmv_src < mmv_dst) && (mmv_dst < mmv_src + len))
	{
		while (len)
		{
			*(mmv_dst + len - 1) = *(mmv_src + len - 1);
			len--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
