/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kugurlu <kugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 18:20:01 by kugurlu           #+#    #+#             */
/*   Updated: 2025/11/29 18:25:49 by kugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	c_char;
	char			*found_c;

	found_c = NULL;
	c_char = (unsigned char)c;
	while (*s)
	{
		if (*s == c_char)
			found_c = (char *)s;
		s++;
	}
	if (c_char == '\0')
		return ((char *)s);
	return (found_c);
}
