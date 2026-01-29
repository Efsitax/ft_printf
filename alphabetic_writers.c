/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alphabetic_writers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kugurlu <kugurlu@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:17:05 by kugurlu           #+#    #+#             */
/*   Updated: 2026/01/29 14:33:37 by kugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	char_writer(int c, t_flags *flags)
{
	ssize_t	count;
	int		padding;
	char	chr;

	count = 0;
	chr = (char)c;
	padding = 0;
	if (flags->width > 1)
		padding = flags->width - 1;
	if (flags->minus)
	{
		count += write(1, &chr, 1);
		count += put_n_char(' ', padding);
	}
	else
	{
		count += put_n_char(' ', padding);
		count += write(1, &chr, 1);
	}
	return (count);
}

static ssize_t	string_writer(char *str, t_flags *flags)
{
	ssize_t	count;
	ssize_t	len;
	int		padding;

	if (!str)
		str = "(null)";
	count = 0;
	len = ft_strlen(str);
	if (flags->dot && flags->precision >= 0 && flags->precision < len)
		len = flags->precision;
	padding = flags->width - len;
	if (flags->minus)
	{
		count += write(1, str, len);
		count += put_n_char(' ', padding);
	}
	else
	{
		count += put_n_char(' ', padding);
		count += write(1, str, len);
	}
	return (count);
}

ssize_t	alphabetic_writers(const char type, va_list *ap, t_flags *flags)
{
	ssize_t	count;

	count = 0;
	if (type == 'c')
		count = char_writer(va_arg(*ap, int), flags);
	else if (type == 's')
		count = string_writer(va_arg(*ap, char *), flags);
	return (count);
}
