/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 23:55:04 by aherrera          #+#    #+#             */
/*   Updated: 2018/05/07 18:08:20 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*aux(int n)
{
	char	*r;
	int		i;
	int		neg;

	i = 0;
	neg = 0;
	if (n < 0)
		neg = 1;
	if (n == 0)
		i = 1;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	r = (char *)malloc((i + 1 + neg) * sizeof(char));
	if (r != NULL)
	{
		if (neg == 1)
			r[i] = '-';
		r[i + neg] = '\0';
	}
	return (r);
}

char		*ft_itoa(int n)
{
	int		i;
	char	*r;

	r = aux(n);
	i = 0;
	if (r != NULL)
	{
		if (n == -2147483648)
		{
			ft_strcpy(r, "-2147483648");
			return (r);
		}
		if (n == 0)
			r[0] = '0';
		if (n < 0)
			n = n * -1;
		while (n != 0)
		{
			r[i++] = n % 10 + '0';
			n = n / 10;
		}
		ft_strrev(r);
	}
	return (r);
}
