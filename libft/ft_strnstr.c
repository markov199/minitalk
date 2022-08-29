/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:02:23 by mkovoor           #+#    #+#             */
/*   Updated: 2022/02/08 13:44:12 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!*s2)
		return ((char *)s1);
	while (n && s1[i])
	{
		j = 0;
		while ((i + j < n) && s2[j] && s1[i + j] && s1[i + j] == s2[j])
		{
			j++;
		}
		if (!s2[j])
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
// check for null params
// if s2 is an empty string return s1
//if n or s1 empty return NULL
