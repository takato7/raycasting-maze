/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:08:58 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/15 15:31:33 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static size_t	ft_get_num_sprite(char **map)
{
	size_t	num;
	int		i;
	int		j;

	num = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == C_SPRITE)
				num++;
			j++;
		}
		i++;
	}
	return (num);
}

static void	ft_set_sprite_info(t_sprite *sprite, int row, int col)
{
	sprite->id = SPRITE_0;
	sprite->map_row = row;
	sprite->map_col = col;
	sprite->pos_row = row + 0.5;
	sprite->pos_col = col + 0.5;
	sprite->x_on_camera = 0;
	sprite->y_on_camera = 0;
	sprite->x_on_win = 0;
	sprite->y_on_win = 0;
	sprite->hight = 0;
	sprite->width = 0;
	sprite->dist = 0;
}

static void	ft_get_sprite_info(t_sprite *sprite, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == C_SPRITE)
				ft_set_sprite_info(sprite++, i, j);
			j++;
		}
		i++;
	}
}

static void	ft_set_zeros(double *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
		arr[i++] = 0;
}

int	ft_init_sprite(t_cub3d *cub3d)
{
	cub3d->num_sprite = ft_get_num_sprite(cub3d->map);
	if (!cub3d->num_sprite)
		return (1);
	cub3d->sprite = malloc(sizeof(t_sprite) * (cub3d->num_sprite + 1));
	cub3d->wall_dists = malloc(sizeof(double) * cub3d->win_x);
	if (!cub3d->sprite || !cub3d->wall_dists)
	{
		free(cub3d->sprite);
		free(cub3d->wall_dists);
		return (ft_error(EMALLOC, NULL));
	}
	ft_get_sprite_info(cub3d->sprite, cub3d->map);
	ft_set_zeros(cub3d->wall_dists, cub3d->win_x);
	return (1);
}
