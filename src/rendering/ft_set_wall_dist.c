/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_wall_dist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:25:30 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/10 15:40:43 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

void	ft_set_wall_dist(t_cub3d *cub3d, double wall_dist, int win_x)
{
	cub3d->wall_dist = wall_dist;
	if (cub3d->wall_dists)
		cub3d->wall_dists[win_x] = wall_dist;
}
