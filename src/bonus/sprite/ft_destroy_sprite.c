/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_sprite.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:05:14 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/10 15:26:52 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	ft_destroy_sprite(t_cub3d *cub3d)
{
	if (cub3d->sprite)
		free(cub3d->sprite);
	if (cub3d->wall_dists)
		free(cub3d->wall_dists);
}
