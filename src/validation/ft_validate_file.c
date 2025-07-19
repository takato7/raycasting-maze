/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:42:29 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/15 16:54:26 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static size_t	ft_file_name_len(const char *file_path)
{
	size_t	path_len;
	size_t	file_len;

	path_len = ft_strlen(file_path);
	file_len = 0;
	while (path_len-- > 0)
	{
		if (file_path[path_len] == '/')
			return (file_len);
		file_len++;
	}
	return (file_len);
}

static int	ft_validate_file_format(const char *file_path)
{
	size_t	file_len;
	size_t	path_len;

	path_len = ft_strlen(file_path);
	file_len = ft_file_name_len(file_path);
	if (file_len < 5)
		return (ft_error(EFILEFORMAT, file_path));
	path_len -= 4;
	if (ft_strcmp(&file_path[path_len], FORMAT))
		return (ft_error(EFILEFORMAT, file_path));
	return (1);
}

int	ft_validate_file(t_file *f)
{
	if (!ft_validate_file_format(f->file_path))
		return (0);
	if (!ft_validate_file_content(f))
		return (0);
	return (1);
}
