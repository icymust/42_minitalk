/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:57:55 by mmustone          #+#    #+#             */
/*   Updated: 2025/08/19 13:18:50 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(const char *str)
{
	int	printed;
	int	temp;

	printed = 0;
	if (!str)
		str = "(null)";
	while (*str)
	{
		temp = ft_print_char(*str++);
		if (temp == -1)
			return (-1);
		printed += temp;
	}
	return (printed);
}
