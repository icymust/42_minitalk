/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martinmust <martinmust@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 01:19:23 by martinmust        #+#    #+#             */
/*   Updated: 2025/12/20 00:42:43 by martinmust       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ack_action(int sig)
{
	if (sig == SIGUSR1)
	{
		write(1, "ok\n", 3);
		exit(0);
	}
}

void	send_byte(unsigned char c, pid_t pid)
{
	int	i;
	int	bit;

	i = 0;
	while (i < 8)
	{
		bit = (c >> (7 - i)) & 1;
		if (bit == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
		i++;
	}
}

void	cut_msg(char *msg, pid_t pid)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		send_byte((unsigned char)msg[i], pid);
		i++;
	}
	send_byte('\0', pid);
}

pid_t	pid_atoi(const char *str)
{
	long	result;

	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str < '0' || *str > '9')
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		if (result > INT_MAX || result < 0)
			return ((pid_t)0);
		str++;
	}
	if (*str != '\0')
		return (0);
	return ((pid_t)(result));
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 3)
	{
		ft_printf("Error\nUsage: ./client <PID_SERVER> <text>\n");
		return (1);
	}
	pid = pid_atoi(av[1]);
	if (!pid)
	{
		ft_printf("Error\nPID incorrect\n");
		return (1);
	}
	if (kill(pid, 0) == -1)
	{
		ft_printf("Error\nServer not running\n");
		return (1);
	}
	signal(SIGUSR1, ack_action);
	cut_msg(av[2], pid);
	pause();
	return (0);
}
