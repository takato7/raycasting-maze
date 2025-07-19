/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:54:56 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/15 11:03:26 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"

static void	ft_set_player_dir(t_cub3d *cub3d, char c)
{
	if (c == C_PLAYER_N)
		cub3d->dir_row = -1;
	if (c == C_PLAYER_E)
		cub3d->dir_col = 1;
	if (c == C_PLAYER_S)
		cub3d->dir_row = 1;
	if (c == C_PLAYER_W)
		cub3d->dir_col = -1;
	cub3d->plane_row = cub3d->fov_data.fov_factor * cub3d->dir_col;
	cub3d->plane_col = -cub3d->fov_data.fov_factor * cub3d->dir_row;
}

static void	ft_get_player_pos(t_pos *player, char **map)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_found_player(map[y][x]))
			{
				player->y = y;
				player->x = x;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	ft_init_player(t_cub3d *cub3d, char **map)
{
	t_pos	player;

	ft_get_player_pos(&player, cub3d->map);
	cub3d->pos_col = (double)player.x + 0.5;
	cub3d->pos_row = (double)player.y + 0.5;
	ft_set_player_dir(cub3d, map[player.y][player.x]);
}
