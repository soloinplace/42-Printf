/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csodini <csodini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 22:26:10 by csodini           #+#    #+#             */
/*   Updated: 2026/05/12 22:30:56 by csodini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_count(int n)
{
	long	nb;
	int		count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		count += ft_putchar_count('-');
		nb = -nb;
	}
	if (nb >= 10)
		count += ft_putnbr_count(nb / 10);
	count += ft_putchar_count((nb % 10 + '0'));
	return (count);
}
