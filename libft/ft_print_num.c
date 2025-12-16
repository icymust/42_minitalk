/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:35:00 by mmustone          #+#    #+#             */
/*   Updated: 2025/08/19 13:12:37 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_num(int num)
{
	int		printed;
	long	l;
	int		temp;

	printed = 0;
	temp = 0;
	l = num;
	if (l < 0)
	{
		if (ft_print_char('-') == -1)
			return (-1);
		printed++;
		l = -l;
	}
	if (l >= 10)
	{
		temp = ft_print_num(l / 10);
		if (temp == -1)
			return (-1);
		printed += temp;
	}
	if (ft_print_char((l % 10) + '0') == -1)
		return (-1);
	printed++;
	return (printed);
}
