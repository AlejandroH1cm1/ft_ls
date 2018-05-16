/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 05:36:41 by aherrera          #+#    #+#             */
/*   Updated: 2018/05/13 23:17:11 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPF_H
# define LIBPF_H
# include <stdio.h>
# include "libft.h"
# include <stdarg.h>
# include <wchar.h>
# include <unistd.h>
# include <stdlib.h>
# define LL_MIN 9223372036854775808ULL
# define LL_MINS "-9223372036854775808"

typedef unsigned long long t_ull;

typedef struct	s_fo
{
	char		*fmt;
}				t_fo;

typedef struct	s_form
{
	char		*flag;
	int			widt;
	int			prec;
	char		*lent;
}				t_form;

int				ft_printf(const char *str, ...);
int				validate(char *form);
int				p_fo(va_list *av, t_form *f);
int				gn_fo(t_form *f, t_fo *tab);
int				fl_exists(char *fl, char f);
void			strcomb(char **st, char *s, int order, int n);
int				is_ec(char c);
t_ull			change(t_ull n, int len);
char			*ft_utoa(t_ull n, t_ull b, char x, int l);
char			*ft_lltoa(long long n);
void			cleanse_str(char **s);
int				is_hex(char *s);
int				is_oct(char *s);
char			*ft_ctoa(int c);
char			*ft_stoa(int c);
char			*ctos(char c);
t_form			*m_fo(void);
void			d_fo(t_form **f, int v);
int				r_fo(t_form *f, char *fo);
char			*s_fo1(va_list *av, int i);
char			*s_fo2(va_list *av, int i);
char			*s_fo3(va_list *av, int i);
char			*s_fo4(va_list *av, int i);
int				pf_fo1(char **st, t_form *f);
int				pf_fo2(char **st, t_form *f);
int				pf_fo3(char **st, t_form *f);
int				pf_fo4(char **st, t_form *f);
int				pf_foa1(t_form *f, wint_t c);
int				pf_foa2(t_form *f, wint_t c);
int				pf_fob1(t_form *f, wchar_t *s);
int				pf_fob2(t_form *f, wchar_t *s);

#endif
