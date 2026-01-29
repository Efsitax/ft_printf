/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kugurlu <kugurlu@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:41:03 by kugurlu           #+#    #+#             */
/*   Updated: 2026/01/29 22:54:16 by kugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	type_checker(const char **format, va_list *ap)
{
	t_flags	flags;
	ssize_t	count;

	flag_checker(&flags, format);
	count = 0;
	if (**format == '%')
		count = write(1, "%", 1);
	else if (**format == 'c' || **format == 's')
		count = alphabetic_writers(**format, ap, &flags);
	else if (**format == 'd' || **format == 'i' || **format == 'u')
		count = numeric_writers(**format, ap, &flags);
	else if (**format == 'x' || **format == 'X' || **format == 'p')
		count = hexadecimal_writers(**format, ap, &flags);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	ssize_t	count;
	va_list	ap;

	if (!format)
		return (-1);
	count = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			count += type_checker(&format, &ap);
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		if (*format)
			format++;
	}
	va_end(ap);
	return (count);
}
