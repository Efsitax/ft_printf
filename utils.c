/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kugurlu <kugurlu@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:28:37 by kugurlu           #+#    #+#             */
/*   Updated: 2026/01/30 16:01:10 by kugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	put_n_char(char c, int n)
{
	ssize_t	total;
	ssize_t	res;

	total = 0;
	if (n <= 0)
		return (0);
	while (n > 0)
	{
		res = write(1, &c, 1);
		if (res == -1)
			return (-1);
		total += res;
		n--;
	}
	return (total);
}

ssize_t	put_formatted_str(char *str, t_flags *f, int is_char)
{
	int		len;
	int		padding;
	char	pad_char;
	ssize_t	count;

	if (!str && !is_char)
		str = "(null)";
	if (is_char)
		len = 1;
	else
		len = (int)ft_strlen(str);
	if (!is_char && f->dot && f->precision >= 0 && f->precision < len)
		len = f->precision;
	padding = f->width - len;
	pad_char = ' ';
	if (f->zero && !f->minus)
		pad_char = '0';
	count = 0;
	if (!f->minus && padding > 0)
		count += put_n_char(pad_char, padding);
	count += write(1, str, len);
	if (f->minus && padding > 0)
		count += put_n_char(' ', padding);
	return (count);
}
