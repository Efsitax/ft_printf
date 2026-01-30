/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kugurlu <kugurlu@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:28:37 by kugurlu           #+#    #+#             */
/*   Updated: 2026/01/30 17:23:24 by kugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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

static int	get_padding_info(t_flags *f, int len, char *pad_char)
{
	*pad_char = ' ';
	if (f->zero && !f->minus)
		*pad_char = '0';
	if (f->width > len)
		return (f->width - len);
	return (0);
}

ssize_t	put_formatted_str(char *str, t_flags *f, int is_char)
{
	int		len;
	int		pad;
	char	pad_c;
	ssize_t	count;

	len = 1;
	if (!str && !is_char)
	{
		str = "(null)";
		len = 6;
		if (f->dot && f->precision >= 0 && f->precision < 6)
			len = 0;
	}
	else if (!is_char)
		len = (int)ft_strlen(str);
	if (!is_char && f->dot && f->precision >= 0 && f->precision < len)
		len = f->precision;
	pad = get_padding_info(f, len, &pad_c);
	count = 0;
	if (!f->minus && pad > 0)
		count += put_n_char(pad_c, pad);
	count += write(1, str, len);
	if (f->minus && pad > 0)
		count += put_n_char(' ', pad);
	return (count);
}
