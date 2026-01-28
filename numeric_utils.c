/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numeric_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kugurlu <kugurlu@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:37:41 by kugurlu           #+#    #+#             */
/*   Updated: 2026/01/28 17:38:31 by kugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	get_filler(t_flags *flags)
{
	if (flags->zero && !flags->dot && !flags->minus)
		return ('0');
	return (' ');
}

char	get_sign(int num, t_flags *flags)
{
	if (num < 0)
		return ('-');
	if (flags->plus)
		return ('+');
	if (flags->space)
		return (' ');
	return (0);
}
