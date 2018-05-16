/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sfs2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 11:31:26 by aherrera          #+#    #+#             */
/*   Updated: 2018/03/23 12:54:57 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.h"

static char	*aux(char n)
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

char		*ft_ctoa(int c)
{
	int		i;
	char	*r;
	char	n;

	n = (char)c;
	i = 0;
	if (n == -128)
		return (ft_strdup("-128"));
	r = aux(n);
	if (r != NULL)
	{
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

static char	*aux2(short n)
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

char		*ft_stoa(int c)
{
	int		i;
	char	*r;
	short	n;

	n = (short)c;
	i = 0;
	if (n == -32768)
		return (ft_strdup("-32768"));
	r = aux2(n);
	if (r != NULL)
	{
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
