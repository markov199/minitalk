/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:26:11 by mkovoor           #+#    #+#             */
/*   Updated: 2022/06/13 15:00:08 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(char ch)
{
	if (ch == ' ' || ch == '\f' || ch == '\n' || ch == '\r'
		|| ch == '\t' || ch == '\v')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int				sign;
	unsigned long	num;
	int				i;

	i = 0;
	sign = 1;
	num = 0;
	while (ft_isspace(str[i]))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = str[i] - '0' + (num * 10);
		i++;
	}
	if ((num) > 2147483647 && sign == 1)
		return (-1);
	if (num > 2147483648 && sign == -1)
		return (0);
	return (num * sign);
}
