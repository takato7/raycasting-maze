/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game_condition.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:02:23 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/15 16:20:39 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"

static int	ft_rgb_to_color(int red, int green, int blue)
{
	return ((red << 16) + (green << 8) + blue);
}

static void	ft_get_color(t_cub3d *cub3d, t_col *col)
{
	while (col)
	{
		if (col->id == COLFLOOR)
			cub3d->f_color = ft_rgb_to_color(col->r, col->g, col->b);
		else if (col->id == COLCEILING)
			cub3d->c_color = ft_rgb_to_color(col->r, col->g, col->b);
		col = col->next;
	}
}

int	ft_init_game_condition(t_cub3d *cub3d, t_file file)
{
	ft_init_player(cub3d, cub3d->map);
	if (gettimeofday(&cub3d->time, NULL) < 0)
		return (ft_error(EGETTIME, NULL));
	cub3d->prev_time = cub3d->time;
	cub3d->anim_time = cub3d->time;
	ft_get_color(cub3d, file.col);
	return (1);
}
