/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 17:41:51 by aherrera          #+#    #+#             */
/*   Updated: 2018/05/17 14:07:38 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

void	swp_entry(t_entry *e1, t_entry *e2)
{
	char			*naux;
	char			*paux;
	struct stat		*laux;

	naux = e1->name;
	paux = e1->path;
	laux = e1->lsta;
	e1->name = e2->name;
	e1->path = e2->path;
	e1->lsta = e2->lsta;
	e2->name = naux;
	e2->path = paux;
	e2->lsta = laux;
}

void	add_entry(t_entry **entries, char *name, char *path)
{
	t_entry *tmp;

	if (!*entries)
	{
		*entries = (t_entry *)malloc(sizeof(t_entry));
		(*entries)->name = ft_strdup(name);
		(*entries)->path = ft_strjoin(path, name);
		(*entries)->lsta = (struct stat *)malloc(sizeof(struct stat));
		lstat((*entries)->path, (*entries)->lsta);
		(*entries)->next = NULL;
		return ;
	}
	tmp = *entries;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (t_entry *)malloc(sizeof(t_entry));
	tmp = tmp->next;
	tmp->name = ft_strdup(name);
	tmp->path = ft_strjoin(path, name);
	tmp->lsta = (struct stat *)malloc(sizeof(struct stat));
	lstat(tmp->path, tmp->lsta);
	tmp->next = NULL;
}

t_entry	*get_entries(DIR *dir, char *path)
{
	struct dirent	*entry;
	t_entry			*entries;
	char			*r_path;

	entries = NULL;
	r_path = ft_strjoin(path, "/");
	while ((entry = readdir(dir)))
		add_entry(&entries, entry->d_name, r_path);
	free(r_path);
	return (entries);
}

void	dst_entry(t_entry **entries)
{
	if (!*entries)
		return ;
	if ((*entries)->next)
		dst_entry(&((*entries)->next));
	free((*entries)->name);
	free((*entries)->path);
	free((*entries)->lsta);
	free(*entries);
	*entries = NULL;
}

int		single_file(char *path, int *mode)
{
	t_entry		*single;

	single = (t_entry *)malloc(sizeof(t_entry));
	single->lsta = (struct stat *)malloc(sizeof(struct stat));
	single->path = ft_strdup(path);
	single->name = ft_strdup(path);
	single->next = NULL;
	if (lstat(path, single->lsta) == -1)
	{
		dst_entry(&single);
		return (0);
	}
	put_entry(single, mode);
	dst_entry(&single);
	return (1);
}
