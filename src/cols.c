/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cols.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 13:58:04 by aherrera          #+#    #+#             */
/*   Updated: 2018/05/21 14:23:47 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

void		get_col2(char *path, int i)
{
	DIR				*dir;
	struct dirent	*entry;
	struct stat		*st;
	char			*aux;

	if (!(dir = opendir(path)))
		i = 1;
	else
	{
		st = (struct stat *)malloc(sizeof(struct stat));
		path = ft_strdup(path);
		ft_strcomb(&path, "/", 0, 1);
		while ((entry = readdir(dir)))
		{
			aux = ft_strjoin(path, entry->d_name);
			lstat(aux, st);
			if (st->st_mode / (64 * 64) == 4)
				i++;
			ft_strdel(&aux);
		}
		free(st);
		ft_strdel(&path);
	}
	ft_printf("%3.d  ", i);
}

void		get_col3(uid_t uid, gid_t gid)
{
	struct passwd	*pwd;
	struct group	*grp;

	pwd = getpwuid(uid);
	grp = getgrgid(gid);
	ft_printf("%s  %s  ", pwd->pw_name, grp->gr_name);
}

void		get_col5(t_entry *entry)
{
	char	*st;
	char	*l;
	int		a;

	st = ctime(&(entry->lsta->st_mtime));
	write(1, &st[4], 12);
	ft_putchar(' ');
	if (entry->lsta->st_mode / (64 * 64) == 10)
	{
		l = (char *)malloc(100 * sizeof(char));
		a = readlink(entry->path, l, 100);
		l[a] = '\0';
		printf("%s -> %s\n", entry->name, l);
		ft_strdel(&l);
	}
	else
		ft_putendl(entry->name);
}

int			dt(struct timespec t1, struct timespec t2)
{
	if (t1.tv_sec != t2.tv_sec)
		return (t1.tv_sec - t2.tv_sec);
	if (t1.tv_nsec != t2.tv_nsec)
		return (t1.tv_nsec - t2.tv_nsec);
	return (0);
}

void		get_total(char *dir, int mode)
{
	DIR				*d;
	struct stat		*st;
	struct dirent	*entry;
	int				t;
	char			*aux;

	t = -1;
	st = (struct stat *)malloc(sizeof(struct stat));
	d = opendir(dir);
	dir = ft_strdup(dir);
	ft_strcomb(&dir, "/", 0, 1);
	while ((entry = readdir(d)))
	{
		if (t == -1)
			t = 0;
		aux = ft_strjoin(dir, entry->d_name);
		lstat(aux, st);
		if (entry->d_name[0] != '.' || mode == 1)
			t += st->st_blocks;
		ft_strdel(&aux);
	}
	t > 0 ? ft_printf("total: %d\n", t) : 1;
	free(st);
	ft_strdel(&dir);
	ft_strdel(&aux);
}
