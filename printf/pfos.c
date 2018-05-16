/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfos.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 02:24:49 by aherrera          #+#    #+#             */
/*   Updated: 2018/03/25 05:16:59 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.h"

static char	*apply_0(char **st, t_form *f)
{
	char	*tmp;
	int		i;

	i = f->prec;
	if (f->prec < 0)
		i = f->widt;
	if (st[0][0] == '-' || st[0][0] == '+' || st[0][0] == ' ')
		tmp = ft_strdup(&(st[0][1]));
	else if (is_hex(*st) || is_oct(*st))
		tmp = ft_strdup(&(st[0][2]));
	else
		tmp = ft_strdup(*st);
	if ((st[0][0] == '-' || st[0][0] == '+' || st[0][0] == ' ')
			&& fl_exists(f->flag, '0') && f->prec < 0)
		i--;
	if ((is_hex(*st) || is_oct(*st)) && f->lent[ft_strlen(f->lent) - 1] != 'p')
		i -= 2;
	while ((int)ft_strlen(tmp) < i)
		strcomb(&tmp, "0", 1, 1);
	if (st[0][0] == '-' || st[0][0] == '+' || st[0][0] == ' ')
		strcomb(&tmp, ctos(st[0][0]), 1, 1);
	if (!ft_strncmp(*st, "0x", 2) || !ft_strncmp(*st, "0X", 2))
		strcomb(&tmp, *st, 1, 2);
	free(*st);
	return (tmp);
}

int			pf_fo1(char **st, t_form *f)
{
	int j;

	j = 0;
	if (f->prec > 0)
		*st = apply_0(st, f);
	while (st[0][j])
	{
		ft_putchar(st[0][j]);
		j++;
	}
	while (j < f->widt)
	{
		ft_putchar(' ');
		j++;
	}
	free(*st);
	return (j);
}

int			pf_fo2(char **st, t_form *f)
{
	int		j;
	int		i;

	j = 0;
	i = 0;
	if (fl_exists(f->flag, '0') || f->prec > 0)
		*st = apply_0(st, f);
	while (j + (int)ft_strlen(*st) < (int)f->widt)
	{
		ft_putchar(' ');
		j++;
	}
	while (st[0][i])
	{
		ft_putchar(st[0][i]);
		i++;
		j++;
	}
	free(*st);
	return (j);
}

int			pf_fo3(char **st, t_form *f)
{
	int j;

	j = 0;
	if (f->prec < 0)
		f->prec = ft_strlen(*st);
	while (j < f->prec && st[0][j])
	{
		ft_putchar(st[0][j]);
		j++;
	}
	while (j < f->widt)
	{
		ft_putchar(' ');
		j++;
	}
	free(*st);
	return (j);
}

int			pf_fo4(char **st, t_form *f)
{
	int j;
	int k;

	j = 0;
	k = 0;
	if ((int)ft_strlen(*st) < (int)f->prec || f->prec < 0)
		f->prec = ft_strlen(*st);
	if (!ft_strcmp(f->lent, "c") && st[0][0] == 0)
		j++;
	while (j + f->prec < f->widt)
	{
		ft_putchar(' ');
		j++;
	}
	while (k < f->prec && st[0][k])
	{
		ft_putchar(st[0][k]);
		k++;
		j++;
	}
	if (!ft_strcmp(f->lent, "c") && st[0][0] == 0)
		ft_putchar(0);
	free(*st);
	return (j);
}
