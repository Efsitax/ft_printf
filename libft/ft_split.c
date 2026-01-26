/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kugurlu <kugurlu@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:21:45 by kugurlu           #+#    #+#             */
/*   Updated: 2026/01/21 14:25:49 by kugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (s[++i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
	}
	return (count);
}

static char	*splited_word(char const *s, char const *w_start, int j, char c)
{
	int		count;
	int		i;

	i = -1;
	count = 0;
	while (w_start[++i] && w_start[i] != c)
		count++;
	return (ft_substr(s, (unsigned int)j, count));
}

static char	**free_tab(char **str, int i)
{
	while (i > 0)
	{
		i--;
		free(str[i]);
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char		**split_str;
	int			i;
	int			j;

	if (!s)
		return (NULL);
	split_str = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split_str)
		return (NULL);
	i = -1;
	j = 0;
	while (s[++i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			split_str[j] = splited_word(s, s + i, i, c);
			if (!split_str[j])
				return (free_tab(split_str, j));
			j++;
		}
	}
	split_str[j] = NULL;
	return (split_str);
}
