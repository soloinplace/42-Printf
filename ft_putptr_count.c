/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csodini <csodini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 22:32:40 by csodini           #+#    #+#             */
/*   Updated: 2026/05/12 22:44:12 by csodini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_count(void *ptr)
{
	int	count;

	if (!ptr)
		return (ft_putstr_count("(nil)"));
	count = 0;
	count += ft_putstr_count("0x");
	count += ft_puthex_count((unsigned long)ptr, "0123456789abcdef");
	return (count);
}
