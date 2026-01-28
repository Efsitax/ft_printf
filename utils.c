/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kugurlu <kugurlu@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:28:37 by kugurlu           #+#    #+#             */
/*   Updated: 2026/01/28 18:00:24 by kugurlu          ###   ########.fr       */
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
