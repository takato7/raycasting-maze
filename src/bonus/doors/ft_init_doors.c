/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_doors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:59:30 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/15 15:31:22 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	ft_set_zero(t_door *door, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		door[i++] = (t_door){0};
}

static void	ft_set_doors_info(t_door *door, t_map map, size_t i, size_t j)
{
	if (map.map[i - 1][j] == C_WALL && map.map[i + 1][j] == C_WALL)
	{
		door->dir = ROW_SIDE;
		door->row = i;
		door->col = j + 0.5;
	}
	else if (map.map[i][j - 1] == C_WALL && map.map[i][j + 1] == C_WALL)
	{
		door->dir = COL_SIDE;
		door->row = i + 0.5;
		door->col = j;
	}
	door->status = CLOSE;
	door->texid = DOOR;
	door->open_ratio = 0;
}

static void	ft_loading_doors(t_door **doors, t_map map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map.map[i])
	{
		j = 0;
		while (map.map[i][j])
		{
			if (map.map[i][j] == C_DOOR)
				ft_set_doors_info(&doors[i][j], map, i, j);
			j++;
		}
		i++;
	}
}

int	ft_init_doors(t_cub3d *cub3d, t_map map)
{
	size_t	i;
	int		flag;

	cub3d->doors = (t_door **)malloc(sizeof(t_door *) * (map.height + 1));
	if (!cub3d->doors)
		return (ft_error(EMALLOC, NULL));
	i = 0;
	flag = 0;
	while (i < map.height)
	{
		cub3d->doors[i] = (t_door *)malloc(sizeof(t_door) * (map.width + 1));
		if (!cub3d->doors[i])
			flag = 1;
		else
			ft_set_zero(cub3d->doors[i], map.width);
		i++;
	}
	cub3d->doors[map.height] = NULL;
	if (flag)
		return (ft_error(EMALLOC, NULL));
	ft_loading_doors(cub3d->doors, map);
	cub3d->door_act = 1;
	return (1);
}
