/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door_side_wall.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:07:21 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/10 18:18:05 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	ft_door_side_wall(t_dda *dda, t_cub3d *cub3d)
{
	if (cub3d->map[dda->map_row][dda->map_col] != C_WALL)
		return (0);
	if (dda->side == ROW_SIDE)
	{
		if (cub3d->map[dda->map_row - dda->step_row][dda->map_col] == C_DOOR)
			return (1);
	}
	else
	{
		if (cub3d->map[dda->map_row][dda->map_col - dda->step_col] == C_DOOR)
			return (1);
	}
	return (0);
}
