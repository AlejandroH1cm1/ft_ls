/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 21:40:27 by aherrera          #+#    #+#             */
/*   Updated: 2018/03/03 15:26:51 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char *s, char (*f)(char))
{
	char	*r;
	int		i;

	if (!s || !f)
		return (0);
	i = 0;
	r = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (r != NULL)
	{
		while (*s != '\0')
		{
			r[i] = (*f)(*s);
			s++;
			i++;
		}
		r[i] = '\0';
	}
	return (r);
}
