/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_found_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:35:41 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/15 10:51:38 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

int	ft_found_map(char *line)
{
	int	is_map;

	is_map = 0;
	while (*line)
	{
		if (*line != ' ' && *line != C_WALL)
			return (0);
		if (*line == C_WALL)
			is_map = 1;
		line++;
	}
	return (is_map);
}

static int	ft_is_empty_line(char *line)
{
	while (*line)
	{
		if (*line != ' ')
			return (0);
		line++;
	}
	return (1);
}

int	ft_end_of_map(char *line)
{
	size_t	x;

	x = 0;
	if (ft_is_empty_line(&line[x]))
		return (1);
	while (line[x])
	{
		if (!ft_is_valid_map_char(line[x]))
			return (1);
		x++;
	}
	return (0);
}
