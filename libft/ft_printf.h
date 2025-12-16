/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:59:26 by mmustone          #+#    #+#             */
/*   Updated: 2025/08/14 11:31:17 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *fmt, ...);
int	ft_print_char(int c);
int	ft_print_str(const char *str);
int	ft_check_format(const char *fmt, va_list ap);
int	ft_print_hex(unsigned long num, int case_type);
int	ft_print_pointer(void *pointer);
int	ft_print_num(int num);
int	ft_print_unsigned(unsigned int num);

#endif