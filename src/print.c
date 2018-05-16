/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 13:58:02 by aherrera          #+#    #+#             */
/*   Updated: 2018/05/16 14:40:23 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

static void	get_perm(int mode)
{
	char	*perm;
	int		i;
	int		aux;

	perm = ft_strnew(10);
	ft_memset((void *)perm, '-', 10);
	i = 9;
	if (mode / (64 * 64) == 4)
		perm[0] = 'd';
	if (mode / (64 * 64) == 10)
		perm[0] = 'l';
	while (i > 0)
	{
		aux = mode % 8;
		if (aux % 2 == 1)
			perm[i] = 'x';
		if (aux > 3)
			perm[i - 2] = 'r';
		if (aux == 2 || aux == 3 || aux == 7 || aux == 6)
			perm[i - 1] = 'w';
		mode = mode / 8;
		i -= 3;
	}
	ft_printf("%s ", perm);
	ft_strdel(&perm);
}

static void	order_e(t_entry *entries, int *m)
{
	t_entry	*tmp;
	t_entry	*tmp2;

	tmp = entries;
	while (tmp)
	{
		tmp2 = entries;
		while (tmp2)
		{
			if (((m[3] == -2 && dt(tmp2->lsta->st_mtimespec,
					tmp->lsta->st_mtimespec) > 0)
			|| (m[3] == 2 && dt(tmp2->lsta->st_mtimespec,
					tmp->lsta->st_mtimespec) < 0)
			|| (m[3] == -1 && ft_strcmp(tmp2->name, tmp->name) < 0)
			|| (m[3] == 1 && ft_strcmp(tmp2->name, tmp->name) > 0)))
			{
				swp_entry(tmp, tmp2);
				tmp2 = entries;
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

void		put_entry(t_entry *entry, int *mode)
{
	if (mode[0] == 0 || mode[0] == 2)
		ft_putendl(entry->name);
	if (mode[0] == 1)
	{
		get_perm(entry->lsta->st_mode);
		get_col2(entry->path, 0);
		get_col3(entry->lsta->st_uid, entry->lsta->st_gid);
		ft_printf("%5.1d ", entry->lsta->st_size);
		get_col5(entry);
	}
}

static void	print_e(char *dir, t_entry *entries, int *mode)
{
	t_entry	*tmp;

	tmp = entries;
	order_e(entries, mode);
	if (mode[0] == 1)
		get_total(dir, mode[1]);
	mode[4] == 1 ? ft_printf("%s:\n", dir) : 1;
	while (entries)
	{
		if (mode[1] == 1 || (mode[1] == 0 && entries->name[0] != '.'))
			put_entry(entries, mode);
		entries = entries->next;
	}
	if (mode[2] == 1)
		while (tmp)
		{
			if (tmp->lsta->st_mode / (64 * 64) == 4 && tmp->name[0] != '.')
			{
				ft_printf("\n%s:\n", tmp->path);
				ls(tmp->path, mode);
			}
			tmp = tmp->next;
		}
	mode[4] == 1 ? ft_printf("\n") : 1;
}

void		ls(char *path, int *mode)
{
	DIR		*dir;
	t_entry	*entries;

	if (!(dir = opendir(path)))
	{
		if (!single_file(path, mode))
			ft_printf("ft_ls: %s: No such file or directory\n", path);
		return ;
	}
	entries = get_entries(dir, path);
	print_e(path, entries, mode);
	dst_entry(&entries);
	closedir(dir);
}
