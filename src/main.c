/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 13:58:56 by aherrera          #+#    #+#             */
/*   Updated: 2018/05/17 14:09:14 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

static void	check(char *str, int *mode)
{
	if (ft_strchr(str, 'l'))
		mode[0] = 1;
	if (ft_strchr(str, '1'))
		mode[0] = 2;
	if (ft_strchr(str, 'a'))
		mode[1] = 1;
	if (ft_strchr(str, 'R'))
		mode[2] = 1;
	if (ft_strchr(str, 't'))
		mode[3] = 2;
	if (ft_strchr(str, 'r'))
		mode[3] = -mode[3];
}

static int	*get_mode(char **av, int *i, int ac)
{
	int	*mode;

	mode = (int *)malloc(5 * sizeof(int));
	mode[0] = 0;
	mode[1] = 0;
	mode[2] = 0;
	mode[3] = 1;
	mode[4] = 0;
	while (av[*i] && av[*i][0] == '-' && av[*i][1])
	{
		check(av[*i], mode);
		*i = *i + 1;
	}
	if (ac > *i + 1)
		mode[4] = 1;
	return (mode);
}

int			main(int ac, char **av)
{
	int	i;
	int	*mode;
	int l;

	i = 1;
	mode = get_mode(av, &i, ac);
	l = 0;
	if (ac == i)
	{
		av[i] = ft_strdup(".");
		av[i + 1] = NULL;
		l = i;
	}
	while (av[i])
	{
		ls(av[i], mode);
		i++;
	}
	if (l != 0)
		ft_strdel(&av[l]);
	free(mode);
	return (0);
}
