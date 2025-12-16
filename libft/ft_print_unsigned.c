/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:20:51 by mmustone          #+#    #+#             */
/*   Updated: 2025/08/14 11:31:02 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int num)
{
	int	printed;
	int	temp;

	printed = 0;
	if (num >= 10)
	{
		temp = ft_print_unsigned(num / 10);
		if (temp == -1)
			return (-1);
		printed += temp;
	}
	temp = ft_print_char((num % 10) + '0');
	if (temp == -1)
		return (-1);
	printed += temp;
	return (printed);
}
