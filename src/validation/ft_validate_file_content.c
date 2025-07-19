/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_file_content.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:58:08 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/15 15:36:34 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static int	ft_get_num_lines(int fd, t_file *f)
{
	static ssize_t	br;
	static char		buffer[1];

	br = read(fd, buffer, 1);
	if (br == -1)
		return (close(fd), ft_error(ERRNO, NULL));
	if (br == 0)
		return (close(fd), 1);
	if (*buffer == '\n')
		f->nlines++;
	return (ft_get_num_lines(fd, f));
}

static int	ft_get_file_content(int fd, t_file *f)
{
	size_t	line;
	int		gnl_error;

	f->file = malloc(sizeof(char *) * (f->nlines + 1));
	if (!f->file)
		return (close(fd), ft_error(EMALLOC, NULL));
	line = 0;
	while (line <= f->nlines)
		f->file[line++] = NULL;
	line = 0;
	gnl_error = 0;
	while (line < f->nlines)
	{
		f->file[line] = get_next_line(fd);
		if (!f->file[line] && line != f->nlines - 1)
			gnl_error = 1;
		line++;
	}
	close(fd);
	if (gnl_error)
		return (0);
	return (1);
}

int	ft_validate_file_content(t_file *f)
{
	int	fd;

	if (!ft_open(f->file_path, &fd))
		return (0);
	if (!ft_get_num_lines(fd, f))
		return (0);
	if (!ft_open(f->file_path, &fd))
		return (0);
	if (!ft_get_file_content(fd, f))
		return (0);
	if (!ft_validate_elements(f))
		return (0);
	return (1);
}
