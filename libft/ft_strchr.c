/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:23:33 by mkovoor           #+#    #+#             */
/*   Updated: 2022/01/26 12:54:39 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	int		i;

	i = 0;
	ch = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == ch)
			break ;
		i++;
	}
	if (s[i] == '\0' && ch != '\0')
		return (0);
	return ((char *)&s[i]);
}
