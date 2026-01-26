/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kugurlu <kugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 19:30:26 by kugurlu           #+#    #+#             */
/*   Updated: 2025/11/29 19:40:11 by kugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	c_char;
	unsigned char	*s_char;
	size_t			i;

	c_char = (unsigned char)c;
	s_char = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (s_char[i] == c_char)
			return ((void *)(s_char + i));
		i++;
	}
	return (NULL);
}
