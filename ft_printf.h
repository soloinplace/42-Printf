/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csodini <csodini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 22:12:33 by csodini           #+#    #+#             */
/*   Updated: 2026/05/12 22:13:20 by csodini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar_count(char c);
int	ft_putstr_count(char *s);
int	ft_putnbr_count(int n);
int	ft_putuint_count(unsigned int n);
int	ft_puthex_count(unsigned long n, char *base);
int	ft_putptr_count(void *ptr);

#endif