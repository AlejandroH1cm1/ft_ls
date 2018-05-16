/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 18:16:00 by aherrera          #+#    #+#             */
/*   Updated: 2018/02/23 22:43:50 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*r;

	if (!s)
		return (0);
	i = 0;
	r = (char *)malloc((len - i + 1) * sizeof(char));
	if (r != NULL)
	{
		while (i < (unsigned int)len)
		{
			r[i] = s[start + i];
			i++;
		}
		r[i] = '\0';
	}
	return (r);
}
