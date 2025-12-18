/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 13:30:38 by mmustone          #+#    #+#             */
/*   Updated: 2025/12/18 14:16:43 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void send_byte(unsigned char c, int pid){
	int i = 0;
	int bit;

	while(i<8){
		bit = (c >> (7 - i)) & 1;
		if(bit == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
		i++;
	}
}

int	pid_atoi(const char *str)
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
			return (0);
		str++;
	}
	if (*str != '\0')
		return (0);
	return ((int)(result));
}

int	main(int ac, char **av)
{
	int	pid;
	int i = 0;

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
	while(av[2][i]){
		send_byte(av[2][i], pid);
		i++;
	}
	send_byte('\0', pid);
	return (0);
}
