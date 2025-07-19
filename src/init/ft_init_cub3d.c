/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cub3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:48:53 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/10 15:39:11 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	ft_init_cub3d(t_cub3d *cub3d, t_map *map)
{
	*cub3d = (t_cub3d){0};
	cub3d->map = map->map;
	cub3d->map_data = map;
}
