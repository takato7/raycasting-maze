/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall_hit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:28:47 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/10 15:40:53 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

int	ft_wall_hit(t_dda *dda, t_dist dist, t_ray ray, t_cub3d *cub3d)
{
	if (cub3d->map[dda->map_row][dda->map_col] != C_WALL)
		return (0);
	if (dda->side == ROW_SIDE)
	{
		dda->wall_dist = dist.side_row - dist.delta_row;
		dda->hit_x = cub3d->pos_col + dda->wall_dist * ray.dir_col;
	}
	else
	{
		dda->wall_dist = dist.side_col - dist.delta_col;
		dda->hit_x = cub3d->pos_row + dda->wall_dist * ray.dir_row;
	}
	dda->hit_x -= (int)dda->hit_x;
	return (1);
}
