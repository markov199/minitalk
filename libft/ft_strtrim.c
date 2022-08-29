/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:39:47 by mkovoor           #+#    #+#             */
/*   Updated: 2022/02/15 10:35:09 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (start < end)
	{
		if (ft_strchr(set, s1[start]))
			start++;
		else
			break ;
	}
	while (end >= start)
	{
		if (ft_strchr(set, s1[end]))
			end--;
		else
			break ;
	}
	return (ft_substr(s1, start, (end - start + 1)));
}
