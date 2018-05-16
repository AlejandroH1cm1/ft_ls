/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 21:44:14 by aherrera          #+#    #+#             */
/*   Updated: 2018/02/23 22:44:17 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char *s, char (*f)(unsigned int, char))
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
			r[i] = (*f)(i, *s);
			s++;
			i++;
		}
		r[i] = '\0';
	}
	return (r);
}
