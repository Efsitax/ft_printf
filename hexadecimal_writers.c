/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal_writers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kugurlu <kugurlu@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:39:40 by kugurlu           #+#    #+#             */
/*   Updated: 2026/01/30 15:33:05 by kugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_hex_rec(unsigned long n, char *base)
{
	if (n >= 16)
		put_hex_rec(n / 16, base);
	write(1, &base[n % 16], 1);
}

static int	get_hex_len(unsigned long n, t_flags *f)
{
	int	len;

	if (n == 0 && f->dot && f->precision == 0)
		return (0);
	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static ssize_t	print_hex(unsigned long n, char *base, t_flags *f, char *prefix)
{
	ssize_t	ret;
	int		len;
	int		zeros;
	int		spaces;
	int		p_len;

	ret = 0;
	len = get_hex_len(n, f);
	p_len = (int)ft_strlen(prefix);
	zeros = 0;
	if (f->dot && f->precision > len)
		zeros = f->precision - len;
	else if (!f->dot && f->zero && !f->minus && f->width > len + p_len)
		zeros = f->width - len - p_len;
	spaces = f->width - (len + zeros + p_len);
	if (!f->minus && spaces > 0)
		ret += put_n_char(' ', spaces);
	if (p_len > 0)
		ret += write(1, prefix, p_len);
	ret += put_n_char('0', zeros);
	if (len > 0)
		put_hex_rec(n, base);
	if (f->minus && spaces > 0)
		ret += put_n_char(' ', spaces);
	return (ret + len);
}

static void	get_hex_meta(char type, unsigned long n, t_flags *f, char **p)
{
	*p = "";
	if (type == 'x' && f->hash && n != 0)
		*p = "0x";
	else if (type == 'X' && f->hash && n != 0)
		*p = "0X";
	else if (type == 'p')
		*p = "0x";
}

ssize_t	hexadecimal_writers(const char type, va_list *ap, t_flags *flags)
{
	unsigned long	val;
	char			*base;
	char			*prefix;

	if (type == 'p')
	{
		val = (unsigned long)va_arg(*ap, void *);
		if (val == 0)
			return (put_formatted_str("(nil)", flags, 0));
		base = "0123456789abcdef";
	}
	else
	{
		val = (unsigned long)va_arg(*ap, unsigned int);
		if (type == 'x')
			base = "0123456789abcdef";
		else
			base = "0123456789ABCDEF";
	}
	get_hex_meta(type, val, flags, &prefix);
	return (print_hex(val, base, flags, prefix));
}
