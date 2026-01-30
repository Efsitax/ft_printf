/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alphabetic_writers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kugurlu <kugurlu@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:17:05 by kugurlu           #+#    #+#             */
/*   Updated: 2026/01/30 16:01:50 by kugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	char_writer(int c, t_flags *flags)
{
	char	s[1];

	s[0] = (char)c;
	if (c == '%')
	{
		flags->dot = 0;
		return (put_formatted_str(s, flags, 1));
	}
	return (put_formatted_str(s, flags, 1));
}

static ssize_t	string_writer(char *str, t_flags *flags)
{
	return (put_formatted_str(str, flags, 0));
}

ssize_t	alphabetic_writers(const char type, va_list *ap, t_flags *flags)
{
	ssize_t	count;

	count = 0;
	if (type == 'c')
		count = char_writer(va_arg(*ap, int), flags);
	else if (type == 's')
		count = string_writer(va_arg(*ap, char *), flags);
	else if (type == '%')
		count = char_writer('%', flags);
	return (count);
}
