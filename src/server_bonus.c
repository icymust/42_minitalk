/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martinmust <martinmust@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 01:19:28 by martinmust        #+#    #+#             */
/*   Updated: 2025/12/20 00:43:59 by martinmust       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	signal_action(int sig, siginfo_t *info, void *context)
{
	int						bit;
	static int				steps;
	static unsigned char	bytes;

	(void)context;
	bit = 0;
	if (sig == SIGUSR1)
		bit = 0;
	else if (sig == SIGUSR2)
		bit = 1;
	bytes = bytes << 1;
	bytes = bytes | bit;
	steps++;
	if (steps == 8)
	{
		if (bytes == '\0')
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR1);
		}
		else
			write(1, &bytes, 1);
		steps = 0;
		bytes = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_sigaction = signal_action;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	pid = getpid();
	if (pid < 0)
	{
		ft_printf("Error PID\n");
		return (0);
	}
	ft_printf("Process ID: %d\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
