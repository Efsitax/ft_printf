/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kugurlu <kugurlu@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:41:03 by kugurlu           #+#    #+#             */
/*   Updated: 2026/01/30 17:22:52 by kugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static ssize_t	type_checker(const char **format, va_list *ap)
{
	t_flags	flags;
	ssize_t	count;

	flag_checker(&flags, format);
	count = 0;
	if (**format == 'c' || **format == 's' || **format == '%')
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
