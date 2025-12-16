/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:38:08 by mmustone          #+#    #+#             */
/*   Updated: 2025/08/14 13:50:45 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		total;
	int		temp;

	total = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			temp = ft_check_format(fmt, ap);
		}
		else
			temp = ft_print_char(*fmt);
		if (temp == -1)
		{
			va_end(ap);
			return (-1);
		}
		total += temp;
		fmt++;
	}
	va_end(ap);
	return (total);
}
