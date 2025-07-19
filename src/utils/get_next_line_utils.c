/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:01:36 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/25 16:46:15 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	gnl_strlcat(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	dl;
	size_t	sl;

	dl = gnl_strlen(dst);
	sl = gnl_strlen(src);
	if (size <= dl)
		return (sl + size);
	i = 0;
	while (src[i] && i < size - dl - 1)
	{
		dst[dl + i] = src[i];
		i++;
	}
	dst[dl + i] = '\0';
	return (dl + sl);
}

int	gnl_find_new_line(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	gnl_init(t_gnl_line *l)
{
	l->line = NULL;
	l->tline = NULL;
	l->eof = 0;
	l->size = 0;
	l->cap = 0;
}

void	*gnl_cleanup(t_gnl_line *l, char *buf, int ok)
{
	if (l->tline != l->line)
	{
		free(l->tline);
		l->tline = NULL;
	}
	if ((ok == -1) || (ok == 0 && l->line[0] == '\0'))
	{
		free(l->line);
		l->line = NULL;
		l->eof = 1;
	}
	if (ok <= 0)
		buf[0] = '\0';
	return (NULL);
}
