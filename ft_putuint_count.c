/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csodini <csodini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 22:56:34 by csodini           #+#    #+#             */
/*   Updated: 2026/05/12 23:02:36 by csodini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuint_count(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putuint_count(n / 10);
	count += ft_putchar_count((n % 10) + '0');
	return (count);
}
