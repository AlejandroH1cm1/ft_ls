/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 19:56:00 by aherrera          #+#    #+#             */
/*   Updated: 2018/03/13 12:11:36 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*st;
	int		i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (!(st = (char *)malloc((i + 1) * sizeof(char))))
		return (NULL);
	ft_strcpy(st, s);
	st[i] = '\0';
	return (st);
}
