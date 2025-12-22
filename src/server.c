/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:34:02 by mmustone          #+#    #+#             */
/*   Updated: 2025/12/22 14:28:43 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	signal_action(int sig)
{
	int						bit;
	static int				steps;
	static unsigned char	byte;

	bit = 0;
	if (sig == SIGUSR1)
		bit = 0;
	else if (sig == SIGUSR2)
		bit = 1;
	byte = byte << 1;
	byte = byte | bit;
	steps++;
	if (steps == 8)
	{
		if (byte == '\0')
			write(1, "\n", 1);
		else
			write(1, &byte, 1);
		steps = 0;
		byte = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("Process ID: %d\n", pid);
	signal(SIGUSR1, signal_action);
	signal(SIGUSR2, signal_action);
	while (1)
		pause();
	return (0);
}
