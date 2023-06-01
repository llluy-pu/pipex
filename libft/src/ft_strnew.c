/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llluy-pu <llluy-pu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:42:25 by llluy-pu          #+#    #+#             */
/*   Updated: 2022/05/19 01:08:49 by llluy-pu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = malloc(sizeof(*str) * size + 1);
	if (str == NULL)
		return (NULL);
	while (size > 0)
	{
		size--;
		str[size] = 0;
	}
	return (str);
}
