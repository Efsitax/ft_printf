/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kugurlu <kugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:20:17 by kugurlu           #+#    #+#             */
/*   Updated: 2025/12/09 14:25:33 by kugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	n_long;

	if (fd < 0)
		return ;
	n_long = n;
	if (n_long < 0)
	{
		n_long = -n_long;
		ft_putchar_fd('-', fd);
	}
	if (n_long >= 10)
		ft_putnbr_fd(n_long / 10, fd);
	ft_putchar_fd((n_long % 10) + '0', fd);
}
