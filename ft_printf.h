/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kugurlu <kugurlu@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:39:27 by kugurlu           #+#    #+#             */
/*   Updated: 2026/01/29 15:03:01 by kugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_flags
{
	int	minus;
	int	zero;
	int	dot;
	int	hash;
	int	space;
	int	plus;
	int	width;
	int	precision;
}	t_flags;

int		ft_printf(const char *format, ...);

ssize_t	alphabetic_writers(const char type, va_list *ap, t_flags *flags);
ssize_t	numeric_writers(const char type, va_list *ap, t_flags *flags);
ssize_t	hexadecimal_writers(const char type, va_list *ap);

void	flag_checker(t_flags *flags, const char **type);
ssize_t	put_n_char(char c, int n);

#endif
