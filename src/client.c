/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martinmust <martinmust@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 13:30:38 by mmustone          #+#    #+#             */
/*   Updated: 2025/12/21 14:00:39 by martinmust       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

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
		send_byte(msg[i], pid);
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
		return ((pid_t)0);
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
	cut_msg(av[2], pid);
	return (0);
}
