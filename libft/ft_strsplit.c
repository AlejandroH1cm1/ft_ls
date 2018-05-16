/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:25:00 by aherrera          #+#    #+#             */
/*   Updated: 2018/05/07 15:32:58 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*word(char *str, char c)
{
	char	*w;
	int		i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	w = (char *)malloc((i + 1) * sizeof(char));
	i = 0;
	while (*str != c && *str != '\0' && *str != '\n')
	{
		w[i] = *str;
		str++;
		i++;
	}
	w[i] = '\0';
	return (w);
}

static int	c_w(char *str, char c)
{
	int i;
	int w;

	if (str[0] == '\0')
		return (0);
	i = 0;
	w = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c || str[i] == '\n')
			i++;
		if (str[i] != c && str[i] != '\0' && str[i] != '\n')
		{
			while (str[i] != c && str[i] != '\0' && str[i] != '\n')
				i++;
			w++;
		}
	}
	return (w);
}

char		**ft_strsplit(char *str, char c)
{
	char	**r;
	int		i;
	int		n;

	if (!str)
		return (0);
	i = 0;
	n = c_w(str, c);
	if (!(r = (char **)malloc((n + 1) * sizeof(char *))))
		return (NULL);
	if (n > 0)
	{
		while (*str != '\0' && i < n)
		{
			while (*str == c || *str == '\n')
				str++;
			r[i] = word(str, c);
			i++;
			while (*str != c && *str != '\0' && *str != '\n')
				str++;
		}
	}
	r[i] = NULL;
	return (r);
}
