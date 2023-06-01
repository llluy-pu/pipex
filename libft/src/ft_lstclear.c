/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llluy-pu <llluy-pu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 04:31:15 by llluy-pu          #+#    #+#             */
/*   Updated: 2022/06/24 12:18:57 by llluy-pu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_memdel_static(void **ap)
{
	free(*ap);
	*ap = NULL;
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	if (lst == NULL || *lst == NULL)
		return ;
	while (*lst)
	{
		ptr = (*lst)->next;
		(*del)((*lst)->content);
		ft_memdel_static((void **)lst);
		*lst = ptr;
	}
	*lst = NULL;
}
