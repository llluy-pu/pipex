/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llluy-pu <llluy-pu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:11:56 by llluy-pu          #+#    #+#             */
/*   Updated: 2022/06/24 12:21:19 by llluy-pu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memalloc_static(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, size);
	return (ptr);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	overflowcheck;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	overflowcheck = nmemb * size;
	if (overflowcheck / nmemb != size)
		return (malloc(0));
	ptr = ft_memalloc_static(nmemb * size);
	return (ptr);
}
