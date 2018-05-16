/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 01:45:52 by aherrera          #+#    #+#             */
/*   Updated: 2018/03/23 15:42:28 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.h"

t_form			*m_fo(void)
{
	t_form	*f;

	f = (t_form *)malloc(sizeof(t_form));
	f->flag = (char *)ft_memalloc(6 * sizeof(char));
	f->lent = (char *)ft_memalloc(4 * sizeof(char));
	f->widt = -1;
	f->prec = -1;
	return (f);
}

void			d_fo(t_form **f, int v)
{
	free((*f)->flag);
	free((*f)->lent);
	free(*f);
	*f = NULL;
	if (v == 0)
		return ;
	*f = m_fo();
}

int				r_fo(t_form *f, char *fo)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (fo[i] == ' ' || fo[i] == '+' || fo[i] == '-' || fo[i] == '0' ||
			fo[i] == '#')
		f->flag[j++] = fo[i++];
	f->widt = ft_atoi(&fo[i]);
	while (fo[i] >= '0' && fo[i] <= '9')
		i++;
	if (fo[i] == '.')
		f->prec = ft_atoi(&fo[i + 1]);
	while ((fo[i] >= '0' && fo[i] <= '9') || fo[i] == '.')
		i++;
	j = 0;
	while (fo[i] == 'h' || fo[i] == 'l' || fo[i] == 'j' || fo[i] == 'z')
		f->lent[j++] = fo[i++];
	f->lent[j] = fo[i++];
	if (f->lent[0] == 0)
		return (0);
	return (i);
}

static int		inner(va_list *av, char *form, int i, int j)
{
	int		k;
	t_form	*f;

	f = m_fo();
	while (form[++i] != '\0')
		if (form[i] == '%')
		{
			k = r_fo(f, &form[i + 1]);
			i = i + k;
			j = j + p_fo(av, f);
			d_fo(&f, 1);
		}
		else
		{
			j++;
			ft_putchar(form[i]);
		}
	d_fo(&f, 0);
	return (j);
}

int				ft_printf(const char *str, ...)
{
	va_list	av;
	int		i;

	va_start(av, (char *)str);
	i = inner(&av, (char *)str, -1, 0);
	va_end(av);
	return (i);
}
