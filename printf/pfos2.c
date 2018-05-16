/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfos2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 16:34:30 by aherrera          #+#    #+#             */
/*   Updated: 2018/03/25 00:52:21 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.h"

int	pf_foa1(t_form *f, wint_t c)
{
	int i;

	i = 1;
	ft_putchar(c);
	while (i < f->widt)
	{
		ft_putchar(' ');
		i++;
	}
	return (i);
}

int	pf_foa2(t_form *f, wint_t c)
{
	int		i;
	char	c2;

	i = 1;
	c2 = ' ' + fl_exists(f->flag, '0') * 16;
	while (i < f->widt)
	{
		ft_putchar(c2);
		i++;
	}
	ft_putchar(c);
	return (i);
}

int	pf_fob1(t_form *f, wchar_t *s)
{
	int i;

	i = 0;
	if (s != NULL)
		while (s[i] != '\0')
			i++;
	else
		i = 6;
	if (f->prec < i && f->prec >= 0)
		i = f->prec;
	if (s != NULL)
		ft_putwstr(s, i);
	else
		ft_putwstr(L"(null)", i);
	while (i < f->widt)
	{
		ft_putchar(' ');
		i++;
	}
	return (i);
}

int	pf_fob2(t_form *f, wchar_t *s)
{
	int i;
	int j;
	int c;

	i = 0;
	j = 0;
	c = 32 + fl_exists(f->flag, '0') * 16;
	if (s != NULL)
		while (s[j] != '\0')
			j++;
	else
		j = 6;
	if (f->prec < j && f->prec >= 0)
		j = f->prec;
	while (i < f->widt - j)
	{
		ft_putchar(c);
		i++;
	}
	i = i + j;
	if (s != NULL)
		ft_putwstr(s, j);
	else
		ft_putwstr(L"(null)", j);
	return (i);
}
