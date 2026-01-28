/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kugurlu <kugurlu@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 12:55:19 by kugurlu           #+#    #+#             */
/*   Updated: 2026/01/28 18:08:10 by kugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	num_parser(t_flags *flags, const char **type, int is_width)
{
	while (ft_isdigit(**type))
	{
		if (is_width)
			flags->width = flags->width * 10 + (**type - '0');
		else
			flags->precision = flags->precision * 10 + (**type - '0');
		(*type)++;
	}
}

static void	dot_shaper(t_flags *flags, const char **type)
{
	flags->dot = 1;
	flags->precision = 0;
	(*type)++;
	num_parser(flags, type, 0);
}

void	flag_checker(t_flags *flags, const char **type)
{
	ft_memset(flags, 0, sizeof(t_flags));
	flags->precision = -1;
	while (**type && !ft_strchr("cspdiuxX%", **type))
	{
		if (**type == '-')
			flags->minus = 1;
		else if (**type == '+')
			flags->plus = 1;
		else if (**type == '#')
			flags->hash = 1;
		else if (**type == ' ')
			flags->space = 1;
		else if (**type == '0' && flags->width == 0 && !flags->dot)
			flags->zero = 1;
		else if (**type == '.')
			dot_shaper(flags, type);
		else if (ft_isdigit(**type))
			num_parser(flags, type, 1);
		if (ft_strchr("-+# ", **type) || (**type == '0' && !flags->width))
			(*type)++;
	}
}
