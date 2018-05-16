/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 07:28:28 by aherrera          #+#    #+#             */
/*   Updated: 2018/02/23 00:57:11 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t nt)
{
	size_t	nd;
	int		i;

	i = 0;
	while (dst[i] != '\0' && i < (int)nt)
		i++;
	nd = i;
	while (src[i - nd] != '\0' && i < (int)nt - 1)
	{
		dst[i] = src[i - nd];
		i++;
	}
	if (nd < nt)
		dst[i] = '\0';
	return (nd + ft_strlen(src));
}
