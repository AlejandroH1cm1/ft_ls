/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:14:38 by aherrera          #+#    #+#             */
/*   Updated: 2018/02/19 15:54:53 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	int				i;
	unsigned char	*ch;

	i = 0;
	ch = (unsigned char *)b;
	while (i < (int)n)
	{
		*ch = (unsigned char)c;
		ch++;
		i++;
	}
	return (b);
}
