/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kugurlu <kugurlu@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 01:16:54 by kugurlu           #+#    #+#             */
/*   Updated: 2026/01/21 14:27:01 by kugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(long num)
{
	int	count;

	count = 0;
	if (num < 0)
	{
		num = -num;
		count++;
	}
	while (num > 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

static char	*res_zero(void)
{
	char	*str_zero;

	str_zero = malloc(2);
	if (!str_zero)
		return (NULL);
	str_zero[0] = '0';
	str_zero[1] = '\0';
	return (str_zero);
}

char	*ft_itoa(int n)
{
	char	*str_int;
	int		count;
	long	n_long;

	if (n == 0)
		return (res_zero());
	n_long = n;
	count = int_len(n_long);
	str_int = malloc(count + 1);
	if (!str_int)
		return (NULL);
	if (n_long < 0)
	{
		str_int[0] = '-';
		n_long = -n_long;
	}
	str_int[count--] = '\0';
	while (n_long > 0)
	{
		str_int[count] = (n_long % 10) + '0';
		n_long /= 10;
		count--;
	}
	return (str_int);
}
