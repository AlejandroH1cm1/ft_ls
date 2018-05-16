/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcomb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 19:04:13 by aherrera          #+#    #+#             */
/*   Updated: 2018/05/15 19:05:16 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcomb(char **st, char *s, int order, int n)
{
	char *tmp;
	char *tmp2;

	tmp2 = (char *)malloc((n + 1) * sizeof(char));
	ft_strncpy(tmp2, s, n);
	tmp2[n] = '\0';
	if (order == 0)
		tmp = ft_strjoin(*st, tmp2);
	else
		tmp = ft_strjoin(tmp2, *st);
	free(*st);
	free(tmp2);
	*st = tmp;
}
