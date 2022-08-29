/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:33:23 by mkovoor           #+#    #+#             */
/*   Updated: 2022/06/16 17:35:43 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	sh1(int sig)
{
	static int		bits;
	static char		c;

	if (sig == SIGUSR1)
		c = c | (128 >> bits);
	bits++;
	if (bits == 8)
	{
		write (1, &c, 1);
		bits = 0;
		c = 0;
	}	
}

int	main(void)
{
	pid_t	pid;

	signal(SIGUSR1, sh1);
	signal(SIGUSR2, sh1);
	pid = getpid();
	ft_printf("PID %d\n", pid);
	while (1)
	{		
		pause();
	}	
	return (0);
}
