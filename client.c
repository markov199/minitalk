/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:38:10 by mkovoor           #+#    #+#             */
/*   Updated: 2022/06/16 17:37:30 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<signal.h>
#include"libft/libft.h"

int		ft_msg_to_bin(char *msg, int pid);
int		ft_valid_pid(char *str);

int	main(int ac, char *av[])
{
	pid_t	pid;

	if (ac != 3)
	{
		write(1, "Error: wrong number of arguments", 32);
		return (-1);
	}
	if (ac == 3)
	{	
		if (ft_valid_pid(av[1]) == -1)
			return (-1);
		pid = ft_atoi(av[1]);
		if (ft_msg_to_bin(av[2], pid) == -1)
		{
			write (1, "Unexpected Error!!", 18);
		}
		return (0);
	}
	return (-1);
}

int	ft_msg_to_bin(char *msg, int pid)
{
	int	bitshift;
	int	i;

	bitshift = -1;
	i = -1;
	while (msg[++bitshift / 8])
	{
		if (msg[bitshift / 8] & 128 >> (bitshift % 8))
		{
			if (kill (pid, SIGUSR1) == -1)
				return (-1);
		}
		else
		{
			if (kill (pid, SIGUSR2) == -1)
				return (-1);
		}
		usleep (500);
	}
	return (0);
}

int	ft_valid_pid(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			write (1, "not a valid PID", 15);
			return (-1);
		}
		i++;
	}
	return (0);
}
