/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 19:59:27 by aherrera          #+#    #+#             */
/*   Updated: 2018/04/25 10:58:07 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	int		i;
	char	*t;

	i = 0;
	t = dst;
	while (*src != '\0' && i < (int)n)
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	while (i < (int)n)
	{
		*dst = '\0';
		dst++;
		i++;
	}
	return (t);
}
