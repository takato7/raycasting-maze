/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall_collision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:42:07 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/11 17:55:27 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static int	ft_is_obstacle(t_cub3d *c, int row, int col)
{
	if (c->map[row][col] == C_WALL)
		return (1);
	if (c->map[row][col] == C_DOOR)
	{
		if (c->doors[row][col].status != OPEN)
			return (1);
	}
	return (0);
}

static int	ft_is_collided(double pos, int map_pos, double dir)
{
	if (fabs(dir) < EPSILON)
		return (0);
	if (dir > 0)
	{
		if (pos > map_pos - WALL_DISTANCE)
			return (1);
	}
	else
	{
		if (pos < map_pos + 1 + WALL_DISTANCE)
			return (1);
	}
	return (0);
}

static int	ft_front_obstacle_collision(t_collision cl, t_cub3d *c)
{
	if (ft_is_obstacle(c, cl.nexmap_row, cl.nexmap_col))
	{
		if (ft_is_collided(cl.pos_row, cl.nexmap_row, cl.add_row))
			return (1);
		if (ft_is_collided(cl.pos_col, cl.nexmap_col, cl.add_col))
			return (1);
	}
	return (0);
}

static int	ft_corner_obstacle_collision(t_collision cl, t_cub3d *c, int flip)
{
	int	side_map_row;
	int	side_map_col;

	cl.side_row *= flip;
	cl.side_col *= flip;
	side_map_row = cl.nexmap_row + cl.side_row;
	side_map_col = cl.nexmap_col + cl.side_col;
	if (ft_is_obstacle(c, side_map_row, side_map_col))
	{
		if (ft_is_collided(cl.pos_row, cl.nexmap_row, cl.add_row))
		{
			if (ft_is_collided(cl.pos_col, side_map_col, cl.side_col))
				return (1);
		}
		if (ft_is_collided(cl.pos_col, cl.nexmap_col, cl.add_col))
		{
			if (ft_is_collided(cl.pos_row, side_map_row, cl.side_row))
				return (1);
		}
	}
	return (0);
}

int	ft_wall_collision(t_cub3d *cub3d, double add_row, double add_col)
{
	t_collision	checker;

	ft_init_checker(&checker, add_row, add_col, cub3d);
	if (ft_front_obstacle_collision(checker, cub3d))
		return (1);
	if (ft_corner_obstacle_collision(checker, cub3d, 1))
		return (1);
	if (ft_corner_obstacle_collision(checker, cub3d, -1))
		return (1);
	return (0);
}
