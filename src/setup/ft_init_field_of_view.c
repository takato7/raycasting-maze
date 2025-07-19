/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_field_of_view.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:01:52 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/15 15:31:44 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"

int	ft_init_field_of_view(t_cub3d *cub3d)
{
	cub3d->fov.x = cub3d->win_x;
	cub3d->fov.y = cub3d->win_y;
	cub3d->fov.img = mlx_new_image(cub3d->mlx, cub3d->win_x, cub3d->win_y);
	if (!cub3d->fov.img)
		return (ft_error(EMLXNEWIMG, NULL));
	ft_set_img_addr(&cub3d->fov);
	return (1);
}
