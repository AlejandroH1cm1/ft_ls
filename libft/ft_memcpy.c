/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:01:59 by aherrera          #+#    #+#             */
/*   Updated: 2018/02/22 23:57:54 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	int		i;
	char	*c1;
	char	*c2;

	i = 0;
	c2 = (char *)dst;
	c1 = (char *)src;
	while (i < (int)n)
	{
		*c2 = *c1;
		c2++;
		c1++;
		i++;
	}
	return (dst);
}
