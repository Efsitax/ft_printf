/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kugurlu <kugurlu@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 20:05:34 by kugurlu           #+#    #+#             */
/*   Updated: 2026/01/18 15:14:47 by kugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*s_dup;

	len = ft_strlen(s);
	s_dup = malloc(len + 1);
	if (!s_dup)
		return (NULL);
	ft_memcpy(s_dup, s, len + 1);
	return (s_dup);
}
