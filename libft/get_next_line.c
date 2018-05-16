/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 22:56:45 by aherrera          #+#    #+#             */
/*   Updated: 2018/05/01 03:49:18 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static char		*r_fi(int fd, char **s)
{
	int		ret;
	char	*tmp;
	char	*r;

	tmp = ft_strnew(BUFF_SIZE + 1);
	ret = read(fd, tmp, BUFF_SIZE);
	if (ret < 0)
	{
		free(tmp);
		return (NULL);
	}
	tmp[ret] = '\0';
	if (ret != 0)
		tmp = r_fi(fd, &tmp);
	if (!s)
		r = ft_strdup(tmp);
	else
		r = ft_strjoin(*s, tmp);
	if (s)
		free(*s);
	free(tmp);
	return (r);
}

static t_buf	*create_bf(const int fd)
{
	t_buf	*buf;

	if (!(buf = (t_buf *)malloc(sizeof(t_buf))))
		return (NULL);
	if (!(buf->st = r_fi(fd, NULL)))
	{
		free(buf->st);
		free(buf);
		buf = NULL;
		return (buf);
	}
	buf->cr = buf->st;
	return (buf);
}

static void		destroy(t_buf **buf)
{
	free((*buf)->st);
	free(*buf);
	*buf = NULL;
	return ;
}

int				get_next_line(const int fd, char **line)
{
	static t_buf	*buf;
	int				i;

	if (!buf && !(buf = create_bf(fd)))
		return (-1);
	i = 0;
	while ((buf->cr)[i] != '\n' && (buf->cr)[i] != '\0')
		i++;
	if (i == 0 && (buf->cr)[i] == '\0')
	{
		destroy(&buf);
		return (0);
	}
	*line = ft_strsub(buf->cr, 0, i);
	line[0][i] = '\0';
	while (*(buf->cr) != '\n' && *(buf->cr) != '\0')
		(buf->cr)++;
	if (*(buf->cr) == '\n')
		(buf->cr)++;
	return (1);
}
