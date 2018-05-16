/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 18:45:06 by aherrera          #+#    #+#             */
/*   Updated: 2018/02/23 00:01:14 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*r;

	r = (unsigned char *)s;
	i = 0;
	while (i < (int)n)
	{
		if (*r == (unsigned char)c)
			return ((void *)r);
		r++;
		i++;
	}
	return (NULL);
}
