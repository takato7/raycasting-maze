/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cell_id.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:38:21 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/15 11:03:14 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static int	ft_offset(int pixel_pos, t_mmap *mmap)
{
	int	cell_offset;

	cell_offset = pixel_pos / mmap->cell_size;
	return (mmap->vis_dist - cell_offset);
}

static int	ft_door_cell_id(char **map, int y, int x)
{
	if (map[y][x] == C_DOOR)
	{
		if (map[y][x - 1] == C_WALL && map[y][x + 1] == C_WALL)
			return (CLOSED_DOOR_CELL_H);
		return (CLOSED_DOOR_CELL_V);
	}
	if (map[y][x - 1] == C_WALL && map[y][x + 1] == C_WALL)
		return (OPEN_DOOR_CELL_H);
	return (OPEN_DOOR_CELL_V);
}

static int	ft_cell_id(t_mmap *mmap, int y, int x)
{
	if (y < 0 || x < 0)
		return (BACKGROUND_CELL);
	if (y >= mmap->map_height || x >= mmap->map_width)
		return (BACKGROUND_CELL);
	if (mmap->map[y][x] == C_FLOOR)
		return (FLOOR_CELL);
	if (mmap->map[y][x] == C_WALL)
		return (WALL_CELL);
	if (mmap->map[y][x] == C_SPRITE)
		return (SQUIRREL_CELL);
	if (mmap->map[y][x] == C_PLAYER_N)
		return (FLOOR_CELL);
	if (mmap->map[y][x] == C_PLAYER_E)
		return (FLOOR_CELL);
	if (mmap->map[y][x] == C_PLAYER_S)
		return (FLOOR_CELL);
	if (mmap->map[y][x] == C_PLAYER_W)
		return (FLOOR_CELL);
	if (mmap->map[y][x] == C_DOOR)
		return (ft_door_cell_id(mmap->map, y, x));
	return (BACKGROUND_CELL);
}

int	ft_get_cell_id(int line, int i, t_mmap *mmap)
{
	int	x;
	int	y;
	int	x_offset;
	int	y_offset;

	x_offset = ft_offset(i / (mmap->img.bpp / 8), mmap);
	y_offset = ft_offset(line, mmap);
	if (x_offset == 0 && y_offset == 0)
		return (PLAYER_CELL);
	y = (int)*mmap->pos_y - y_offset;
	x = (int)*mmap->pos_x - x_offset;
	return (ft_cell_id(mmap, y, x));
}
