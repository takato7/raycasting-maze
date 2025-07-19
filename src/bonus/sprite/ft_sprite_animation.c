/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_animation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:27:20 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/10 15:27:09 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	ft_change_sprite_id(t_sprite *sprite)
{
	if (sprite->id == SPRITE_0)
		sprite->id = SPRITE_1;
	else if (sprite->id == SPRITE_1)
		sprite->id = SPRITE_2;
	else if (sprite->id == SPRITE_2)
		sprite->id = SPRITE_3;
	else
		sprite->id = SPRITE_0;
}

static int	ft_is_image_change(t_cub3d *cub3d, int milsec)
{
	size_t	i;

	if (milsec < ANIMATION_SPEED_MILISEC)
		return (0);
	i = 0;
	while (i < cub3d->num_sprite)
		ft_change_sprite_id(&cub3d->sprite[i++]);
	return (1);
}

int	ft_sprite_animation(t_cub3d *cub3d)
{
	int	milsec;

	milsec = ft_get_time_diff_sec(cub3d->time, cub3d->anim_time) * 1000;
	if (ft_is_image_change(cub3d, milsec))
		cub3d->anim_time = cub3d->time;
	return (1);
}
