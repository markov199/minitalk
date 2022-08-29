/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:37:16 by mkovoor           #+#    #+#             */
/*   Updated: 2022/06/21 12:38:23 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<signal.h>
#include "libft/libft.h"
#include<stdio.h>


void	sh1(int sig, siginfo_t *info, void *context)
{
	static int		bits;
	static char		c;
	static	int		pid_client;

	(void)context;
	if (pid_client == 0)
		pid_client = info->si_pid;
	else if (pid_client != 0 && pid_client != info->si_pid)
	{
		kill(info->si_pid, SIGSTOP);
		return;
	}	
	if (sig == SIGUSR1)
		c = c | (128 >> bits);
	bits++;
	if (bits == 8)
	{
		if (c != '\0')
			write (1, &c, 1);
		else
		{
			kill (pid_client, SIGUSR1);
			pid_client = 0;
		}
		bits = 0;
		c = 0;
	}	
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sig;
	sigset_t			sig_block;

	sigemptyset (&sig_block);
	sigaddset(&sig_block, SIGQUIT);
	sig.sa_handler = 0;
	sig.sa_flags = SA_SIGINFO;
	sig.sa_mask = sig_block;
	sig.sa_sigaction = sh1;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	
	pid = getpid();
	ft_printf("PID %d\n", pid);
	while (1)
	{		
		pause();
	}	
	return (0);
}
