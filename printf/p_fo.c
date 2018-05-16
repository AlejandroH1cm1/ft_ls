/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_fo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 02:48:16 by aherrera          #+#    #+#             */
/*   Updated: 2018/03/25 05:12:00 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.h"
#include "form.h"

static char	*apply_flags(char **st, t_form *f, int i)
{
	if (fl_exists(f->flag, '#') && (ft_strcmp(*st, "0") != 0))
	{
		if ((i >= 14 && i <= 20) || i == 43)
			strcomb(st, "0", 1, 1);
		if (i >= 28 && i <= 34)
			strcomb(st, "0x", 1, 2);
		if (i >= 35 && i <= 41)
			strcomb(st, "0X", 1, 2);
	}
	if (fl_exists(f->flag, ' ') && i < 14 && !fl_exists(f->flag, '+'))
		if (st[0][0] != '-')
			strcomb(st, " ", 1, 1);
	if (fl_exists(f->flag, '+') && i < 14)
		if (st[0][0] != '-')
			strcomb(st, "+", 1, 1);
	if (f->prec == 0 && !ft_strcmp("0", *st) && (i < 45))
		if ((i > 13 && i < 21 && !fl_exists(f->flag, '#')) || i < 14 || i > 20)
			st[0][0] = '\0';
	if (f->prec == 0 && i == 45 && !ft_strcmp(*st, "0x0"))
		st[0][2] = '\0';
	if (f->prec == 0 && (i == 52 || i == 45))
		f->prec = -1;
	return (*st);
}

static char	*s_fo(va_list *av, int i)
{
	char *st;

	st = s_fo1(av, i);
	if (st == NULL)
		st = s_fo2(av, i);
	if (st == NULL)
		st = s_fo3(av, i);
	if (st == NULL)
		st = s_fo4(av, i);
	if (!st && i == 49)
		st = ft_strdup("(null)");
	if (i == 45)
		strcomb(&st, "0x", 1, 2);
	return (st);
}

static int	p_wfo(va_list *av, t_form *f, int gn)
{
	int i;

	i = 0;
	if ((gn == 47 || gn == 48) && fl_exists(f->flag, '-'))
		return (pf_foa1(f, va_arg(*av, wint_t)));
	if ((gn == 47 || gn == 48) && !fl_exists(f->flag, '-'))
		return (pf_foa2(f, va_arg(*av, wint_t)));
	if ((gn == 50 || gn == 51) && fl_exists(f->flag, '-'))
		return (pf_fob1(f, va_arg(*av, wchar_t *)));
	if ((gn == 50 || gn == 51) && !fl_exists(f->flag, '-'))
		return (pf_fob2(f, va_arg(*av, wchar_t *)));
	if (gn == 46 && fl_exists(f->flag, '-'))
		return (pf_foa1(f, (char)va_arg(*av, int)));
	if (gn == 46 && !fl_exists(f->flag, '-'))
		return (pf_foa2(f, (char)va_arg(*av, int)));
	return (0);
}

int			p_fo(va_list *av, t_form *f)
{
	char	*st;
	int		gn;

	gn = gn_fo(f, g_fo);
	if (gn == 53)
		return (0);
	if (gn == 54)
		st = ft_strdup(f->lent);
	if (gn == 54 && fl_exists(f->flag, '-'))
		return (pf_fo3(&st, f));
	if (gn == 54 && !fl_exists(f->flag, '-'))
		return (pf_fo4(&st, f));
	if (gn == 46 || gn == 47 || gn == 48 || gn == 50 || gn == 51)
		return (p_wfo(av, f, gn));
	st = s_fo(av, gn);
	st = apply_flags(&st, f, gn);
	if (fl_exists(f->flag, '-') && gn < 46)
		return (pf_fo1(&st, f));
	if (fl_exists(f->flag, '-') && gn > 46)
		return (pf_fo3(&st, f));
	if (!fl_exists(f->flag, '-') && gn < 46)
		return (pf_fo2(&st, f));
	if (!fl_exists(f->flag, '-') && gn > 46)
		return (pf_fo4(&st, f));
	return (0);
}
