/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:16:50 by mkovoor           #+#    #+#             */
/*   Updated: 2022/02/08 14:32:44 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	char	*sub;

	j = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	sub = (char *) malloc (sizeof (char) * len + 1);
	if (sub == NULL)
		return (0);
	while (j < len)
	{
		sub[j] = s[j + start];
		j++;
	}
	sub[j] = '\0';
	return (sub);
}

//returns substring from INDEX 'start' with length 'len'
// checks for null string.
//checks for validity of start.
// checks for validity of len...should stop at end of string
// return null terminated substring (sub) always 
//except when string is null pointer