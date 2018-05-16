/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_fo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 01:21:45 by aherrera          #+#    #+#             */
/*   Updated: 2018/03/25 05:34:19 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.h"

char	*s_fo4(va_list *av, int i)
{
	if (i == 36)
		return (ft_utoa((t_ull)va_arg(*av, unsigned long), 16, 'A', 2));
	if (i == 37)
		return (ft_utoa(va_arg(*av, t_ull), 16, 'A', 3));
	if (i == 38)
		return (ft_utoa((t_ull)va_arg(*av, unsigned int), 16, 'A', -1));
	if (i == 39)
		return (ft_utoa((t_ull)va_arg(*av, unsigned int), 16, 'A', -2));
	if (i == 40)
		return (ft_utoa((t_ull)va_arg(*av, uintmax_t), 16, 'A', 3));
	if (i == 41)
		return (ft_utoa((t_ull)va_arg(*av, size_t), 16, 'A', 1));
	if (i == 45)
		return (ft_utoa((t_ull)va_arg(*av, void *), 16, 'a', 3));
	if (i == 46)
		return (ctos(va_arg(*av, int)));
	if (i == 49)
		return (ft_strdup(va_arg(*av, char *)));
	if (i == 52)
		return (ft_strdup("%"));
	return (NULL);
}

char	*s_fo3(va_list *av, int i)
{
	if (i == 24)
		return (ft_utoa((t_ull)va_arg(*av, unsigned int), 10, 0, -1));
	if (i == 25)
		return (ft_utoa((t_ull)va_arg(*av, unsigned int), 10, 0, -2));
	if (i == 26)
		return (ft_utoa((t_ull)va_arg(*av, uintmax_t), 10, 0, 3));
	if (i == 27)
		return (ft_utoa((t_ull)va_arg(*av, size_t), 10, 0, 3));
	if (i == 28)
		return (ft_utoa((t_ull)va_arg(*av, unsigned int), 16, 'a', 0));
	if (i == 29)
		return (ft_utoa((t_ull)va_arg(*av, unsigned long), 16, 'a', 2));
	if (i == 30)
		return (ft_utoa(va_arg(*av, t_ull), 16, 'a', 3));
	if (i == 31)
		return (ft_utoa((t_ull)va_arg(*av, unsigned int), 16, 'a', -1));
	if (i == 32)
		return (ft_utoa((t_ull)va_arg(*av, unsigned int), 16, 'a', -2));
	if (i == 33)
		return (ft_utoa((t_ull)va_arg(*av, uintmax_t), 16, 'a', 3));
	if (i == 34)
		return (ft_utoa((t_ull)va_arg(*av, size_t), 16, 'a', 1));
	if (i == 35)
		return (ft_utoa((t_ull)va_arg(*av, unsigned int), 16, 'A', 0));
	return (NULL);
}

char	*s_fo2(va_list *av, int i)
{
	if (i == 14)
		return (ft_utoa((t_ull)va_arg(*av, unsigned int), 8, 0, 0));
	if (i == 15 || i == 43)
		return (ft_utoa((t_ull)va_arg(*av, unsigned long), 8, 0, 2));
	if (i == 16)
		return (ft_utoa(va_arg(*av, t_ull), 8, 0, 3));
	if (i == 17)
		return (ft_utoa((t_ull)va_arg(*av, unsigned int), 8, 0, -1));
	if (i == 18)
		return (ft_utoa((t_ull)va_arg(*av, unsigned int), 8, 0, -2));
	if (i == 19)
		return (ft_utoa((t_ull)va_arg(*av, uintmax_t), 8, 0, 3));
	if (i == 20)
		return (ft_utoa((t_ull)va_arg(*av, size_t), 8, 0, 1));
	if (i == 21)
		return (ft_utoa((t_ull)va_arg(*av, unsigned int), 10, '0', 0));
	if (i == 22 || i == 44)
		return (ft_utoa((t_ull)va_arg(*av, unsigned long), 10, '0', 2));
	if (i == 23)
		return (ft_utoa(va_arg(*av, t_ull), 10, '0', 3));
	return (NULL);
}

char	*s_fo1(va_list *av, int i)
{
	if (i == 0 || i == 7)
		return (ft_lltoa((long long)va_arg(*av, int)));
	if (i == 1 || i == 42 || i == 8)
		return (ft_lltoa((long long)va_arg(*av, long)));
	if (i == 2 || i == 9)
		return (ft_lltoa(va_arg(*av, long long)));
	if (i == 3 || i == 10)
		return (ft_stoa(va_arg(*av, int)));
	if (i == 4 || i == 11)
		return (ft_ctoa(va_arg(*av, int)));
	if (i == 5 || i == 12)
		return (ft_lltoa((long long)va_arg(*av, intmax_t)));
	if (i == 6 || i == 13)
		return (ft_lltoa((long long)va_arg(*av, size_t)));
	return (NULL);
}
