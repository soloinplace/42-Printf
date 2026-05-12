/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csodini <csodini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 23:04:24 by csodini           #+#    #+#             */
/*   Updated: 2026/05/12 23:25:21 by csodini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_arg(char c, va_list *args)
{
	if (c == 'c')
		return (ft_putchar_count((char)va_arg(*args, int)));
	if (c == 's')
		return (ft_putstr_count(va_arg(*args, char *)));
	if (c == 'p')
		return (ft_putptr_count(va_arg(*args, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_count(va_arg(*args, int)));
	if (c == 'u')
		return (ft_putuint_count(va_arg(*args, unsigned int)));
	if (c == 'x')
		return (ft_puthex_count(va_arg(*args, unsigned int),
				"0123456789abcdef"));
	if (c == 'X')
		return (ft_puthex_count(va_arg(*args, unsigned int),
				"0123456789ABCDEF"));
	if (c == '%')
		return (ft_putchar_count('%'));
	return (ft_putchar_count('%') + ft_putchar_count(c));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!format)
		return (-1);
	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += ft_print_arg(format[i + 1], &args);
			i += 2;
		}
		else
		{
			count += ft_putchar_count(format[i]);
			i++;
		}
	}
	va_end(args);
	return (count);
}
