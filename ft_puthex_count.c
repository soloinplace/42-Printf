/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csodini <csodini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 22:15:28 by csodini           #+#    #+#             */
/*   Updated: 2026/05/12 22:55:31 by csodini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_count(unsigned long n, char *base)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_puthex_count(n / 16, base);
	count += ft_putchar_count(base[n % 16]);
	return (count);
}
