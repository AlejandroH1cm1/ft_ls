/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 05:37:34 by aherrera          #+#    #+#             */
/*   Updated: 2018/05/13 23:15:12 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.h"
#include "libft.h"

void	strcomb(char **st, char *s, int order, int n)
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

int		fl_exists(char *fl, char f)
{
	int i;

	i = 0;
	while (fl[i] != '\0')
	{
		if (fl[i] == f)
			return (1);
		i++;
	}
	return (0);
}

int		gn_fo(t_form *f, t_fo *tab)
{
	int i;

	i = 0;
	if (f->lent[0] == '\0')
		return (53);
	if (!is_ec(f->lent[ft_strlen(f->lent) - 1]))
		return (54);
	if (f->lent[ft_strlen(f->lent) - 1] == 'p')
		return (45);
	if (f->lent[ft_strlen(f->lent) - 1] == 'O')
		return (16);
	if (f->lent[ft_strlen(f->lent) - 1] == 'D')
		return (2);
	if (f->lent[ft_strlen(f->lent) - 1] == 'U')
		return (23);
	if (f->lent[ft_strlen(f->lent) - 1] == 'C')
		return (47);
	if (f->lent[ft_strlen(f->lent) - 1] == 'S')
		return (50);
	while (i < 54 && ft_strcmp(tab[i].fmt, f->lent))
		i++;
	return (i);
}

int		is_ec(char c)
{
	if (c == 's' || c == 'S' || c == 'O' || c == 'o' || c == 'x' || c == 'X' ||
		c == 'd' || c == 'D' || c == 'i' || c == 'u' || c == 'U' || c == 'C' ||
		c == 'p' || c == '%' || c == 'c')
		return (1);
	return (0);
}

t_ull	change(t_ull n, int len)
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
