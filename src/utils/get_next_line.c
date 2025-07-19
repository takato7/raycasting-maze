/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:56:55 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/25 16:46:07 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	gnl_get_line(t_gnl_line *l, char *buf, int fd);

static int	gnl_malloc_line_exact(t_gnl_line *l)
{
	if (l->line)
	{
		l->cap = gnl_strlen(l->line) + 1;
		l->tline = l->line;
		l->line = malloc(l->cap);
		if (!l->line)
			return (0);
		l->line[0] = '\0';
		l->size = gnl_strlcat(l->line, l->tline, l->cap);
	}
	return (1);
}

static int	gnl_malloc_line(t_gnl_line *l, char *buf)
{
	if (!l->cap)
		l->cap = gnl_strlen(buf) + 1;
	else if (l->size * 2 < l->cap)
		l->cap = SIZE_MAX;
	else
		l->cap = l->size * 2;
	l->tline = l->line;
	l->line = malloc(l->cap);
	if (!l->line)
		return (0);
	l->line[0] = '\0';
	if (l->tline && (l->cap == l->size * 2 || l->cap == SIZE_MAX))
		l->size = gnl_strlcat(l->line, l->tline, l->cap);
	free(l->tline);
	l->tline = NULL;
	return (1);
}

static int	gnl_read_line(t_gnl_line *l, char *buf, int fd)
{
	l->br = read(fd, buf, BUFFER_SIZE);
	if (l->br >= 0)
		buf[l->br] = '\0';
	if (l->br <= 0)
		return (l->br);
	if (l->size + l->br < (size_t)l->br)
		return (-1);
	l->size += l->br;
	if (l->cap <= l->size)
		if (!gnl_malloc_line(l, buf))
			return (-1);
	return (gnl_get_line(l, buf, fd));
}

static int	gnl_get_line(t_gnl_line *l, char *buf, int fd)
{
	l->i = gnl_find_new_line(buf);
	if (l->i == -1)
	{
		l->size = gnl_strlcat(l->line, buf, l->cap);
		return (gnl_read_line(l, buf, fd));
	}
	buf[l->i] = '\0';
	l->size = gnl_strlcat(l->line, buf, l->cap);
	l->line[l->size] = '\0';
	buf[0] = '\0';
	gnl_strlcat(buf, buf + l->i + 1, BUFFER_SIZE + 1);
	return (1);
}

char	*get_next_line(int fd)
{
	t_gnl_line	l;
	static char	buf[BUFFER_SIZE + 1];

	gnl_init(&l);
	if (fd < 0)
		return (NULL);
	if (!gnl_malloc_line(&l, buf))
		return (NULL);
	l.ok = gnl_get_line(&l, buf, fd);
	if (!gnl_malloc_line_exact(&l))
		return (gnl_cleanup(&l, buf, -1));
	gnl_cleanup(&l, buf, l.ok);
	if (l.eof || l.ok == -1)
		return (NULL);
	return (l.line);
}
