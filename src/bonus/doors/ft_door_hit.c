/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door_hit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:44:01 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/10 15:25:00 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static double	ft_get_door_dist(t_dist dist, t_side side)
{
	if (side == ROW_SIDE)
		return (dist.side_row - (dist.delta_row / 2));
	else
		return (dist.side_col - (dist.delta_col / 2));
}

static double	ft_get_intersec(double dist, t_ray ray, t_cub3d *c, t_side side)
{
	if (side == ROW_SIDE)
		return (c->pos_col + dist * ray.dir_col);
	else
		return (c->pos_row + dist * ray.dir_row);
}

static double	ft_get_door_pos(t_door door, t_side side)
{
	if (side == ROW_SIDE)
		return (door.col + door.open_ratio);
	else
		return (door.row + door.open_ratio);
}

static double	ft_get_door_end(t_door door, t_side side)
{
	if (side == ROW_SIDE)
		return (door.col + 1);
	else
		return (door.row + 1);
}

int	ft_door_hit(t_dda *dda, t_dist dist, t_ray ray, t_cub3d *cub3d)
{
	t_door	door;
	double	door_dist;
	double	intsec;
	double	door_pos;
	double	door_end;

	if (cub3d->map[dda->map_row][dda->map_col] != C_DOOR)
		return (0);
	door = cub3d->doors[dda->map_row][dda->map_col];
	door_dist = ft_get_door_dist(dist, dda->side);
	intsec = ft_get_intersec(door_dist, ray, cub3d, dda->side);
	door_pos = ft_get_door_pos(door, dda->side);
	door_end = ft_get_door_end(door, dda->side);
	if (intsec - door_pos < EPSILON || intsec - door_end > EPSILON)
		return (0);
	dda->wall_dist = door_dist;
	dda->hit_x = intsec - door_pos;
	return (1);
}
