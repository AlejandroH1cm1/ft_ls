/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 13:30:05 by aherrera          #+#    #+#             */
/*   Updated: 2018/04/08 14:02:33 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int i;

	i = 0;
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2 && i < (int)n)
	{
		s1++;
		s2++;
		i++;
	}
	if (i == (int)n)
	{
		s1--;
		s2--;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
