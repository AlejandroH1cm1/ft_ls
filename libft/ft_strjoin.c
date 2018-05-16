/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 18:18:30 by aherrera          #+#    #+#             */
/*   Updated: 2018/05/11 04:07:30 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *r;

	if (!s1 || !s2)
		return (0);
	r = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (r != NULL)
	{
		ft_strcpy(r, s1);
		r[ft_strlen(s1)] = '\0';
		ft_strcat(r, s2);
		r[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	}
	return (r);
}
