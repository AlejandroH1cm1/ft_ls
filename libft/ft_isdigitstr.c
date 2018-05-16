/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigitstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 16:47:59 by aherrera          #+#    #+#             */
/*   Updated: 2018/04/25 19:45:46 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigitstr(char *st)
{
	int i;
	int j;

	i = 0;
	j = ft_strlen(st);
	while (i < j)
	{
		if (!ft_isdigit(st[i]))
			return (0);
		i++;
	}
	return (1);
}
