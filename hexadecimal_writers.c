/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal_writers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kugurlu <kugurlu@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:39:40 by kugurlu           #+#    #+#             */
/*   Updated: 2026/01/23 17:35:47 by kugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static size_t	hex_writer(unsigned long num, int is_upper)
{
	char	*lower_hex;
	char	*upper_hex;
	size_t	count;
	char	c;

	lower_hex = "0123456789abcdef";
	upper_hex = "0123456789ABCDEF";
	count = 0;
	if (num >= 16)
		count += hex_writer(num / 16, is_upper);
	if (is_upper)
		c = upper_hex[num % 16];
	else
		c = lower_hex[num % 16];
	count += (size_t)write(1, &c, 1);
	return (count);
}

static size_t	pointer_writer(void *ptr)
{
	unsigned long	ptr_num;
	size_t			count;

	if (!ptr)
		return ((size_t)write(1, "(nil)", 5));
	count = 0;
	ptr_num = (unsigned long)ptr;
	count += (size_t)write(1, "0x", 2);
	count += hex_writer(ptr_num, 0);
	return (count);
}

size_t	hexadecimal_writers(const char type, va_list ap)
{
	size_t	count;

	count = 0;
	if (type == 'x')
		count = hex_writer(va_arg(ap, int), 0);
	else if (type == 'X')
		count = hex_writer(va_arg(ap, unsigned int), 1);
	else if (type == 'p')
		count = pointer_writer(va_arg(ap, void *));
	return (count);
}
