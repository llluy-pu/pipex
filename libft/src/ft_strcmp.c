/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llluy-pu <llluy-pu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 04:56:23 by llluy-pu          #+#    #+#             */
/*   Updated: 2022/04/21 22:50:45 by llluy-pu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	if (ft_strlen(s1) < ft_strlen(s2))
		return (ft_memcmp(s1, s2, ft_strlen(s1) + 1));
	else
		return (ft_memcmp(s1, s2, ft_strlen(s2) + 1));
}
