/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door_positioning.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 20:06:51 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/10 15:25:06 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	ft_change_open_ratio(t_door *door, t_cub3d *cub3d)
{
	if (door->status == OPENING)
	{
		door->open_ratio += cub3d->frame_time;
		if (door->open_ratio - 1 > EPSILON)
		{
			door->open_ratio = 1;
			door->status = OPEN;
		}
	}
	else if (door->status == CLOSING)
	{
		door->open_ratio -= cub3d->frame_time;
		if (door->open_ratio < EPSILON)
		{
			door->open_ratio = 0;
			door->status = CLOSE;
		}
	}
}

void	ft_door_positioning(t_cub3d *cub3d)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (cub3d->map[i])
	{
		j = 0;
		while (cub3d->map[i][j])
		{
			if (cub3d->map[i][j] == C_DOOR)
				ft_change_open_ratio(&cub3d->doors[i][j], cub3d);
			j++;
		}
		i++;
	}
}
