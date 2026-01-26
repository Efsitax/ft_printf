/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kugurlu <kugurlu@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:17:47 by kugurlu           #+#    #+#             */
/*   Updated: 2026/01/17 12:49:05 by kugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srcsize;

	srcsize = ft_strlen(src);
	if (size == 0)
		return (srcsize);
	if (size > srcsize)
	{
		ft_memcpy(dst, src, srcsize);
		dst[srcsize] = '\0';
	}
	else
	{
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (srcsize);
}
