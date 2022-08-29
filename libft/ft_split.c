/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:54:39 by mkovoor           #+#    #+#             */
/*   Updated: 2022/02/15 10:33:08 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_strcount(const char *str, char ch)
{
	int	i;
	int	count;
	int	string;

	i = 0;
	count = 0;
	while (str[i])
	{
		string = 0;
		while (str[i] == ch)
			i++;
		while (str[i] != ch && str[i])
		{
			string = 1;
			i++;
		}
		if (string)
			count++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	int			j;
	int			len;
	char		**array;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	array = (char **)malloc(sizeof (char *) * (ft_strcount(s, c) + 1));
	if (array == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		len = 0;
		while (s[i + len] != c && s[i + len])
			len++;
		if (len)
			array[j++] = ft_substr(s, i, len);
		i = i + len;
	}
	array[j] = NULL;
	return (array);
}
