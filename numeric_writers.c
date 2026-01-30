/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numeric_writers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kugurlu <kugurlu@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:00:26 by kugurlu           #+#    #+#             */
/*   Updated: 2026/01/30 17:18:16 by kugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	num_writer(long num, int is_signed)
{
	ssize_t		count;
	char		c;

	count = 0;
	if (num < 0 && is_signed)
	{
		count += write(1, "-", 1);
		num = -num;
	}
	if (num >= 10)
		count += num_writer(num / 10, is_signed);
	c = num % 10 + '0';
	count += write(1, &c, 1);
	return (count);
}

ssize_t	numeric_writers(const char type, va_list *ap)
{
	ssize_t	count;

	count = 0;
	if (type == 'd' || type == 'i')
		count = num_writer(va_arg(*ap, int), 1);
	else if (type == 'u')
		count = num_writer(va_arg(*ap, unsigned int), 0);
	return (count);
}
