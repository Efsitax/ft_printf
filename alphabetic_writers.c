/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alphabetic_writers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kugurlu <kugurlu@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:17:05 by kugurlu           #+#    #+#             */
/*   Updated: 2026/01/23 17:47:49 by kugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static size_t	char_writer(int c)
{
	char	chr;

	chr = (char)c;
	return ((size_t)write(1, &chr, 1));
}

static size_t	string_writer(char *str)
{
	size_t	len;

	if (str == NULL)
		return ((size_t)write(1, "(null)", 6));
	len = ft_strlen(str);
	return ((size_t) write(1, str, len));
}

size_t	alphabetic_writers(const char type, va_list ap)
{
	size_t	count;

	count = 0;
	if (type == 'c')
		count = char_writer(va_arg(ap, int));
	else if (type == 's')
		count = string_writer(va_arg(ap, char *));
	return (count);
}
