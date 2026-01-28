/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numeric_writers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kugurlu <kugurlu@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:00:26 by kugurlu           #+#    #+#             */
/*   Updated: 2026/01/28 18:07:46 by kugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	put_numeric_data(char *s, int p_len, char sign, t_flags *flags)
{
	ssize_t	count;
	int		len;

	count = 0;
	len = ft_strlen(s);
	if (flags->dot && flags->precision == 0 && s[0] == '0')
		len = 0;
	if (sign)
		count += write(1, &sign, 1);
	count += put_n_char('0', p_len - len);
	count += write(1, s, len);
	return (count);
}

static ssize_t	handle_numeric(char *s, int p_len, t_flags *flags, int num)
{
	ssize_t	count;
	int		total_len;
	char	sign;
	char	filler;

	count = 0;
	sign = get_sign(num, flags);
	filler = get_filler(flags);
	total_len = p_len + (sign != 0);
	if (!flags->minus && filler == ' ')
		count += put_n_char(' ', flags->width - total_len);
	if (filler == '0' && sign)
	{
		count += write(1, &sign, 1);
		sign = 0;
	}
	if (filler == '0')
		count += put_n_char('0', flags->width - total_len);
	count += put_numeric_data(s, p_len, sign, flags);
	if (flags->minus)
		count += put_n_char(' ', flags->width - total_len);
	return (count);
}

static ssize_t	num_writer(long n, t_flags *flags, int is_signed)
{
	char	*s;
	ssize_t	count;
	int		len;
	int		p_len;
	char	sign;

	if (is_signed)
		sign = get_sign((int)n, flags);
	else
		sign = 0;
	if (n < 0)
		n = -n;
	s = ft_itoa(n);
	len = ft_strlen(s);
	p_len = len;
	if (flags->dot && flags->precision > len)
		p_len = flags->precision;
	if (flags->dot && flags->precision == 0 && n == 0)
		p_len = 0;
	count = handle_numeric(s, p_len, flags, sign);
	free(s);
	return (count);
}

ssize_t	numeric_writers(const char type, va_list ap, t_flags *flags)
{
	if (type == 'd' || type == 'i')
		return (num_writer(va_arg(ap, int), flags, 1));
	if (type == 'u')
		return (num_writer(va_arg(ap, unsigned int), flags, 0));
	return (0);
}
