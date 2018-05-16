/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 18:12:52 by aherrera          #+#    #+#             */
/*   Updated: 2018/02/23 00:11:35 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	int				i;

	c2 = (unsigned char *)dst;
	c1 = (unsigned char *)src;
	i = -1;
	if (c1 < c2)
		while ((int)(--n) >= 0)
			c2[n] = c1[n];
	else
		while (++i < (int)n)
			c2[i] = c1[i];
	return (c2);
}
