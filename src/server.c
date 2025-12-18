/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:34:02 by mmustone          #+#    #+#             */
/*   Updated: 2025/12/18 15:13:02 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	signal_action(int sig)
{
	int						bit;
	static int				steps;
	static unsigned char	bytes;

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
			write(1, "\n", 1);
		else
			write(1, &bytes, 1);
		steps = 0;
		bytes = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	if (pid < 0)
	{
		ft_printf("Error PID\n");
		return (0);
	}
	ft_printf("Process ID: %d\n", pid);
	signal(SIGUSR1, signal_action);
	signal(SIGUSR2, signal_action);
	while (1)
		pause();
	return (0);
}
