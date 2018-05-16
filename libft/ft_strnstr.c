/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 11:07:15 by aherrera          #+#    #+#             */
/*   Updated: 2018/02/23 01:32:48 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		j;

	if (*s2 == '\0')
		return ((char *)s1);
	j = ft_strlen(s2);
	while (*s1 != '\0' && n-- >= (size_t)j)
	{
		if (*s1 == *s2 && ft_memcmp(s1, s2, j) == 0)
			return ((char *)s1);
		s1++;
	}
	return (0);
}
