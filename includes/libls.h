/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:09:37 by aherrera          #+#    #+#             */
/*   Updated: 2018/05/17 14:12:16 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLS_H
# define LIBLS_H
# include "libft.h"
# include "libpf.h"
# include <grp.h>
# include <pwd.h>
# include <sys/stat.h>
# include <dirent.h>

typedef struct		s_entry
{
	char			*name;
	char			*path;
	struct stat		*lsta;
	struct s_entry	*next;
}					t_entry;

void				add_entry(t_entry **entries, char *name, char *path);
void				swp_entry(t_entry *e1, t_entry *e2);
void				dst_entry(t_entry **entries);
int					single_file(char *path, int *mode);
t_entry				*get_entries(DIR *dir, char *path);
void				get_col2(char *path, int i);
void				get_col3(uid_t uid, gid_t gid);
void				get_col5(t_entry *entry);
int					dt(struct timespec t1, struct timespec t2);
void				get_total(char *dir, int mode);
void				put_entry(t_entry *entry, int *mode);
void				ls(char *path, int *mode);

#endif
