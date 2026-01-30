/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numeric_writers_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kugurlu <kugurlu@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:00:26 by kugurlu           #+#    #+#             */
/*   Updated: 2026/01/30 17:23:19 by kugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	put_recursive(unsigned long num)
{
	char	c;

	if (num >= 10)
		put_recursive(num / 10);
	c = (num % 10) + '0';
	write(1, &c, 1);
}

static int	get_num_len(unsigned long num, t_flags *f)
{
	int	len;

	if (num == 0 && f->dot && f->precision == 0)
		return (0);
	if (num == 0)
		return (1);
	len = 0;
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static ssize_t	print_formatted(char sign, unsigned long num, t_flags *f)
{
	ssize_t	ret;
	int		len;
	int		zeros;
	int		spaces;

	ret = 0;
	len = get_num_len(num, f);
	zeros = 0;
	if (f->dot && f->precision > len)
		zeros = f->precision - len;
	else if (!f->dot && f->zero && !f->minus && f->width > len + (sign != 0))
		zeros = f->width - len - (sign != 0);
	spaces = f->width - (len + zeros + (sign != 0));
	if (!f->minus && spaces > 0)
		ret += put_n_char(' ', spaces);
	if (sign)
		ret += write(1, &sign, 1);
	ret += put_n_char('0', zeros);
	if (len > 0)
		put_recursive(num);
	if (f->minus && spaces > 0)
		ret += put_n_char(' ', spaces);
	return (ret + len);
}

ssize_t	numeric_writers(const char type, va_list *ap, t_flags *flags)
{
	unsigned long	val;
	long			n;
	char			sign;

	sign = 0;
	if (type == 'u')
		val = (unsigned long)va_arg(*ap, unsigned int);
	else
	{
		n = (long)va_arg(*ap, int);
		if (n < 0)
		{
			val = (unsigned long)(-n);
			sign = '-';
		}
		else
		{
			val = (unsigned long)n;
			if (flags->plus)
				sign = '+';
			else if (flags->space)
				sign = ' ';
		}
	}
	return (print_formatted(sign, val, flags));
}
