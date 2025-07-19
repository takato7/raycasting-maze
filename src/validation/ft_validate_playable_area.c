/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_playable_area.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:00:23 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/09 14:03:42 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

int	ft_validate_playable_area(t_map_val *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == ' ')
			{
				map->valid = 0;
				return (map->valid);
			}
			x++;
		}
		y++;
	}
	return (map->valid);
}
