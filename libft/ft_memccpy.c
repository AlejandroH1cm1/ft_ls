/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:17:41 by aherrera          #+#    #+#             */
/*   Updated: 2018/02/23 22:53:11 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void *src, int c, size_t n)
{
	int				i;
	unsigned char	*c1;
	unsigned char	*c2;

	i = 0;
	c2 = (unsigned char *)dst;
	c1 = (unsigned char *)src;
	while (i < (int)n)
	{
		c2[i] = c1[i];
		if (c1[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
