/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 20:46:30 by aherrera          #+#    #+#             */
/*   Updated: 2018/05/14 22:02:22 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *s;

	s = (char *)malloc((size + 1) * sizeof(char));
	if (s != NULL)
		ft_memset((void *)s, 0, size + 1);
	return (s);
}
