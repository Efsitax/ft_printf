/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kugurlu <kugurlu@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:19:23 by kugurlu           #+#    #+#             */
/*   Updated: 2026/01/21 17:29:34 by kugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nlst;

	if (!lst || !*lst || !del)
		return ;
	while (*lst)
	{
		nlst = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = nlst;
	}
	*lst = NULL;
}
