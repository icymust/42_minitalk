/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 11:21:08 by mmustone          #+#    #+#             */
/*   Updated: 2025/08/14 15:54:35 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(void *pointer)
{
	int				printed;
	unsigned long	l;
	int				temp;

	printed = 2;
	temp = 0;
	l = (unsigned long)pointer;
	if (!pointer)
		return (ft_print_str("0x0"));
	if (write(1, "0x", 2) == -1)
		return (-1);
	if (l == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		printed ++;
	}
	else
	{
		temp = ft_print_hex(l, 0);
		if (temp == -1)
			return (-1);
		printed += temp;
	}
	return (printed);
}
