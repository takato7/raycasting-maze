/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:42:05 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/15 15:34:08 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

int	ft_is_valid_map_char(char c)
{
	if (c == ' ')
		return (1);
	if (c == C_FLOOR)
		return (1);
	if (c == C_WALL)
		return (1);
	if (c == C_PLAYER_N)
		return (1);
	if (c == C_PLAYER_E)
		return (1);
	if (c == C_PLAYER_S)
		return (1);
	if (c == C_PLAYER_W)
		return (1);
	if (c == C_SPRITE)
		return (1);
	if (c == C_DOOR)
		return (1);
	return (0);
}

int	ft_only_trailing_spaces(char *line)
{
	while (*line)
	{
		if (*line != ' ')
			return (0);
		line++;
	}
	return (1);
}

size_t	ft_get_line_length(char *line)
{
	size_t	line_len;

	line_len = 0;
	while (*line && ft_is_valid_map_char(*line))
	{
		if (*line == ' ' && ft_only_trailing_spaces(line))
			return (line_len);
		line++;
		line_len++;
	}
	return (line_len);
}

int	ft_malloc_map(t_map *map)
{
	size_t	line;

	map->map = malloc(sizeof(char *) * (map->height + 1));
	if (!map->map)
		return (ft_error(EMALLOC, NULL));
	line = 0;
	while (line < map->height)
	{
		map->map[line] = malloc(map->width + 1);
		if (!map->map[line])
		{
			ft_cleanup_str_array(map->map, line);
			return (ft_error(EMALLOC, NULL));
		}
		line++;
	}
	map->map[map->height] = NULL;
	return (1);
}
