/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_rotation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:05:29 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/10 15:15:03 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_action.h"

void	ft_vector_rotation(t_cub3d *cub3d, double x)
{
	double	tmp;

	tmp = cub3d->dir_row;
	cub3d->dir_row = cub3d->dir_row * cos(x) - cub3d->dir_col * sin(x);
	cub3d->dir_col = tmp * sin(x) + cub3d->dir_col * cos(x);
	tmp = cub3d->plane_row;
	cub3d->plane_row = cub3d->plane_row * cos(x) - cub3d->plane_col * sin(x);
	cub3d->plane_col = tmp * sin(x) + cub3d->plane_col * cos(x);
}
