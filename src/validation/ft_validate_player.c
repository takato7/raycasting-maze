/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 10:35:27 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/10 16:16:41 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static size_t	ft_count_players(char **map)
{
	size_t	y;
	size_t	x;
	size_t	nplayers;

	nplayers = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_found_player(map[y][x]))
				nplayers++;
			x++;
		}
		y++;
	}
	return (nplayers);
}

int	ft_validate_player(t_map *map)
{
	if (ft_count_players(map->map) != 1)
		return (0);
	return (1);
}
