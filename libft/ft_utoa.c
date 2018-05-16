/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 23:13:54 by aherrera          #+#    #+#             */
/*   Updated: 2018/05/13 23:36:14 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_ull	change(t_ull n, int len)
{
	unsigned short	s;
	unsigned char	c;
	unsigned long	l;
	unsigned int	i;
	size_t			t;

	t = (size_t)n;
	s = (unsigned short)n;
	c = (unsigned char)n;
	i = (unsigned int)n;
	l = (unsigned long)n;
	if (len == 0)
		return ((t_ull)i);
	if (len == -1)
		return ((t_ull)s);
	if (len == -2)
		return ((t_ull)c);
	if (len == 1)
		return ((t_ull)t);
	if (len == 2)
		return ((t_ull)l);
	return (n);
}

static void		cleanse_str(char **s)
{
	char *tmp;

	if (((s[0][0] < '0' || s[0][0] > '9') && (s[0][0] < 'a' || s[0][0] > 'f')
		&& (s[0][0] < 'A' || s[0][0] > 'F'))
		|| (s[0][0] == '0' && s[0][1] != 0))
	{
		tmp = ft_strdup(&(s[0][1]));
		free(*s);
		*s = tmp;
	}
}

static char		*aux(t_ull n, t_ull b)
{
	char	*r;
	int		i;

	i = 0;
	while (n >= b)
	{
		n = n / b;
		i++;
	}
	i++;
	r = (char *)malloc((i + 1) * sizeof(char));
	if (r != NULL)
		r[i] = '\0';
	return (r);
}

char			*ft_utoa(t_ull n, t_ull b, char x, int l)
{
	int		i;
	char	*r;

	n = change(n, l);
	r = aux(n, b);
	i = 0;
	if (r != NULL)
	{
		if (n == 0)
			r[0] = '0';
		while (n != 0)
		{
			r[i++] = n % b + '0';
			if (r[i - 1] > '9')
				r[i - 1] = r[i - 1] - '0' + x - 10;
			n = n / b;
		}
		ft_strrev(r);
	}
	cleanse_str(&r);
	return (r);
}
