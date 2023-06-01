/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llluy-pu <llluy-pu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 03:55:02 by llluy-pu          #+#    #+#             */
/*   Updated: 2022/07/12 17:03:08 by llluy-pu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstsize(t_list *lst)
{
	size_t	cnt;

	if (lst == NULL)
		return (0);
	cnt = 1;
	while (lst->next)
	{
		cnt++;
		lst = lst->next;
	}
	return (cnt);
}
