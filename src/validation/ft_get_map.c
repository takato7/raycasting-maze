/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:56:26 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/15 15:49:45 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static size_t	ft_get_map_height(t_file *f, size_t y)
{
	size_t	height;

	height = 0;
	while (f->file[y] && !ft_end_of_map(f->file[y]))
	{
		y++;
		height++;
	}
	return (height);
}

static size_t	ft_get_map_width(t_file *f, size_t y)
{
	size_t	line_width;
	size_t	largest_width;

	line_width = 0;
	largest_width = 0;
	while (f->file[y] && !ft_end_of_map(f->file[y]))
	{
		line_width = ft_get_line_length(f->file[y]);
		if (line_width > largest_width)
			largest_width = line_width;
		y++;
	}
	return (largest_width);
}

static void	ft_copy_map_line(t_map *map, char *line, size_t i)
{
	size_t	line_len;

	line_len = ft_get_line_length(line);
	ft_strlcpy(map->map[i], line, line_len + 1);
	if (line_len < map->width)
	{
		while (line_len < map->width)
			map->map[i][line_len++] = ' ';
		map->map[i][line_len] = '\0';
	}
}

static int	ft_post_map_content(t_file *f, size_t y)
{
	size_t	x;

	while (f->file[y])
	{
		x = 0;
		while (f->file[y][x])
		{
			if (f->file[y][x] != ' ')
				return (ft_error(EUNEXPECTED, &f->file[y][x]));
			x++;
		}
		y++;
	}
	return (1);
}

int	ft_get_map(t_file *f, size_t y)
{
	t_map	map;
	size_t	i;

	map.height = ft_get_map_height(f, y);
	map.width = ft_get_map_width(f, y);
	if (!ft_malloc_map(&map))
		return (0);
	i = 0;
	while (f->file[y] && !ft_end_of_map(f->file[y]))
	{
		ft_copy_map_line(&map, f->file[y], i);
		y++;
		i++;
	}
	if (!ft_post_map_content(f, y))
		return (0);
	f->map = map;
	return (1);
}
