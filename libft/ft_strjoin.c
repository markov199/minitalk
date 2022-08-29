/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:52:58 by mkovoor           #+#    #+#             */
/*   Updated: 2022/02/02 14:31:30 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*string;
	int				j;

	if (!s1 || !s2)
		return (NULL);
	j = 0;
	string = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof (char) + 1);
	if (string == NULL)
		return (NULL);
	while (*s1)
	{
		string[j] = *s1;
		j ++;
		s1 ++;
	}
	while (*s2)
	{
		string[j] = *s2;
		j ++;
		s2 ++;
	}
	string[j] = '\0';
	return (string);
}
