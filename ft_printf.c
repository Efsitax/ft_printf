/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kugurlu <kugurlu@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:41:03 by kugurlu           #+#    #+#             */
/*   Updated: 2026/01/23 17:08:24 by kugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	type_checker(const char type, va_list ap)
{
	size_t	count;

	count = 0;
	if (type == '%')
		count = (size_t)write(1, "%", 1);
	else if (type == 'c' || type == 's')
		count = alphabetic_writers(type, ap);
	else if (type == 'd' || type == 'i' || type == 'u')
		count = numeric_writers(type, ap);
	else if (type == 'x' || type == 'X' || type == 'p')
		count = hexadecimal_writers(type, ap);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	count;
	va_list	ap;

	i = -1;
	count = 0;
	va_start(ap, format);
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
		{
			count += type_checker(format[i + 1], ap);
			i++;
			continue ;
		}
		write(1, &format[i], 1);
		count++;
	}
	va_end(ap);
	return (count);
}
